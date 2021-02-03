#include "Figure.h"

Figure::Figure()
{
	a = 0;
	b = 0;
}

Figure::Figure(int a, int b) {
	this->a = a;
	this->b = b;
}

int Figure::getA() {
	return a;
}

int Figure::getB() {
	return b;
}

//void Figure::show() {
//	int a = this->a;
//	int b = this->b;
//
//	cout << "Площадь плоской фигуры = " << a * b << endl;
//}

Triangle::Triangle(int a, int b, int c) : Figure(a, b)
{
	this->c = c;
	if (a + b <= c || a + c <= b || b + c <= a) {
		cout << "Такого триугольника не бывает" << endl;
		exit(0);
	}
}

void Triangle::show() {
	int a = Figure::getA();
	int b = Figure::getB();
	int c = this->c;
	double P = a + b + c;
	double p = round(P / 2);

	cout << "Площадь треугольника = " << sqrt(p*(p-a)*(p-b)*(p-c)) << endl;
}

Rectangle::Rectangle(int a, int b) : Figure(a,b)
{
}

void Rectangle::show() {
	int a = Figure::getA();
	int b = Figure::getB();
	cout << "Площадь прямоугольника = " << a * b << endl;
}

Circle::Circle(int a, int b) : Figure(a,b) {

}

void Circle::show() {
	int a = getA();
	const double PI = 3.14;

	cout << "Площадь круга = " << a * a * PI << endl;
}