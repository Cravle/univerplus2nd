#include "Sobaka.h"
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

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
