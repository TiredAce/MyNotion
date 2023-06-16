#include <reg51.h>
#include <absacc.h>
#define uchar unsigned char
#define uint unsigned int
#define PA XBYTE [0x0000]
#define PB XBYTE [0x0002]
#define PC XBYTE [0x0004]
#define COM XBYTE [0x0006]

void main()
{
	COM=0x90;
	while (1)
	{
		PB = PA;
	}
}