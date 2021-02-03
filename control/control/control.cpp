#include <iostream>
using namespace std;
class B1
{
public:
	B1(int b1);
	~B1();
	virtual void show();

private:
	int b1;
};

B1::B1(int b1)
{
	this->b1 = b1;
}

void B1::show() {
	cout << "B1 " << b1 << endl;
}

B1::~B1()
{
	cout << "D" << endl;
}

class B2
{
public:
	B2(int a);
	~B2();
	virtual void show();

private:
	int b2;

};

B2::B2(int b2)
{
	this->b2 = b2;
}

void B2::show() {
	cout << "B2 " << b2 << endl;
}

B2::~B2()
{
	cout << "D" << endl;
}

class C : public B1, private B2
{
public:
	C(int c, int b1, int b2);
	~C();
	void show()override;
private:
	int c;
};

C::C(int c, int b1, int b2) : B1(b1), B2(b2) {
	this->c = c;
}

void C::show() {
	B1::show();
	B2::show();
	cout << "C " << c << endl;
}


C::~C()
{
	cout << "D" << endl;
}

class A : private B1, public B2
{
public:
	A(int a, int b1, int b2);
	void show()override;
	~A();

private:
	int a;
};

A::A(int a, int b1, int b2) : B1(b1), B2(b2) 
{
		this->a = a;
}

void A::show() {
	B1::show();
	B2::show();
	cout << "A " << a << endl;
}


A::~A()
{
	cout << "D" << endl;
}


int main()
{
	A obA(3,1,2);
	C obC(6,4,5);

	obA.show();
	obC.show();


}



