#include<iostream>
#include<vector>
#include<array>
#include"Drinkitem.h"
using namespace std;

int main(){
	
	vector<Drinkitem> drinks;
	//array<int, 5> a = { 1,2,3,4,5 };
	//array<array<int, 5>, 3>b = { 1,2,3,4,5,6};二維陣列
	//Drinkitem drink1("紅茶", "大杯", 40); 
	//drinks.push_back(drink1);
	drinks.push_back(Drinkitem("紅茶", "大杯", 60));
	drinks.push_back(Drinkitem("紅茶", "小杯", 40));
	drinks.push_back(Drinkitem("綠茶", "大杯", 60));
	drinks.push_back(Drinkitem("紅茶", "小杯", 40));
	drinks.push_back(Drinkitem("咖啡", "大杯", 70));
	drinks.push_back(Drinkitem("咖啡", "小杯", 50));

	return 0;
}