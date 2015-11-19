#ifndef DEFINICJE_H_
#define DEFINICJE_H_

#include <avr/common.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// rejestry 74HC595
#define RPORT PORTB
#define RDDR DDRB
#define RPIN PINB
#define RSS PB2
#define RMOSI PB3
#define RSCK PB5

// diody LED
#define LPORT PORTC
#define LDDR DDRC
#define LMASKA ((1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3))

volatile uint8_t koniec;
volatile uint8_t krok;

#endif

