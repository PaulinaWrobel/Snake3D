#include "definicje.h"
#include "rejestry.h"

void rejestry_ustaw()
{
	RDDR |= ((1<<RSS)|(1<<RSCK)|(1<<RMOSI));
    	SPSR |= (1<<SPI2X);
	SPCR |= (1<<SPE)|(1<<MSTR);
}

void rejestry_wyslij(uint8_t dane)
{
	SPDR = dane;
	while(!(SPSR&(1<<SPIF)));
	SPSR |= (1<<SPIF);
}

void rejestry_16(uint16_t dane)
{
	RPORT &= ~(1<<RSS);
	rejestry_wyslij(dane & 0x00ff);
	rejestry_wyslij((dane & 0xff00) >> 8);
	RPORT |= (1<<RSS);
}

