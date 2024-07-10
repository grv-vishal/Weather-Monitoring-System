#include<reg51.h>
#include"project.h"

sbit DHT11=P3^4;        
int I_RH,D_RH,I_Temp,D_Temp,CheckSum;

void delay20ms()	
{
	TMOD = 0x01;
	TH0 = 0xB8;		
	TL0 = 0x0C;	
	TR0 = 1;	
	while(TF0 == 0);
	TR0 = 0;	
	TF0 = 0;	
}

void delay30us()	
{
	TMOD = 0x01;	
	TH0 = 0xFF;	
	TL0 = 0xF1;	
	TR0 = 1;		
	while(TF0 == 0);
	TR0 = 0;		
	TF0 = 0;	
}

void Request()		
{
	DHT11 = 0;		
	delay20ms();	
	DHT11 = 1;		
}

void Response()			
{
	while(DHT11==1);
	while(DHT11==0);
	while(DHT11==1);
}

int Receive_data()	
{
	int q,c=0;	
	for (q=0; q<8; q++)
	{
		while(DHT11==0);
		delay30us();
		if(DHT11 == 1)	
		c = (c<<1)|(0x01);
		else	
		c = (c<<1);
		while(DHT11==1);
	}
	return c;
}


void dhtToDisp()
{
	Request();
	Response();


	I_RH=Receive_data();
	D_RH=Receive_data();	
	I_Temp=Receive_data();	
	D_Temp=Receive_data();	
	CheckSum=Receive_data();


	if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
		{
		}
		
	else
		{  //temperature
		   lcd_cmd(0xc1);
		   lcd_data(I_Temp/10+'0');
		   lcd_data(I_Temp%10+'0');
		   lcd_data(0xDF);
		   lcd_data('C');
		   

		   //Humidity
		   lcd_cmd(0xc7);
		   lcd_data(I_RH/10+0x30);
		   lcd_data(I_RH%10+0x30);
		   lcd_data(0x25); 
			
		}		
	delay(100);
}
