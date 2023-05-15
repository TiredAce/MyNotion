#include <reg51.h>

sbit led = P2^0;
unsigned char cnt = 0;

void set()
{
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
}

void main()
{
	EA = 1;
	ET0 = 1;
	TMOD = 0x01;
	set();
	TR0 = 1;
	while (1);
}

void time0() interrupt 1
{
	cnt ++;
	if (cnt == 20)
	{
		cnt = 0;
		led = ~led;
	}
	set();
}