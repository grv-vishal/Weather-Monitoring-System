#include<reg51.h>
#include"project.h"

sbit rd=P3^5;
sbit wr=P3^6;
sbit intr=P3^7;
unsigned int adc;

void adcConv()
{	   
    rd=1;
	wr=0;
	delay(100);
	wr=1;
    while(intr==1);
	delay(100);
	rd=0;
	adc=P1;
	lcd_cmd(0xcc);
	convertToDisplay();
	intr=1;
}

void convertToDisplay(void) 
{
        unsigned int t;
        t = (adc*100/249); 
		
		if(t/100!=0)
		  lcd_data(t / 100 + '0');
		if(t/100==0 && (t / 10) % 10 ==0)
		{}
		else
		   lcd_data((t / 10) % 10 + '0');

		lcd_data(t % 10 + '0');
		lcd_data(0x25);
        
}

