#ifndef JEDZENIE_H_
#define JEDZENIE_H_

struct sjedzenie
{
    uint16_t xy;
    uint8_t z;
};
volatile struct sjedzenie jedzenie;
volatile uint32_t stanp;

void jedzenie_ustaw();
void jedzenie_losuj();
uint8_t jedzenie_blad();
void jedzenie_jedzenia();
void jedzenie_ustal();

#endif

