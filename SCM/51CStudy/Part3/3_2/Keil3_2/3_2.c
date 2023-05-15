/*
	用16个发光二极管实现除法
*/
#include <reg51.h>
#define uint unsigned int
#define uchar unsigned char
	
sbit data1 = P3^4;
sbit iclk = P3^6;
sbit oclk = P3^5;

uchar i, j, k, m;

void delay()
{
	uint a, b;
	for (a = 0; a < 10; a ++)
		for (b = 0; b < 110; b ++);
}

void xiaoshu(uchar m)
{
	uchar n;
	n = m;
	oclk = 0;
	iclk = 0;
	for (i = 0; i < 8; i ++)
	{
		n <<= 1;
		data1 = CY;
		iclk = 1;
		delay();
		iclk = 0;
	}
	oclk = 1;
	delay();
	oclk = 0;
}

void main()
{
	i = 10;
	j = 6;
	P2 = i / j;
	k = ((i % j) * 10) / j;
	xiaoshu(k);
	while (1);
}