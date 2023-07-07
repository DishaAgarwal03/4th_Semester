//stepper ex
//clockwise direction when SW2 is high and anticlockwise direction when SW2 is low. 
#include <LPC17xx.h>
long int var1,var2;
int i=0,j=0,k=0;

void clock_wise(void)
{
	var1 = 0x00000008; 
	 for(i=0;i<=3;i++) 
	{
		var1 = var1<<1; 
		 LPC_GPIO0->FIOPIN = var1;
		 
		 for(k=0;k<3000;k++); 
	}
}

void anti_clock_wise(void)
{
	var1 = 0x00000100; 
	 for(i=0;i<=3;i++)
	 {
		 var1 = var1>>1; 
		 LPC_GPIO0->FIOPIN = var1;
		 
		 for(k=0;k<3000;k++); 
	 }

}

int main(void)
{
	//LPC_PINCON->PINSEL0 = 0xFFFF00FF;
	LPC_GPIO0->FIODIR = 0x000000F0;
	while(1)
	{
		if((LPC_GPIO2->FIOPIN & 1<<12))
		{	
			for(j=0;j<50;j++) 
				clock_wise();
			for(k=0;k<10000;k++);
		}
		else
		{
			for(j=0;j<50;j++) 
				anti_clock_wise();
			for(k=0;k<10000;k++);
		}
	} 
} 


