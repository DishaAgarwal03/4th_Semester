#include<LPC17xx.h>
unsigned int i,j;
unsigned int hex[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};  
int arr[4]={0,0,0,0};

void delay()
{
	for(j=0;j<100000;j++);
}

int main()
{
	LPC_GPIO0->FIODIR|=0xFF0;   //0.4-0.11
	LPC_GPIO1->FIODIR|=0xF<<23; //1.23-1.26
	while(1)
	{
		for(arr[3]=9;arr[3]>=0;arr[3]--)
			for(arr[2]=9;arr[2]>=0;arr[2]--)
				for(arr[1]=9;arr[1]>=0;arr[1]--)
					for(arr[0]=9;arr[0]>=0;arr[0]--)
						{
							for(i=0;i<4;i++)
							{
								LPC_GPIO1->FIOPIN=i<<23;
								LPC_GPIO0->FIOPIN=hex[arr[i]]<<4;
								delay();
							}
							delay();
							LPC_GPIO0->FIOCLR|=0x00000FF0;
						}
	}
}