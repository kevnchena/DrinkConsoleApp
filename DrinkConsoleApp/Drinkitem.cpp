#include "Drinkitem.h"

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
