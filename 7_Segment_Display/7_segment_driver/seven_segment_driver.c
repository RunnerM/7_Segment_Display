/*
 * seven_segment_driver.c
 *
 * Created: 2022-04-01 9:07:31 AM
 *  Author: pente
 */ 


#include "seven_segment_driver.h"

uint16_t currentValue;
int DigitCounter;

uint8_t first_digit = 0b11111111;
uint8_t second_digit = 0b11111111;
uint8_t third_digit = 0b11111111;
uint8_t fourth_digit = 0b11111111;
uint8_t numbers[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	
uint8_t i =0;


void init_display(){
	cli();
	OCR4A = 312; // 5KHz 
	TCCR4B |= _BV(WGM42);// Setting the timer to CTC mode.
	TCCR4B |= _BV(CS41);// Prescaler 8
	TCCR4A |= _BV(COM4A0);//Output compare match
	TIMSK4 |= _BV(OCIE4A);//Enabling the mask of the timer.
	//Set Up SPI 
	DDRB |= 1 << 0| 1 << 1 | 1 << 2;
	DDRF |=  1 << 0| 1 << 1 | 1 << 2 | 1 << 3;
	
	//data order, leading edge, 
	SPCR &= ~(1 << DORD | 1 << CPHA);
	// Master and enable, polarity rising edge.
	SPCR |= 1 << MSTR | 1 << SPE | 1 << CPOL | 1 << SPIE | 1 << DORD;
	//SPI speed CLK/2
	SPCR &= ~(1 << SPR1 | 1 << SPR0);
	//SPSR |= 1 << SPI2X;

	PORTB &= ~(1 << PB0);
	PORTF |= 1 << 0| 1 << 1 | 1 << 2 | 1 << 3;
	sei();
}
void printint_4u(uint16_t value){
	cli();
	first_digit = numbers[value/1000];
	second_digit = numbers[(value%1000/100)];
	third_digit = numbers[(value%100/10)];
	fourth_digit = numbers[(value%10/1)];
	sei();
}

ISR(SPI_STC_vect){
	PORTB |= 1 << PB0;//store pulse.
	PORTB &= ~(1 << PB0);
	PORTF &=  ~(1 << DigitCounter);
	DigitCounter++;
	if (DigitCounter < 4)
	{
		switch (DigitCounter)
		{
			case 1:{
				SPDR = second_digit;
				break;
			}
			case 2:{
				SPDR = third_digit;
				break;
			}
			case 3:{
				SPDR = fourth_digit;
				break;
			}
		}
	}
	PORTF |=  1 << (DigitCounter-1); // pulse
}

ISR(TIMER4_COMPA_vect){
	DigitCounter=0;
	SPDR = first_digit;
}