#include "definicje.h"
#include "jedzenie.h"
#include "waz.h"

void jedzenie_ustaw()
{
    stanp=0xf5f7f0fa;
    jedzenie.z=0;
    jedzenie.xy=0x0000;
    jedzenie_ustal();
}

void jedzenie_losuj()
{  
    uint8_t stan;

    stanp=(22695477*stanp+1);
    stan=(stanp)&0x3f;
    jedzenie.z=stan>>4;
    jedzenie.xy=1<<(stan&0x0f);
}

uint8_t jedzenie_blad()
{
    uint8_t czy;
    czy=0;
    if(!jedzenie.xy) czy=1;
    if(jedzenie.z>3) czy=1;
    if(jedzenie.xy>0xffff)  czy=1;
    uint8_t i;
    for(i=0;i<dlugosc;++i)
    {
        if((jedzenie.z==waz[i].z)&&(jedzenie.xy==waz[i].xy)) czy=1;
    }
    
    return czy;
}

void jedzenie_ustal()
{   
    do
	{
        jedzenie_losuj();
    }
	while(jedzenie_blad());
}

void jedzenie_jedzenia()
{
    if((waz[0].z==jedzenie.z)&&(waz[0].xy==jedzenie.xy))
    {
        dlugosc++;
        if(dlugosc<64) jedzenie_ustal();
        if(OCR1A>1000) OCR1A -= 20;
    }
}

