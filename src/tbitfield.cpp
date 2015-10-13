// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include <assert.h>
#include <algorithm>
 
void TBitField::CheckN (const int n) const 
{
	if ((n<0)||(n>=BitLen))
	{
		throw "Incorrect entries";
	}
}

TBitField::TBitField(int len)
{
	if (len<=0) //?
	{
		throw "Incorrect entries";
	}

	//if (len==0)
	//{
	//	BitLen = 0;
	//	pMem = NULL;
	//	return;
	//}
	MemLen = (len + (sizeof(TELEM)-1))/sizeof(TELEM);// MemLen = (len + 31)>>5;
	pMem = new TELEM[MemLen];
	if ( pMem != NULL)
	{
		BitLen = len;
		for (int i=0; i<MemLen; i++ ) 
			pMem[i] = 0;
	}
	else
	{
		BitLen = 0;
		MemLen = 0;	
	}
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen; 
	MemLen = bf.MemLen; 
	pMem = new TELEM [MemLen];
	if (pMem != NULL ) 
		for (int i=0; i<MemLen; i++)
			pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete[] pMem;
	pMem = NULL;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n / sizeof(TELEM); //return n>>5; 
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{	
	return 1<< (n % sizeof(TELEM));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	CheckN(n);
	pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	CheckN(n);
	pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  CheckN(n);
  return pMem[GetMemIndex(n)] & GetMemMask(n);
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	if (this == &bf)
		return *this;
	BitLen = bf.BitLen;
	if (MemLen != bf.MemLen)
	{
		MemLen = bf.MemLen;
		if (pMem != NULL)
			delete pMem;
		pMem = new TELEM[MemLen];
	}
	if (pMem != NULL)
		for (int i=0; i<MemLen; i++)
			pMem[i] = bf.pMem[i];
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  int result = 1;
  if (BitLen != bf.BitLen)
	  result = 0;
  for (int i=0; i<MemLen; i++)
	  if (pMem[i] != bf.pMem[i])
	  {
		  result = 0;
		  break;
	  }
  return result;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  int result = 1;
  if (BitLen == bf.BitLen)
	  for (int i=0; i<MemLen; i++)
		  if (pMem[i] != bf.pMem[i])
		  {
			  result = 1;
			  break;
		  }
  return result;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	/*int len = max(BitLen, bf.BitLen);
	TBitField temp(len);
	for (int i=0; i<MemLen; ++i)
		temp.pMem[i] = pMem[i];
	for (int i=0; i<bf.MemLen; ++i)
		temp.pMem[i] |= bf.pMem[i];
	return temp;*/

	int len = max(BitLen, bf.BitLen);
	TBitField temp(len);
	for (int i=0; i<BitLen; ++i)
		if (GetBit(i))
			temp.SetBit(i);
	for (int i=0; i<bf.BitLen; ++i)
		if (bf.GetBit(i))
			temp.SetBit(i);
	return temp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	//int len = max(BitLen, bf.BitLen);
	//TBitField temp(len);
	//for (int i=0; i<MemLen; ++i)
	//	temp.pMem[i] = pMem[i];
	//for (int i=0; i<bf.MemLen; ++i)
	//	temp.pMem[i] &= bf.pMem[i];
	//return temp;

	int len = max(BitLen, bf.BitLen);
	TBitField temp(len);
	for (int i=0; i<min(BitLen, bf.BitLen); ++i)
		if (GetBit(i) && bf.GetBit(i))
			temp.SetBit(i);
	return temp;
}

TBitField TBitField::operator~(void) // отрицание
{
	//TBitField temp(BitLen);
	//for (int i=0; i<MemLen; ++i)
	//	temp.pMem[i] = ~pMem[i];
	//return temp;

	TBitField temp(BitLen);
	for (int i=0; i<BitLen; ++i)
		if (GetBit(i))
			temp.ClrBit(i);
		else
			temp.SetBit(i);
	return temp;
}

 //ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	int i=0, k=0;
	char ch;
	cin >> std::ws; // кушает начальные пробелы
	TBitField temp(32);
	if ((char(istr.peek())!='0') && (char(istr.peek())!='1'))
		return istr;
	while (((char(istr.peek())=='0') || (char(istr.peek())=='1')) && (istr.peek()!=EOF))
	{
	while ((i<temp.GetLength()) && ((char(istr.peek())=='0') || (char(istr.peek())=='1')) && (istr.peek()!=EOF))
	{
		istr >> ch;
		if (ch == '0')
			temp.ClrBit(i++);
		else
			if (ch == '1')
				temp.SetBit(i++);
	}
	if ((i==temp.GetLength()) && ((char(istr.peek())=='0') || (char(istr.peek())=='1')))
	{
		TBitField temp_copy(2*temp.GetLength());
		for (k; k<temp.BitLen; k++)
			if (temp.GetBit(k))
				temp_copy.SetBit(k);
		k=i;
		temp=temp_copy;
	}
	}
	TBitField copy(i);
	for (int j=0; j<copy.GetLength(); j++)
		if (temp.GetBit(j))
			copy.SetBit(j);
	bf = copy;
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	for (int i=0; i<bf.GetLength(); ++i)
		if (bf.GetBit(i))
			ostr << 1;
		else 
			ostr << 0;
	return ostr;
}

