//if writing unsigned int arr[] then cannot give
//condition as >=0 since it will always be true and kit will not give correct output
//also, cannot compare unsigned int with -1.
//therefore using int.

//switch always 7th pin of CN_ i.e 2.0 of CND, 2.12 of CNB etc.
//we're using SW2

//cannot use 2.12 since that is already connected for LED
#include<LPC17xx.h>
unsigned int i,j;
unsigned int hex[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
int arr[4]={0,0,0,0};
void downcounter();
void delay()
{
	for(j=0;j<50000;j++);
}

void upcounter()
{
    for(arr[3]=0;arr[3]<16;arr[3]++)
			for(arr[2]=0;arr[2]<16;arr[2]++)
				for(arr[1]=0;arr[1]<16;arr[1]++)
					for(arr[0]=0;arr[0]<16;arr[0]++)
						{
							if(!(LPC_GPIO2->FIOPIN & 1))  //switch not pressed: upcounter
                                downcounter();
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

void downcounter()
{
    for(arr[3]=15;arr[3]>=0;arr[3]--)
			for(arr[2]=15;arr[2]>=0;arr[2]--)
				for(arr[1]=15;arr[1]>=0;arr[1]--)
					for(arr[0]=15;arr[0]>=0;arr[0]--)
						{
						    if(LPC_GPIO2->FIOPIN & 1)  //switch not pressed: upcounter
                                upcounter();
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


int main()
{
	LPC_GPIO0->FIODIR|=0xFF0;   //0.4-0.11
	LPC_GPIO1->FIODIR|=0xF<<23; //1.23-1.26
	LPC_GPIO2->FIODIR&=0xFFFFFFFE; //2.0
	while(1)
    {
        if(LPC_GPIO2->FIOPIN & 1)  //switch not pressed: upcounter
            upcounter();
        else   //switch pressed: downcounter
            downcounter();
    }
}
