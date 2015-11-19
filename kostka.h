#ifndef KOSTKA_H_
#define KOSTKA_H_

struct skostka
{
    uint16_t xy[4];
    uint8_t z;
};
volatile struct skostka kostka;

void kostka_zeruj();
void kostka_z_weza();
void kostka_z_jedzenia(uint8_t x);

#endif

