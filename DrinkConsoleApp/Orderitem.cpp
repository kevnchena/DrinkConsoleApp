#include "Orderitem.h"
#include<iostream>
using namespace std;


Orderitem::Orderitem(int index, int qty) : itemindex{ index }, quantity{qty}
{


}

void Orderitem::displayOrderitem(vector<Drinkitem>& drinks)
{
	Drinkitem drinkitem = drinks[itemindex - 1];
	cout << "您所點的飲料為 : " << drinkitem.getName() << " " << drinkitem.getSize() << " " << quantity << "杯,每杯" << drinkitem.getPrice() << endl;
}