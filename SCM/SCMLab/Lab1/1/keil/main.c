#include <reg51.h>
#define uchar unsigned char 
#define uint unsigned int
	
void delay()
{
	uint i, j;
	for (i = 1000; i ; i --)
		for (j = 100; j; j --);
}

void main()
{
	uchar m = 0xfe;
	while (1)
	{
		P1 = m;
		delay();
		m <<= 1;
		m |= 0x01;
		if (m == 0xff) m = 0xfe;
	}
}