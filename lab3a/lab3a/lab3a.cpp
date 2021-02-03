#include "Sobaka.h"
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	//Sobaka ob1;
	Spaniel ob2;

	//cin >> ob1;
//	cout << ob1;
	//ob1.golos();

	cin >> ob2;
	ob2.setColor();
	cout << ob2;
	ob2.showColor();
	ob2.golos();




}
