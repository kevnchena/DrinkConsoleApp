#pragma once
#include"Drinkitem.h"
#include<vector>
#include<fstream>

class Orderitem
{
private:
	int itemindex;
	int quantity;
	int subtotal = 0;

public:
	Orderitem(int, int);
	void displayOrderitem(vector<Drinkitem>& drinks);
	int getindex();
	int getquantity();
	void printOrderItem(ofstream & , vector<Drinkitem>&);
};

