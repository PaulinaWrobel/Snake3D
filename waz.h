#ifndef WAZ_H_
#define WAZ_H_

#define LEWO 0
#define PRAWO 1
#define PRZOD 2
#define TYL 3
#define GORA 4
#define DOL 5

struct swaz
{
    uint16_t xy;
    uint8_t z;
};
volatile struct swaz waz[64];
volatile uint8_t dlugosc;
volatile uint8_t kierunek;
volatile uint8_t kierunekp;

void waz_ustaw();
void waz_przesun();
void waz_kierunek();

#endif

