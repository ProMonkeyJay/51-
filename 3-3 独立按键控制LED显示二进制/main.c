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

void main()
{
	unsigned char LEDNum = 0;
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay1ms(20);
			while (P3_1 == 0);
			Delay1ms(20);
			
			//P2++;
			LEDNum++;
			P2 = ~LEDNum;
		}
		
	}
}