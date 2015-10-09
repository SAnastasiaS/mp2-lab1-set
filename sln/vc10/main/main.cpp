#include "tbitfield.h"

int main()
{
	TBitField bit(10);
	TBitField bit2(bit);
	int m = bit.GetLength();
	bit.SetBit(1);
	bit.SetBit(5);
	bit.SetBit(4);
	cout<<bit<<" Setting bits 1,4,5 on ""bit(10)""\n";
	bit.ClrBit(5);
	cout<<bit<<" Clear bit 5 on ""bit(10)""\n";
	TBitField bit3(21);
	bit3.SetBit(2);
	bit3.SetBit(15);
	cout<<bit3<<" Setting bits 2,15 on ""bit3(21)""\n";
	TBitField bittemp(10);
	bittemp = bit | bit3;
	cout<<bittemp<<" Operation bit|bit3\n";
}