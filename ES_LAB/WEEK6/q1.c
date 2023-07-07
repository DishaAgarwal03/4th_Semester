#include<LPC17xx.h>
int main(void)
{
	unsigned int j;
	unsigned long LED;
	
	LPC_PINCON->PINSEL0 &= 0XFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	
	//LPC_PINCON->PINSEL4 &= 0XFCFFFFFF;
	//LPC_GPIO2->FIODIR &= 0XFFFFEFFF;
	
	while(1)
	{
		//if(!(LPC_GPIO2->FIOPIN & 1<<12)){
			for(LED=0;LED<=255;LED++)
			{
				LPC_GPIO0->FIOPIN=LED<<4;
				for(j=0;j<600000;j++);
			}
		//}
	}
}
