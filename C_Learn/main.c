#include "stm32f10x.h"

#define RAM_ADDRESS 0x20000000

int u32CheckingVolatile = 0U;
int Dem = 0U;

int main(void)
{
	while(1)
	{
		u32CheckingVolatile = *(int*)RAM_ADDRESS;
		Dem++;
		if(u32CheckingVolatile != 0U)
		{
			break;
		}
	}
	Dem = 100;
	
	return 0;
}