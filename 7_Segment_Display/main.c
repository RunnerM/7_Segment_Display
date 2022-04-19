/*
 * 7_Segment_Display.c
 *
 * Created: 2022-04-01 8:29:40 AM
 * Author : pente
 */ 

#include "7_segment_driver/seven_segment_driver.h"
#include "drivers/TMP36GRTZ.h"

void thermometer_callback(float result);
int i,j ;


int main(void)
{
	init_termometer(thermometer_callback);
	init_display();
	printint_4u(0000);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

void thermometer_callback(float result){
	printint_4u(result);
}

