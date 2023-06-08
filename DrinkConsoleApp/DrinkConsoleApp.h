#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include"Drinkitem.h"
#include "Orderitem.h"
#include<sstream>
using namespace std;

void AddNewDrinks(vector<Drinkitem>& drinks);
void DisplayDrinkMenu(vector<Drinkitem>& drinks);
void OrderDrink(vector<Orderitem>& order, vector<Drinkitem>& drinks);
void CalculateSalePrice(vector<Orderitem>& order, vector<Drinkitem>& drinks);
void PrintOrder(vector<Orderitem>& , vector<Drinkitem> drinks,string,string,int, int);
string ReadFile(const string&);
vector<string> Split(const string&, char del);