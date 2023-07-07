//switch released(1): upcounter. switch pressed(0): downcounter
#include<LPC17xx.h>
int main()
{
	unsigned int LED;
	unsigned int j;
	
	LPC_PINCON->PINSEL0 &= 0XFF0000FF;
	LPC_GPIO0->FIODIR |= 0XFF<<4;
	
	LPC_PINCON->PINSEL4 &= 0XFCFFFFFF;
	LPC_GPIO2->FIODIR &= 0XFFFFEFFF;
	
	while(1)
	{
		if(LPC_GPIO2->FIOPIN & 1<<12)
		{
			for(LED=0;LED<=255;LED++)
			{
				LPC_GPIO0->FIOPIN=LED<<4;
				for(j=0;j<800000;j++);
				//if(!(LPC_GPIO2->FIOPIN & 1<<12))
				//	break;
			}
		}
		else
		{
			for(LED=255;LED>=0;LED--)
			{
				LPC_GPIO0->FIOPIN=LED<<4;
				for(j=0;j<800000;j++);
			 // if(LPC_GPIO2->FIOPIN & 1<<12)
			//      	break;
			}
		}
	}
}