#include<regx52.h>
#include<intrins.h>
void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while (xms)
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
	while(1)
	{
		 if(P3_1 == 0)
		 {
			Delay1ms(20);          //an xia shi xiao dou
			while(P3_1 == 0);	   //yi zhi an zhe, yi zhi zai xun huan nei
			Delay1ms(20);          //song kai xiao dou
			
			P2_0 = ~P2_0;          //2_0 dian ping qu fan
		 }
	}
}

