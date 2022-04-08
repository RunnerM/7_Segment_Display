/*
 * seven_segment_driver.c
 *
 * Created: 2022-04-01 9:07:31 AM
 *  Author: pente
 */ 


#include "seven_segment_driver.h"

uint16_t currentValue;
int DigitCounter;
int Digits [4];
int DecDigits [4];


void init_display(){
	
	//Set Up Timer (30-60HZ)
	
	//Set Up SPI 
	DDRB |= 1 << 0| 1 << 1 | 1 << 2;
	DDRF |=  1 << 0| 1 << 1 | 1 << 2 | 1 << 3;
	
	SPCR &= ~(0 << DORD | 0 << CPHA | 0 << CPOL);
	SPCR |= 1 << MSTR;
	//SPI speed
	SPCR &= ~(0 << SPR1 | 0 << SPR0);
	SPSR |= 1 << SPI2X;

	PORTB |= 1 << PB0;
	
}
void printint_4u(uint16_t value){
	currentValue = value;
	for (int i = 0; i<=4 ; i++)
	{
		switch(value % 10){
			case 0:{
				Digits[i]=ZERO;
			}
			case 1:{
				Digits[i]=ONE;
			}
			case 2:{
				Digits[i]=TWO;
			}
			case 3:{
				Digits[i]=THREE;
			}
			case 4:{
				Digits[i]=FOUR;
			}
			case 5:{
				Digits[i]=FIVE;
			}
			case 6:{
				Digits[i]=SIX;
			}
			case 7:{
				Digits[i]=SEVEN;
			}
			case 8:{
				Digits[i]=EIGHT;
			}
			case 9:{
				Digits[i]=NINE;
			}
		}
	 	value /= 10;
	}
	
}
void printint_4s(uint16_t value){
	
}

ISR(SPI_STC_vect){
	//save shift register value here..
	PORTF |=  1 << DigitCounter;
	if (DigitCounter== 3)
	{
		DigitCounter=0;
	}else{
		DigitCounter++;
		SPDR = Digits[DigitCounter];
	}
}

ISR(TIMER0_COMPA_vect){
	
}


