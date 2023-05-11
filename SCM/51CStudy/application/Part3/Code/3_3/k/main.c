#include <reg51.h>
#define uint unsigned int
#define uchar unsigned char

void delay()
{
	uint i, j;
	for (i = 0; i < 1000; i ++)
		for (j = 0; j < 110; j ++);
}

int main()
{
	uchar m, n;
	while (1)
	{
		for (m = 0; m < 10; m ++)
		{
			P2 = m;
			delay();
		}
		for (n = 10; n > 0; n --)
		{
			P2 = n;
			delay();
		}
	}
}