/*
	�õ�Ƭ��ʵ�ֳ˷�78*18��ͨ��P2�ڷ�ʱ����ʾ��8��8λ
*/
#include <reg51.h>
#define uint unsigned int
#define uchar unsigned char
	
void delay()
{
	uint m, n;
	for (m = 1000; m > 0; m --)
		for (n = 110; n > 0; n --);
}

void main()
{
	uint ans;
	uchar i, j;
	i = 78;
	j = 18;
	ans = i * j;
	while (1)
	{
		P2 = ans / 256;
		delay();
		P2 = 0xff;
		delay();
		P2 = ans % 256;
		delay();
	}
}