#include<regx52.h>
#include<intrins.h>

void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 23;
	j = 205;
	k = 120;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	while(1)
	{
		P2 = 0xFE;     //1111 1110
		Delay500ms();
		P2 = 0xFF
		DElay500ms();
	}
}