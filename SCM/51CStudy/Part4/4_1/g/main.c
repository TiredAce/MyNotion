/*
	实现P2口8位灯交替闪烁，间隔50ms
*/
#include <reg51.h>

void set()
{
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
}

void main()
{
	TMOD = 0x01;
	set();
	P2 = 0xff;
	TR0 = 1;
	while (1)
	{
		while (TF0 == 0);
		TF0 = 0;
		P2 = ~P2;
		set();
	}
}