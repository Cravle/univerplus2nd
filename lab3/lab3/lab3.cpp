#include "inheritance.h"

int main()
{
	setlocale(LC_ALL, "rus");

	/*B ob(1);
	D1 ob1(2, 3);
	D2 ob2(3, 4);
	D3 ob3(5, 6);*/
	D4 ob4(7, 8, 9);
	D5 ob5(-6, 51, -77, 0);
	//b = -6    d2=51    d3=-77    d5=0
	cout << "D4 ob4(7, 8, 9)" << endl;
	cout << "D5 ob5(10, 11, 12, 13)" << endl;


	/*ob.show();
	ob1.show();
	ob2.show();
	ob3.show();*/
	cout << "—леду€ из иерархии класса D4" << endl;
	ob4.show();
	cout << "—леду€ из иерархии класса D5" << endl;
	ob5.show();

	
}
