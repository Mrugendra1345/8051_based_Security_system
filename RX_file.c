#include <reg51.h>

#define data_line P2
sbit RS= P1^0;
sbit RW = P1^1;
sbit EN = P1^2;

void lcd_init(void );
void lcd_data(unsigned char);
void lcd_cmd(unsigned char);
void lcd_string(unsigned char *);
void delay(int);
void UART_init(void);
unsigned char receive (void);


void main()
{
	char b[4];
	int i;
	lcd_init();
	UART_init();
	
	
	
	while(1){
		i=0;
		lcd_string("Enter Password:");
  lcd_cmd(0xc0);
		while(i<4)
		{
		b[i]= receive();
	  lcd_data(b[i]);
		i++;
		}
				
		if((b[0]=='1') && (b[1]=='2') && (b[2]=='3') && (b[3]=='4'))
	 {
		 lcd_cmd(0x01);
		 lcd_cmd(0x80);
		 lcd_string("Access Granted  ");
		 delay(500);
	 }
	 else
	 {
		 lcd_cmd(0x01);
		 lcd_cmd(0x80);
		 lcd_string("Access Denied  ");
		 delay(500);
	 }
	 lcd_cmd(0x01);
	
	}
	}

	void lcd_init(void)
	{
		lcd_cmd(0x38);
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_cmd(0x0F);
	}
	
	void lcd_cmd( unsigned char c)
	{
		data_line = c;
		
		RS=0;
		RW=0;
		EN=1;
		delay(50);
		EN=0;
	}
	
	void lcd_data( unsigned char c)
	{
		data_line = c ;
		
		RS=1;
		RW=0;
		EN=1;
		delay(50);
		EN=0;
	}
 
	void lcd_string(unsigned char *p)
	{
		while(*p!='\0')
		{
			lcd_data(*p);
			p++;
		}
	}
	
	
		void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<t;j++)
		{
		}
	}
}

void UART_init(void)
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1= 0xFD;
	TR1=1;
}

unsigned char receive (void)
{
	while(RI==0);
	RI=0;
	return SBUF;
}
