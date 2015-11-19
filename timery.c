#include "definicje.h"
#include "timery.h"
#include "rejestry.h"
#include "kostka.h"
#include "waz.h"
#include "jedzenie.h"

void timery_ustaw()
{    
    cli();
    
    // TIMER0 - przyciski
    TCCR0A |= (1 << WGM01);
	OCR0A = 100;
	TCCR0B |= ((1 << CS02)|(1<<CS00));
	TIMSK0 |= (1 << OCIE0A);

    // TIMER1 - krok
    TCCR1B |= (1 << WGM12);
	OCR1A = 2000;
	TCCR1B |= ((1 << CS12));
	TIMSK1 |= (1 << OCIE1A);
	
	// TIMER2 - diody
    TCCR2A |= (1 << WGM21);
	OCR2A = 100;
	TCCR2B |= ((1 << CS21));
	TIMSK2 |= (1 << OCIE2A);
	
    sei();
    
    czyt=0;
    czyp=0;  
}

ISR(TIMER0_COMPA_vect)
{
    if(PIND&(1<<PD0)) czyt|=(1<<0);
    else czyt&=~(1<<0);
    if(PIND&(1<<PD1)) czyt|=(1<<1);
    else czyt&=~(1<<1);
    if(PIND&(1<<PD2)) czyt|=(1<<2);
    else czyt&=~(1<<2);
    if(PIND&(1<<PD3)) czyt|=(1<<3);
    else czyt&=~(1<<3);
    if(PIND&(1<<PD4)) czyt|=(1<<4);
    else czyt&=~(1<<4);
    if(PIND&(1<<PD5)) czyt|=(1<<5);
    else czyt&=~(1<<5);
    
    if( (czyt&(1<<0)) & ~(czyp&(1<<0)) ){ stanp+=1; if(kierunekp!=GORA)  kierunek=DOL;}
    if( (czyt&(1<<1)) & ~(czyp&(1<<1)) ){ stanp-=1; if(kierunekp!=DOL)   kierunek=GORA;}
    if( (czyt&(1<<2)) & ~(czyp&(1<<2)) ){ stanp+=4; if(kierunekp!=LEWO) kierunek=PRAWO;}
    if( (czyt&(1<<3)) & ~(czyp&(1<<3)) ){ stanp+=5; if(kierunekp!=PRZOD) kierunek=TYL;}
    if( (czyt&(1<<4)) & ~(czyp&(1<<4)) ){ stanp+=8; if(kierunekp!=TYL)   kierunek=PRZOD;}
    if( (czyt&(1<<5)) & ~(czyp&(1<<5)) ){ stanp+=3; if(kierunekp!=PRAWO)  kierunek=LEWO;}

    czyp=czyt;
}

ISR(TIMER1_COMPA_vect)
{
    kostka_zeruj();
    kostka_z_jedzenia(krok&0x01);
    kostka_z_weza();
    krok++;
}

ISR(TIMER2_COMPA_vect)
{
    LPORT &= ~LMASKA;
    rejestry_16(kostka.xy[kostka.z]);
    
    LPORT |= (1<<kostka.z);
    
    kostka.z++;
    if(kostka.z>3) kostka.z=0;
}

