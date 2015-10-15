#include "tbitfield.h"
#include "tset.h"

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
	bit3.SetBit(4);
	cout<<bit3<<" Setting bits 2, 4,15 on ""bit3(21)""\n";
	TBitField bittemp(10);
	bittemp = bit | bit3;
	cout<<bittemp<<" Operation bit|bit3\n";
	bittemp = bit & bit3;
	cout<<bittemp<<" Operation bit&bit3\n";
	bittemp = ~bit;
	cout<<bittemp<<" Operation ~bit\n";
	TBitField bit4(10);
	cin >> bit4;
	cout << "bit4: "<< bit4 <<"\n";
    const int size = 4;
	TBitField bf1(size), bf2(size);
	bf1.SetBit(1);
	bf1.SetBit(3);
	bf2.SetBit(1);
	bf2.SetBit(2);
	int result = bf1 == bf2;
	cout << "result = bf1 == bf2: "<<result;


//
//	TSet set(10);
//	cin >> set;
//	cout << "Conclusion previously introduced set " << set << "\n";
//	TSet set1(set);
//	cout << "Copy constructor set1(set) " << set1 << "\n";
//	TBitField bit(10);
//	bit.SetBit(1);
//	bit.SetBit(5);
//	bit.SetBit(4);
//	TSet set2 (bit);
//	cout << "Conversion constructor set2(bit- "<< bit<< ") " << set2 << "\n";
//	bit = TBitField(set);
//	cout << "Conversion constructor bit = TBitField(set) " << bit << "\n";
//	int n = set1.GetMaxPower();
//	cout << "MaxPower(set1) = " << n << "\n";
//	int m=3;
//	int l = set1.IsMember(m);
//	cout << "set1.IsMember(3) = "<< l <<"\n";
//	m=1;
//	l = set1.IsMember(m);
//	cout << "set1.IsMember(1) = "<< l <<"\n";
//	set1.InsElem(6);
//	cout << "set1.InsElem(6) "<< set1 <<"\n";
//	set1.DelElem(2);
//	cout << "set1.DelElem(2) "<< set1 <<"\n";
//	TSet set3 = set1;
//	cout << "set3 = set1; set3 = "<< set3 <<"\n";
//	cout << "set1 == set2? "<< (set1 == set2) <<"\n";
//	cout << "set1 != set2? "<< (set1 != set2) <<"\n";
//	cout << "set1 + set2 = "<< (set1 + set2) <<"\n";
//	cout << "set1 + 2 = "<< (set1 + 2) <<"\n";
//	cout << "set1 - 9 = "<< (set1 - 9) <<"\n";
//	cout << "set1*set2 = "<< (set1*set2) <<"\n";
//	cout << "~set1 = "<< (~set1) <<"\n"; //Выводит ноль, нужно ли это?
}