#include <iostream>
using namespace std;

template<typename T>
class MyClass			//  template MyClass<int>;
{
public:
	MyClass();
	MyClass(T value);

	MyClass<T> operator + (MyClass<T>& ob);
	void showValue();
private:
	T value;
};

template<typename T>
MyClass<T> MyClass<T>::operator+(MyClass<T>& ob) {
	MyClass temp;
	temp.value = this->value + ob.value;
	return temp;
}

template<typename T>
MyClass<T>::MyClass() {
	value = 0;
}

template<typename T>
MyClass<T>::MyClass(T value) {
	this->value = value;
}

template<typename T>
void MyClass<T>::showValue() {
	cout << value << endl;
}


int main()
{
	int a1 = 5 ;
	int a2 = 7 ;

	double b1 = 4.45;
	double b2 = 6.84;

	MyClass<int> ob1(a1);
	MyClass<int> ob11(a2);
	cout << "ob1 = ";
	ob1.showValue();
	cout << "ob11 = ";
	ob11.showValue();
	cout  << "ob1 + ob11 = ";
	(ob1 + ob11).showValue();
	cout << "---------------" << endl;

	MyClass<double> ob2(b1);
	MyClass<double> ob22(b2);
	cout << "ob2 = ";
	ob2.showValue();
	cout  << "ob22 = ";
	ob22.showValue();
	cout << "ob2 + ob22 = ";
	(ob2 + ob22).showValue();
}

