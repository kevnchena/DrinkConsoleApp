#include"DrinkConsoleApp.h"

int main(){
	
	vector<Drinkitem> drinks;
	vector<Orderitem> order;

	//array<int, 5> a = { 1,2,3,4,5 };
	//array<array<int, 5>, 3>b = { 1,2,3,4,5,6};二維陣列
	//Drinkitem drink1("紅茶", "大杯", 40); 
	//drinks.push_back(drink1);
	
	//新增飲料品項
	AddNewDrinks(drinks);
	//顯示飲料品項
	DisplayDrinkMenu(drinks);
	//點餐
	OrderDrink(order, drinks);
	//計算總金額與售價
	CalculateSalePrice(order,drinks);
	return 0;
}

void AddNewDrinks(vector<Drinkitem>& drinks)
{
	/*drinks.push_back(Drinkitem("紅茶", "大杯", 60));
	drinks.push_back(Drinkitem("紅茶", "小杯", 40));
	drinks.push_back(Drinkitem("綠茶", "大杯", 60));
	drinks.push_back(Drinkitem("紅茶", "小杯", 40));
	drinks.push_back(Drinkitem("咖啡", "大杯", 70));
	drinks.push_back(Drinkitem("咖啡", "小杯", 50));
	drinks.push_back(Drinkitem("可樂", "大杯", 50));
	drinks.push_back(Drinkitem("可樂", "小杯", 25));*/
	string filename("drinks.csv");
	string file_content = ReadFile(filename);
	
	vector<string> lines = Split(file_content,'\n');
	for (string line : lines) {
		vector<string>fields = Split(line, ',');
		if (fields.size() == 3) {
			string name = fields[0];
			string size = fields[1];
			int price = stoi(fields[2]);
			drinks.push_back(Drinkitem(name, size, price));
		}
	}
	
}

string ReadFile(const string& filename) {
	auto string_content = ostringstream();
	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cout << "無法讀取檔案: " << filename << endl;
		return "";
	}
	string_content << input_file.rdbuf();//raw device
	input_file.close();
	return string_content.str();
}

vector<string> Split(const string& string_content, char del) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(string_content);
	while (getline(tokenStream, token, del)) {
		tokens.push_back(token);
	}
	return tokens;
}

void DisplayDrinkMenu(vector<Drinkitem>& drinks) {

	cout << setw(4) << "編號" << setw(10) << "飲料名稱" << setw(10) << "大小" <<setw(10)<< "售價" << endl;
	cout << "--------------------------------------" << endl;
	
	int i = 1;
	//for (Drinkitem item : drinks) {
	//	cout << setw(4) << i;//setw()空白
	//	item.displayitem();
	//	i++;
	//}

	vector<Drinkitem>::iterator v = drinks.begin();//迭代器
	while (v != drinks.end()) {
		cout << setw(4) << i;
		v->displayitem();
		v++;
		i++;
	}
	cout << "--------------------------------------" << endl;
}

void OrderDrink(vector<Orderitem>& order, vector<Drinkitem>& drinks) {
	int index;
	int qty;
	char ans = 'Y';

	do {
		cout << "請輸入要訂購的飲料標號:  ";
		cin >> index;
		cout << "請輸入要訂購的飲料數量:  ";
		cin >> qty;
		if (index<1 || index>drinks.size()) {
			cout << "編號錯誤,請重新輸入:" << endl;
		}
		else if(qty<1){
			cout << "數量錯誤,請重新輸入:" << endl;
		}
		else {
			Orderitem orderitem(index,qty);
			order.push_back(orderitem);
			orderitem.displayOrderitem(drinks);
			cout << "是否繼續點餐?(Y或y繼續點餐)";
			cin >> ans;

		}
	} while (ans == 'Y' || ans == 'y');

}

void CalculateSalePrice(vector<Orderitem>& order, vector<Drinkitem>& drinks) {
	int takein = 1;
	cout << "請問是內用還是外帶?(1.內用 2.外帶)";
	cin >> takein;
	string messagetakein = (takein == 1) ? "內用" : "外帶";

	int totalPrice = 0;
	int salePrice = 0;
	string messagePrice = "";

	cout << "--------------------------------------" << endl;
	cout << "您所點的飲料如下: " << endl;
	cout << "--------------------------------------" << endl;

	for (Orderitem orderitem : order) {
		orderitem.displayOrderitem(drinks);
		Drinkitem drinkitem = drinks[orderitem.getindex() - 1];
		totalPrice += drinkitem.getPrice() * orderitem.getquantity();

	}

	if (totalPrice >= 500) {
		salePrice = totalPrice * 0.8;
		messagePrice = "訂購500元以上者8折";

	}
	else if (totalPrice >= 300) {
		salePrice = totalPrice * 0.9;
		messagePrice = "訂購300元以上者9折";
	}
	else if (totalPrice >= 200) {
		salePrice = totalPrice * 0.95;
		messagePrice = "訂購200元以上者95折";
	}
	else {
		salePrice = totalPrice;
		messagePrice = "訂購未滿200元不打折";
	}

	cout << "------------------------------" << endl;
	cout << "訂購方式: " << messagetakein<< endl;
	cout << "總金額: " << totalPrice << endl;
	cout << messagePrice << endl;
	cout << "售價: " << salePrice << endl;
	cout << "------------------------------" << endl;

	//列印訂單
	PrintOrder(order, drinks, messagetakein, messagePrice, totalPrice, salePrice);
}

void PrintOrder(vector<Orderitem>& order , vector<Drinkitem> drinks, string messagetakein, string totalPrice, int messagePrice, int salePrice)
{
	//cout << "列印" << endl;
	string filename{ "order.txt" };
	ofstream output_file;
	output_file.open(filename, ios::app);
	if (!output_file.is_open()) {
		cout << "無法寫入檔案" << endl;
		return;
	}
	output_file << "--------------------------------------" << endl;
	output_file << "您所點的飲料如下: " << endl;
	output_file << "--------------------------------------" << endl;

	for (Orderitem orderitem : order) {
			orderitem.printOrderItem(output_file,drinks);
	}
	output_file << "------------------------------" << endl;
	output_file << "訂購方式: " << messagetakein << endl;
	output_file << "總金額: " << totalPrice << endl;
	output_file << messagePrice << endl;
	output_file << "售價: " << salePrice << endl;
	output_file << "------------------------------" << endl;

	output_file.close();
}
