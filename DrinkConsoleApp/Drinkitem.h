#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Drinkitem
{
private:
	string Name;
	string Size;
	int Price;
public:
	Drinkitem(const string&,const string&, int);
	void displayitem();
	string getName();
	string getSize();
	int getPrice();
};

