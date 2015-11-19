#include "definicje.h"
#include "timery.h"
#include "rejestry.h"
#include "kostka.h"
#include "waz.h"
#include "animacja.h"
#include "jedzenie.h"

#define F_CPU 16000000UL

int main()
{
    // ustawienie portow 
    LDDR |= LMASKA;
    LPORT &= ~LMASKA;
    DDRD&=~((1<<PD0)|(1<<PD1)|(1<<PD2)|(1<<PD3)|(1<<PD4)|(1<<PD5));
    
    // inicjalizacja rejestrow przesuwnych i timerow
    rejestry_ustaw();
    timery_ustaw();
    
    // inicjalizacja kostki
    kostka_zeruj();

	// inicjalizacja zmiennych
    stanp=0;
    koniec=0;    
    krok=0;
    
	// animacje poczatkowe
    animacja_poczatek();
	animacja_koniec();
	
	// przygotowanie weza i jedzenia
    kostka_zeruj();
    waz_ustaw();
    jedzenie_ustaw();
    kostka_z_weza();
    kostka_z_jedzenia(1);
    
    while(1)
    {
        if(!koniec) // poruszanie weza dopoki nie umrze
        {   
            if(krok==4)
            {
                krok=0;
                waz_przesun();
                jedzenie_jedzenia();   
            }
        }
        else // zastapienie martwego weza zywym i przygotowanie nowej gry
        {
            animacja_koniec(krok); // animacja symbolizujaca smierc weza
			
            if(dlugosc==64) // gdy waz zajmuja cala kostke, wykonywana jest specjalna animacja
            {
                animacja_wygrana(krok);
            }
			
			// przygotowanie weza i jedzenia
			OCR1A=2000;
			krok=0;
			koniec=0;
			waz_ustaw();
			jedzenie_ustal();
			kostka_zeruj();
			kostka_z_weza();
			kostka_z_jedzenia(1);
        }
    }
}

