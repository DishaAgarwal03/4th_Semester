#include<LPC17xx.h>

void main()
{
	unsigned long LED;
	unsigned int j,i;
	//LPC_PIONCON->PINSEL0 &= 0xFF0000FF;
	//LPC_PINCON->PINSEL4 &=0xFCFFFFFF;
	LPC_GPIO0->FIODIR |= 255<<4;
	LPC_GPIO2->FIODIR &= 0XFFFFEFFF;
	while(1)
	{
		if(!(LPC_GPIO2->FIOPIN & 1<<12))
		{
			LED=0X1;
			for(j=0;j<8;j++)
			{
				LPC_GPIO0->FIOPIN = LED<<4;
				LED=LED<<1;
				for(i=0;i<500000;i++);
			}
		}
		//else
		//	LPC_GPIO0->FIOPIN=0;
	}	
}