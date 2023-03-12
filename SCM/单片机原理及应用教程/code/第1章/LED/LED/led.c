#include <reg52.h>
#define uint unsigned int
sbit D1 = p1^0;
void delay(uint z);

void main()
{
	while (1)
	{
		D1 = 0;
		delay(500);
		D1 = 1;
		delay(500);
	}
}

void delay(uint z)
{
	uint x, y;
	for (x = z; x > 0; x --)
		for (y = 110; y > 0; y --);
}