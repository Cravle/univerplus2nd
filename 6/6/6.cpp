#include "Transp.h"
//
extern Transp obj1[N];

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	int cost;
	int vparke;
	int rent;
	string name;

	for (int i = 0; i < N; i++)
	{
		cout << "Введите: стоимость, сколько в парке, рентабильность, название" << endl;
		cin >> cost;
		cin >> vparke;
		cin >> rent;
		cin >> name;
		set(obj1[i], cost, vparke, rent, name);
	}

	show();
	sort();

}