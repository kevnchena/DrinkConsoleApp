#include "Orderitem.h"
#include<iostream>
using namespace std;


Orderitem::Orderitem(int index, int qty) : itemindex{ index }, quantity{qty}
{


}

void Orderitem::displayOrderitem(vector<Drinkitem>& drinks)
{
	Drinkitem drinkitem = drinks[itemindex - 1];
	cout << "�z���I�����Ƭ� : " << drinkitem.getName() << " " << drinkitem.getSize()<< " " << quantity 
		 << "�M,�C�M" << drinkitem.getPrice() << "��" << endl;
}

int Orderitem::getindex()
{
	return itemindex;
}

int Orderitem::getquantity()
{
	return quantity;
}
