#include "definicje.h"
#include "kostka.h"
#include "waz.h"
#include "jedzenie.h"

void kostka_zeruj()
{    
    kostka.z=0;
    int i;
    for(i=0; i<4; ++i)
    {
        kostka.xy[i]=0x0000;
    }
}

void kostka_z_weza()
{
    int i;
    for(i=0;i<dlugosc;++i)
    {
        kostka.xy[waz[i].z] |= waz[i].xy;
    }
}

void kostka_z_jedzenia(uint8_t x)
{
    if(x) kostka.xy[jedzenie.z] |= jedzenie.xy;
    else kostka.xy[jedzenie.z] &= ~jedzenie.xy;
}

