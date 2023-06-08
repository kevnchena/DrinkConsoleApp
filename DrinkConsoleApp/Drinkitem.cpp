#include "Drinkitem.h"
#include<iostream>
using namespace std;

Drinkitem::Drinkitem(const string& a, const string& b, int c)
{
	Name = a;
	Size = b;
	Price = c;
}

void Drinkitem::displayitem()
{
	cout << setw(10) << Name << setw(10) << Size << setw(10) << Price << endl;
}

string Drinkitem::getName()
{
	return Name;
}

string Drinkitem::getSize()
{
	return Size;
}

int Drinkitem::getPrice()
{
	return Price;
}

