#include<reg51.h>
#include"project.h"

#define ldata P0

sbit rs=P2^0;
sbit en=P2^1;

void lcd_init()
{
    lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}

void delay(unsigned int i)
{
    unsigned int j;
	for(j=0;j<i;j++);{
	   unsigned int k;
	   for(k=0;k<i;k++);
	}
}

void lcd_cmd(unsigned char a)
{
    rs=0;//cmd 
	ldata=a;
	en=1;
	delay(5);
	en=0;
	delay(5);
}
void lcd_data(unsigned char b)
{
    rs=1;//data 
	ldata=b;
	en=1;
	delay(5);
	en=0;
	delay(5);
}
void lcd_str(unsigned char *str)
{
   while(*str)
   {
	lcd_data(*str++);
   }
}

