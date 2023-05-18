#include<iostream>
#include<vector>
#include<array>
#include<iomanip>
#include"Drinkitem.h"
#include "DrinkConsoleApp.h"
using namespace std;

void AddNewDrinks(vector<Drinkitem>& drinks)
{
	drinks.push_back(Drinkitem("紅茶", "大杯", 60));
	drinks.push_back(Drinkitem("紅茶", "小杯", 40));
	drinks.push_back(Drinkitem("綠茶", "大杯", 60));
	drinks.push_back(Drinkitem("紅茶", "小杯", 40));
	drinks.push_back(Drinkitem("咖啡", "大杯", 70));
	drinks.push_back(Drinkitem("咖啡", "小杯", 50));
	drinks.push_back(Drinkitem("可樂", "大杯", 50));
	drinks.push_back(Drinkitem("可樂", "小杯", 25));
}

void DisplayDrinkMenu(vector<Drinkitem>& drinks) {
	cout << setw(4) << "編號" << setw(10) << "飲料名稱" << setw(10) << "大小" <<setw(10)<< "售價" << endl;
	cout << "---------------------------------------" << endl;
	
	int i = 1;
	for (Drinkitem item : drinks) {
		cout << setw(4) << i;//setw()空白
		item.displayitem();
		i++;
	}
	cout << "--------------------------------------" << endl;
}

int main(){
	
	vector<Drinkitem> drinks;
	//array<int, 5> a = { 1,2,3,4,5 };
	//array<array<int, 5>, 3>b = { 1,2,3,4,5,6};二維陣列
	//Drinkitem drink1("紅茶", "大杯", 40); 
	//drinks.push_back(drink1);
	AddNewDrinks(drinks);
	DisplayDrinkMenu(drinks);
	
	return 0;
}

