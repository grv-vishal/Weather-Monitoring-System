#include<reg51.h>												
#include"project.h"

void main()
{
    lcd_init();
	lcd_str("     WELCOME TO  ");
	lcd_cmd(0xc0);	   //2nd line
	lcd_str("  OUR PROJECT   ");
	
	delay(500000);
	lcd_cmd(0x01);	//clear
	lcd_cmd(0x80);	 //1st line
    lcd_str("  WEATHER  STATION");
	lcd_cmd(0xc0);		   //2nd line
	lcd_str("    REPORTING   ");
	delay(500000);
	lcd_cmd(0x01);	  //clear
	lcd_cmd(0x80);	   //1st line
	lcd_str("    T     H   LDR ");
	lcd_cmd(0xc0);
	
	while(1)
   {
	
	//Temperature and Humidity
	dhtToDisp();

	//Light
	adcConv();
    
   }
}