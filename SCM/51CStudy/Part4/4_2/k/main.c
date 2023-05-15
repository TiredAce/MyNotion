#include <reg51.h>

sbit led = P2^0;

void set()
{
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
}

void main()
{
	TMOD = 0x01;
	set();
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	while (1);
}

void Timer0() interrupt 1
{
	led = ~led;
	set();
}