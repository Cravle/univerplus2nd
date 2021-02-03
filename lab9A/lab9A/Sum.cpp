#include "Sum.h"

Sum::Sum()
{
	a = 0;
	b = 0;
	createSum();
}

Sum::Sum(int a, int b)
{
	this->a = a;
	this->b = b;
	createSum();
}

int Sum::getSum() {
	return sum;
}

void Sum::createSum() {
	this->sum = a + b;
}

Sum Sum::operator==(Sum& o1) {
	if (this->getSum() == o1.getSum())
		cout << this->getSum() << " = " << o1.getSum() << endl;
	else if (this->getSum() < o1.getSum())
		cout << this->getSum() << " < " << o1.getSum() << endl;
	else if (this->getSum() > o1.getSum())
		cout << this->getSum() << " > " << o1.getSum() << endl;
	return *this;
}


void showAll( vector<Sum> ob)  {
	for (int i = 0; i < ob.size(); i++)
	{
		cout << setw(4) << ob[i].getSum();
	}
	cout << endl;
}

void biggest(vector<Sum> ob1, vector<Sum> ob2) {
	for (int i = 0; i < 3; i++) {
		buildLine();
		cout << i << ". " << ob1[i].getSum() << " ? " << ob2[i].getSum() << endl;
		ob1[i] == ob2[i];
		
	}
}

void buildLine() {
	cout << "-------------------" << endl;
}