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
		 << "�M,�C�M" << drinkitem.getPrice() << "��,�p�O"<<drinkitem.getPrice()*quantity << endl;
}

int Orderitem::getindex()
{
	return itemindex;
}

int Orderitem::getquantity()
{
	return quantity;
}

void Orderitem::printOrderItem(ofstream & output_file, vector<Drinkitem>& drinks)
{

	Drinkitem drinkitem = drinks[itemindex - 1];
	output_file << "�z���I�����Ƭ� : " << drinkitem.getName() << " " << drinkitem.getSize() << " " << quantity
		<< "�M,�C�M" << drinkitem.getPrice() << "��,�p�O" << drinkitem.getPrice() * quantity << endl;
}
