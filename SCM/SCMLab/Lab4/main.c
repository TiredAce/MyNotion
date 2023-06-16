#include <reg51.h>
#include <absacc.h>
#define uchar unsigned char
#define uint unsigned int
	
#define PA XBYTE[0x8000]
#define PB XBYTE[0x8002]
#define PC XBYTE[0x8004]
#define COM XBYTE[0x8006]

uchar code dis[8] = {0xfe,0xfd,0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
uchar code seg[12] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
uchar buff[8], i;

void delay(unsigned char t)
{
  unsigned char i,j;
  for(i=0;i<t;i++)
  {
    for(j=0;j<200;j++)
    {;}
  }
}

void main()
{
	COM = 0x80;
	for (i = 0; i < 8; i ++) buff[i] = i + 1;
	
	while (1)
	{
		for (i = 0; i < 8; i ++)
		{
			
			PB = dis[i];
			PA = seg[buff[i]];
			delay(10);
		}
	}
}