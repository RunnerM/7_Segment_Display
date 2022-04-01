/*
 * seven_segment_driver.c
 *
 * Created: 2022-04-01 9:07:31 AM
 *  Author: pente
 */ 


#include "seven_segment_driver.h"

uint16_t map_value(uint16_t value);

void init_display(){
	//TODO: set up timer
	//
	
}
void printint_4u(uint16_t value){
	
}
void printint_4s(uint16_t value){
	
}

uint16_t map_value(uint16_t value){
	if (!(value > -1 && value < 10))
	{
		return 0;
	}
	switch(value){
		case 0:{
			return 0xFF;
			break;
		}
		case 1:{
			return 0x9F;
			break;
		}
		case 2:{
			return 0x25;
			break;
		}
		case 3:{
			return 0xD;
			break;
		}
		case 4:{
			return 0x169;
			break;
		}
		case 5:{
			return 0x49;
			break;
		}
		case 6:{
			return 0x65;
			break;
		}
		case 7:{
			return 0x1F;
			break;
		}
		case 8:{
			return 0x1;
			break;
		}
		case 9:{
			return 0x9;
			break;
		}
	}
}
