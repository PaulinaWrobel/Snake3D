#include "definicje.h"
#include "kostka.h"
#include "animacja.h"

void animacja_poczatek()
{
    while(krok<16)
    {
        switch (krok)
        {
            case 0:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
                OCR1A=4000;
                break;
            }
            case 2:
            {
                kostka.xy[0]=0xffff;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
                break;
            }
            case 3:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0xffff;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
                break;
            }
            case 4:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0xffff;
                kostka.xy[3]=0x0000;
                break;
            }
            case 5:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0xffff;
                break;
            }
            case 6:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0xffff;
                kostka.xy[3]=0x0000;
                break;
            }
            case 7:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0xffff;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
                break;
            }
            case 8:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0xcccc;
                kostka.xy[2]=0x3333;
                kostka.xy[3]=0x0000;
                break;
            }
            case 9:
            {
                kostka.xy[0]=0x8888;
                kostka.xy[1]=0x4444;
                kostka.xy[2]=0x2222;
                kostka.xy[3]=0x1111;
                break;
            }
            case 10:
            {
                kostka.xy[0]=0x4444;
                kostka.xy[1]=0x4444;
                kostka.xy[2]=0x2222;
                kostka.xy[3]=0x2222;
                break;
            }
            case 11:
            {
                kostka.xy[0]=0x2222;
                kostka.xy[1]=0x2222;
                kostka.xy[2]=0x2222;
                kostka.xy[3]=0x2222;
                break;
            }
            case 12:
            {
                kostka.xy[0]=0x1111;
                kostka.xy[1]=0x1111;
                kostka.xy[2]=0x1111;
                kostka.xy[3]=0x1111;
                break;
            }
            case 13:
            {
                kostka.xy[0]=0x2222;
                kostka.xy[1]=0x2222;
                kostka.xy[2]=0x2222;
                kostka.xy[3]=0x2222;
                break;
            }
            case 14:
            {
                kostka.xy[0]=0x4444;
                kostka.xy[1]=0x4444;
                kostka.xy[2]=0x4444;
                kostka.xy[3]=0x4444;
                break;
            }
            case 15:
            {
                kostka.xy[0]=0x8888;
                kostka.xy[1]=0x8888;
                kostka.xy[2]=0x8888;
                kostka.xy[3]=0x8888;
                OCR1A=2000;
                break;
            }
            default:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
            }
        }
    }
    krok=0;
}

void animacja_koniec()
{
    while(krok<5)
    {
        switch (krok&0x0001)
        {
            case 0:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
                break;
            }
            case 1:
            {
                kostka.xy[0]=0xffff;
                kostka.xy[1]=0xffff;
                kostka.xy[2]=0xffff;
                kostka.xy[3]=0xffff;
                break;
            }
            default:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
            }
        }
    }
    krok=0;
}

void animacja_wygrana()
{
    while(krok<5)
    {
        switch (krok)
        {
            case 0:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
                OCR1A=10000;
                break;
            }
            case 1:
            {
                kostka.xy[0]=0x8888;
                kostka.xy[1]=0x8000;
                kostka.xy[2]=0x8000;
                kostka.xy[3]=0x8000;
                break;
            }
            case 2:
            {
                kostka.xy[0]=0x4444;
                kostka.xy[1]=0x4004;
                kostka.xy[2]=0x4004;
                kostka.xy[3]=0x4444;
                break;
            }
            case 3:
            {
                kostka.xy[0]=0x2222;
                kostka.xy[1]=0x2000;
                kostka.xy[2]=0x2000;
                kostka.xy[3]=0x2000;
                break;
            }
            case 4:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
                OCR1A=2000;
                break;
            }
            default:
            {
                kostka.xy[0]=0x0000;
                kostka.xy[1]=0x0000;
                kostka.xy[2]=0x0000;
                kostka.xy[3]=0x0000;
            }
        }
    }
    krok=0;
}

