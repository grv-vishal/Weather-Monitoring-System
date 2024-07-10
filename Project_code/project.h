
//DHT11 function Declarion
void delay20ms(void);
void delay30us(void);		
void Request(void);
void Response(void);			
int Receive_data(void);
void dhtToDisp(void);


//LDR function Declaration
void adcConv(void);
void convertToDisplay(void);


//LCD Display function Declaration
void delay(unsigned int i);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);
void lcd_init(void);
void lcd_str(unsigned char *str);
void delay_ms(unsigned int delay);