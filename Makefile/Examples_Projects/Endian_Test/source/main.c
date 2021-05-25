//#include <stdio.h>
#include "GPIO.h"

uint32_t Freg_Blink;
uint32_t MD_Value = 1000;			/* default frequency */
const uint32_t BIG_VALUE = 2000;	/* frequency with Big endian */	
const uint32_t LIT_VALUE = 300;		/* frequency with Little endian */

int main()
{	
	Clock_Init();
	GPIO_Init();
	
	//printf("Check Endianness\r\n");
	
	PA->OUT |= (1 << LED_GREEN);	
	Freg_Blink = MD_Value;
	
	while(1)
	{
		if ((PC->IN & (1 << 13)) == 0)
		{
			while((PC->IN & (1 << 13)) == 0);
			//printf("result:\n");
			int check = Check_Endian();
			if (check == 0)		//big endian
				Freg_Blink = BIG_VALUE;
			else		// little endian
				Freg_Blink = LIT_VALUE;
		}
		//printf("abc\n");
		PA->OUT ^= (1 << LED_GREEN);
		myDelay(Freg_Blink);
	}
}
