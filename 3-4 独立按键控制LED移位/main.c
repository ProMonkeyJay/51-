#include<regx52.h>
#include<intrins.h>

void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{
		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

unsigned char LEDNums = 0;

void main()
{
	P2 = ~0x01;
	while(1)
	{
		if (P3_0 == 0)
		{
			Delay1ms(20);
			while(P3_0 == 0);
			Delay1ms(20);
			 
			LEDNums++;
			LEDNums = LEDNums % 8;
			 
			P2 = ~(0x01<<LEDNums);
		}
		 
		if (P3_1 == 0)
		{
			Delay1ms(20);
			while(P3_1 == 0);
			Delay1ms(20);
			 
			 
			if (LEDNums == 0)
			{
				LEDNums = 7;				
			}
			else
			{
				LEDNums--;
			}				
			P2 = ~(0x01<<LEDNums);
		}
	}
}
