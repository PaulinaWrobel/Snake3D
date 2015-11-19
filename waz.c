#include "definicje.h"
#include "waz.h"

void waz_ustaw()
{
    uint8_t i;
    for(i=0;i<64;++i)
    {
        waz[i].z=0;
        waz[i].xy=0x0000;
    }
    
    dlugosc=1;
    kierunek=PRAWO;
    waz[0].z=2;
    waz[0].xy=0x2000;
}

void waz_przesun()
{
    uint8_t i;
    for(i=dlugosc-1;i>0;--i)
    {
        waz[i]=waz[i-1];
    }
    waz_kierunek();
    for(i=4;i<dlugosc;++i)
    {
        if((waz[0].z==waz[i].z)&&(waz[0].xy==waz[i].xy))
        {
            koniec=1;
            krok=0;
        }
    }
}

void waz_kierunek()
{
    switch (kierunek)
    {
        case PRAWO:
        {
            if(waz[0].xy&0x000f)
            {
                koniec=1;
                krok=0;
            }
            else
            {
                waz[0].xy >>= 4;
            }
            break;
        }
        case LEWO:
        {
            if(waz[0].xy&0xf000)
            {
                koniec=1;
                krok=0;
            }
            else
            {
                waz[0].xy <<= 4;
            }
            break;
        }
        case PRZOD:
        {
            if(waz[0].xy&0x1111)
            {
                koniec=1;
                krok=0;
            }
            else
            {
                waz[0].xy >>= 1;
            }
            break;
        }
        case TYL:
        {
            if(waz[0].xy&0x8888)
            {
                koniec=1;
                krok=0;
            }
            else
            {
                waz[0].xy <<= 1;
            }
            break;
        }
        case GORA:
        {
            if(waz[0].z==3)
            {
                koniec=1;
                krok=0;
            }
            else
            {
                waz[0].z += 1;
            }
            break;
        }
        case DOL:
        {
            if(waz[0].z==0)
            {
                koniec=1;
                krok=0;
            }
            else
            {
                waz[0].z -= 1;
            }
            break;
        }
    }
    kierunekp=kierunek;
}

