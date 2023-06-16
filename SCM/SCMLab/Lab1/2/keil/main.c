#include <reg51.h>
#include <absacc.h>
#define uchar unsigned char
#define uint unsigned int
	
sbit P0_0 = P0^0;
sbit P0_1 = P0^1;
sbit P0_2 = P0^2;
sbit P0_3 = P0^3;
uchar cnt;

void count()
{
	cnt = 0;
	if (P0_0 == 1) cnt ++;
	if (P0_1 == 1) cnt ++;
	if (P0_2 == 1) cnt ++;
	if (P0_3 == 1) cnt ++;
}

void delay()
{
	uint i, j;
	for (i = 1000; i; i --)
		for (j = 100; j ; j --);
}

void show()
{
	uchar i;
	if (cnt == 1)
	{
		uchar m = 0xfe;
		P1 = m;
		for (i = 1; i < 8; i ++)
		{
			delay();
			m <<= 1;
			m |= 0x01;
			P1 = m;
		}
		delay();
	}
	else if (cnt == 2)
	{
		uchar m = 0x7f;
		P1 = m;
		for (i = 1; i < 8; i ++)
		{
			delay();
			m >>= 1;
			m |= 0x80;
			P1 = m;
		}
		delay();
	}
	else if (cnt == 3)
	{
		P1 = 0xff;
		delay();
		P1 = 0xe7;
		delay();
		P1 = 0xc3;
		delay();
		P1 = 0x81;
		delay();
		P1 = 0x00;
		delay();
	}
	else
	{
		P1 = 0xff;
		delay();
		P1 = 0x7e;
		delay();
		P1 = 0x3c;
		delay();
		P1 = 0x18;
		delay();
		P1 = 0x00;
		delay();
	}
}

void main()
{
	while (1)
	{
		count();
		show();
	}
}