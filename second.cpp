//============================================================================
// Name        : second.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

struct Tovar{
	string name;
	int amount;
	float cost;
};

Tovar init_Tovar(string name, int amount, float cost){
	Tovar n;
	n.name = name;
	n.amount = amount;
	n.cost = cost;
	return n;
}

int main() {

	setlocale(LC_ALL, "ru");
	int i ,size, amount;
	float cost, sum = 0, avg = 0;
	string name;
	Tovar buf;

	cout << "Введите количество проданных товаров:" << endl;
	cin >> size;

	Tovar *list = new Tovar[size];
	for (i = 0; i < size; i++)
	{
		cout << "Введите название товара: ";
		cin >> name;
		cout << "Введите количество проданных единиц товара " << name << ": ";
		cin >> amount;
		cout << "Введите цену за единицу товара " << name << ": ";
		cin >> cost;
		*(list + i) = init_Tovar(name, amount, cost);
	}

	for (i = 0; i < size - 1; i++) {
		if (list[i].name > list[i+1].name){
			swap(list[i], list[i+1]);
			i = -1;
		}
	}
	cout<< "Имя\tКол-во\tЦена" << endl;
	for (i = 0; i < size; i++){
		cout<< list[i].name << "\t" << list[i].amount <<"\t" << list[i].cost <<endl;
		sum = sum + list[i].amount * list[i].cost;
		avg = avg + list[i].cost;
	}

	cout << "Общая сумма продаж: "<< sum << endl << "Средняя цена за единицу товара: " << avg/size << endl;
	delete[] list;
	return 0;
}
