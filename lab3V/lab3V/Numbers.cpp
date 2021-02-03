#include "Numbers.h"

Numbers::Numbers()
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		x[i] = i;
	}
}

void Numbers::show() {
	
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << x[i];
	}
	cout << endl;
}

int Numbers::getX(int i) {
	return x[i];
}

Numbers7::Numbers7()
{
	for (int i = 0; i < N; i++)
	{
		if (Numbers::getX(i) % 7 == 3)
			x.push_back(Numbers::getX(i));

	}
}

void Numbers7::show() {
	for (int i = 0; i < x.size(); i++)
	{
		cout << setw(4) << x[i];
	}
	cout << endl;
	if (x.size() == 0) {
		cout << "Нет подходящих значений" << endl;
	}
}

int Numbers7::getSize() {
	return x.size();
}

int Numbers7::getX(int i) {
	return x[i];
}

Numbers5::Numbers5()
{
	for (int i = 0; i < Numbers7::getSize(); i++)
	{
		if (Numbers7::getX(i) % 5 == 2)
			x.push_back(Numbers7::getX(i));
	}
}

void Numbers5::show() {
	Numbers::show();
	Numbers7::show();
	for (int i = 0; i < x.size(); i++)
	{
		cout << setw(4) << x[i];
	}
	cout << endl;
	if (x.size() == 0) {
		cout << "Нет подходящих значений" << endl;
	}
}
