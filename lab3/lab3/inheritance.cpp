#include "inheritance.h"

B::B() {
	cout << "ÊÏ" << endl;
}

B::B(int a) {
	this->a = a;
}

void B::show() {
	cout << "B= " << a << endl;
}

//----------------D1--------------

D1::D1(int a, int b) : B(a) {
	this->b = b;
}

void D1::show() {
	B::show();
	cout << "D1 = " << b << endl;
}

//----------------D2--------------

D2::D2(int a, int c) : B(a) {
	this->c = c;
}

void D2::show() {
	B::show();
	cout << "D2 = " << c << endl;
}

//----------------D3--------------
D3::D3(int a, int d) : B(a) {
	this->d = d;
}

void D3::show() {
	B::show();
	cout << "D3 = " << d << endl;
}

//----------------D4--------------
D4::D4(int a, int b, int e) : D1(a,b) {
	this->e = e;
}

void D4::show()  {
	
	D1::show();
	cout << "D4 = " << e << endl;
} 

//----------------D5--------------
D5::D5(int a, int c, int d, int f): D2(a,c), D3(a,d) {
	this->f = f;
}

void D5::show() {

	D2::show();
	D3::show();
	cout << "D5 = " << f << endl;
}

