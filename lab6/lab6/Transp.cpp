#include "Transp.h"
Transp obj1[N];

//Transp obj1[N] = {
//		Transp(12,50,5,"Name0"),
//		Transp(10,100,4,"Name1"),
//		Transp(8,200,3,"Name2"),
//		Transp(9,150,4,"Name3"),
//		Transp(15,30,10,"Name4")
//
//};

Transp::Transp()
{
	cost = 0;
	vparke = 0;
	rent = 0;
	name = "name";
}


Transp::Transp(int cost, int vparke, int rent, string name) {
	this->cost = cost;
	this->vparke = vparke;
	this->rent = rent;
	this->name = name;
}

void set(Transp& ob, int& cost, int& vparke, int& rent, string& name) {
	ob.cost = cost;
	ob.vparke = vparke;
	ob.rent = rent;
	ob.name = name;
}

void show() {
	cout << "-----------------------------------------------" << endl;
	cout << setw(10) << "Стоимость" << setw(10) << "В парке" << setw(15) << "Рентабильность" << setw(10) << "Название" << endl;
	cout << "-----------------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << setw(10) << obj1[i].cost << setw(10) << obj1[i].vparke << setw(15) << obj1[i].rent << setw(10) << obj1[i].name << endl;
	}
}

void sort() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (obj1[i].cost > obj1[j].cost)
				swap(obj1[i], obj1[j]);
		}
	}
	show();

}