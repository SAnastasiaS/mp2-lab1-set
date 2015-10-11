// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(-1)
{
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(-1)
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(-1)
{
}

TSet::operator TBitField()
{
	TSet i(10);
	return i;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return 0;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	TSet *i;
	i = new TSet(10);
	return *i;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return 0;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	return 0;
}

TSet TSet::operator+(const TSet &s) // объединение
{
	return s;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	return Elem;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	return Elem;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	return s;
}

TSet TSet::operator~(void) // дополнение
{
	TSet i(10);
	return i;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
	return ostr;
}
