#include<LPC17xx.h>
unsigned int dig_count=0;
unsigned int seven_seg[4]={0x06,0x5B,0x4F,0x66};  
//unsigned int dig_value[4]={4,3,2,1};
unsigned int dig_select[4]={3<<23,2<<23,1<<23,0<<23};

void delay()
{
	unsigned int i;
	for(i=0;i<500000;i++);
}

void display()
{
	LPC_GPIO1->FIOPIN=dig_select[dig_count];
	LPC_GPIO0->FIOPIN=seven_seg[dig_count]<<4;
}

int main()
{
	LPC_GPIO0->FIODIR|=0xFF<<4;
	LPC_GPIO1->FIODIR|=15<<23;
	while(1)
	{
		delay();
		display();
		dig_count+=1;
		if(dig_count==0x04)
			dig_count=0x00;
	}
}