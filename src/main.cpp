/*
 * ATmega2560_DC_MOTOR.cpp
 *
 * Created: 12/18/2016 1:57:45 PM
 * Author : fairenough
 */ 

#include "RCCar.h"

RCCar car;

int main(void)
{
	DDRA = 0x00;
	car.setSpeed(77);
	car.run(CAR_STOP);
	
    while (1) 
    {
		if (PINA & (1 << PINA0))
		{
			car.run(CAR_FORWARD);
			
		}
		else if (PINA & (1 << PINA1))
		{
			car.run(CAR_BACKWARD);
		
		}
		else if (PINA & (1 << PINA2))
		{
			car.run(CAR_RIGHT);
		
		}
		else if (PINA & (1 << PINA3))
		{
			car.run(CAR_LEFT);
		
		}
		else if (PINA & (1 << PINA4))
		{
			car.run(CAR_STOP);
		}
    }
}

