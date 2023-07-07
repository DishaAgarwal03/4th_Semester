//adc ex
#include<LPC17xx.h>
#include "WEEK8/q3_helper.c"
#include<math.h>
unsigned char str[]={"0123456789"};
unsigned long x, t1=0, t2=0;
unsigned int result;
unsigned char msg1[10]={"ADC value"};
unsigned char msg2[10];

void ADC_IRQHandler()
{
	x=LPC_ADC->ADSTAT & (3<<4);
	if(x == (x & 1 << 4)) {
		t1 = (LPC_ADC->ADDR4&(0xFFF<<4)>>4);
	} else {
		t2 = (LPC_ADC->ADDR5&(0xFFF<<4)>>4);
	}
	t1=ceil((t1*3.3)/4096);
	t2=ceil((t2*3.3)/4096);
	result=abs(t1-t2);
	msg2[0]=str[result];
	msg2[1]='\0';
	lcd_comdata(0xc0,0);
	delay_lcd(100000);
	lcd_puts(&msg2[0]);
}

int main(void)
{
	lcd_init();
	LPC_SC->PCONP |= 1<<12;
	LPC_PINCON->PINSEL3 = 0XF<<28;
	LPC_ADC->ADCR = (1<<4 | 1<<5 | 1<<16 | 1<<21);
	LPC_ADC->ADINTEN = 1<<4|1<<5;
	lcd_comdata(0x80,0);
	delay_lcd(30000);
	lcd_puts(&msg1[0]);
	NVIC_EnableIRQ(ADC_IRQn);
	while(1);
}
	
