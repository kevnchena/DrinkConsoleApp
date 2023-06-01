#pragma once
#include"Drinkitem.h"
#include<vector>

class Orderitem
{
private:
	int itemindex;
	int quantity;
public:
	Orderitem(int, int);
	void displayOrderitem(vector<Drinkitem>& drinks);
	
};

