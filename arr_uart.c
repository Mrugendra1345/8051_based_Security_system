#include<reg51.h>

sbit r0= P2^0;
sbit r1=P2^1;
sbit r2= P2^2;
sbit r3=P2^3;
sbit c0= P2^4;
sbit c1=P2^5;
sbit c2= P2^6;
sbit c3=P2^7;


void trans(unsigned char );
void UART_init(void);
void delay(int);


void main()
{
unsigned char pass;
int i=0;
UART_init();

	while(1)
	{
		
		
		r0=0;
		r1=r2=r3=1;
		if(c0==0)
		{
			   // 7
		  pass='7';
			
		}
		
		if(c1==0)
		{
			   // 8
			  pass='8';
			
		}
		
		if(c2==0)
		{
			   // 9
			  pass='9';
			
		}
		
		r1=0;
		r0=r2=r3=1;
		if(c0==0)
		{
			   // 4
			  pass='4';
			
		}
		
		if(c1==0)
		{
			  // 5
			  pass='5';
			
		}
		
		if(c2==0)
		{
			   // 6
			  pass='6';
			
		}
		
		r2=0;
		r0=r1=r3=1;
		if(c0==0)
		{
			   // 1
			  pass='1';
			
		}
		
		if(c1==0)
		{
			   // 2
			  pass='2';
			
		}
		
		if(c2==0)
		{
			 //3
			  pass='3';
			
		}
		
		r3=0;
		r0=r1=r2=1;
		if(c1==0)
		{
			
			  pass='0';
			  
		}
		
		if(pass!=' ')
		{
			trans(pass);
		  delay(340);
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

void trans(unsigned char x)
{
	SBUF = x;    // serial buffer register
	while(TI==0);  // TI transmmition interupt (0 not compelet)
	TI=0;
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