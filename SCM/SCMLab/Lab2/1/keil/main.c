#include <reg51.h>
#include <absacc.h>
#define uint unsigned int
#define uchar unsigned char
	
#define PA XBYTE[0x8000]
#define PB XBYTE[0x8002]
#define PC XBYTE[0x8004]
#define COM XBYTE[0x8006]

uchar k, i;
uchar buff[8];

uchar code dis[8] = {0xfe,0xfd,0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
uchar code seg[12] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void delay(unsigned char t)
{
  unsigned char i,j, k;
  for(i=0;i<200;i++)
  {
    for(j=0;j<200;j++)
    {
			for (k; k < 200; k ++);
		}
  }
}

void main()
{
	
	COM = 0x80;
	EA = 1;   // Enable all
	EX0 = 1; 
	IT0 = 1;
	k = 0;
	for (i = 0; i < 8; i ++) buff[i] = 0;
		
 	while (1)
	{
		buff[7] = k % 10;
		buff[6] = k % 100 / 10;
		for (i = 0; i < 8; i ++)
		{
			
			PB = dis[i];
			PA = seg[buff[i]];
			delay(1);
		}
	}
	
	
}

void int0() interrupt 0
{
	k ++;
}
