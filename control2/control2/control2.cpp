#include <iostream>
using namespace std;

class Date
{
public:
	Date();
	Date(int month, int year);
	Date(const Date& other);
	friend ostream& operator<<(ostream& stream, Date& o1);
	friend void operator<(Date& o1, Date& o2);
	Date operator-(int i);
	void getNameMonth();
	~Date();

private:
	int month;
	int year;
};

Date::Date()
{
	month = 11;
	year = 2020;
}

Date::Date(int month, int year) {
	this->month = month;
	this->year = year;
}

Date::Date(const Date& other) {
	this->month = other.month;
	this->year = other.year;
}

Date::~Date()
{
}

Date Date::operator-(int i) {
	if (i < month) {
		month = month - i;
	}
	else {
		cout << "Ошибка ввода" << endl;
	}
	return *this;
}

ostream& operator<<(ostream& stream, Date& o1) {
	cout << "month: " << o1.month << endl;
	cout << "year: " << o1.year << endl;
	return stream;
}

void Date::getNameMonth() {
	switch (month) {
	case 1:
		cout << "1- январь" << endl;
		break;
	case 2:
		cout << "2- февраль" << endl;
		break;
	case 3:
		cout << "3- март" << endl;
		break;
	case 4:
		cout << "4- апрель" << endl;
		break;
	case 5:
		cout << "5- май" << endl;
		break;
	case 6:
		cout << "6- июнь" << endl;
		break;
	case 7:
		cout << "7- июль" << endl;
		break;
	case 8:
		cout << "8- август" << endl;
		break;
	case 9:
		cout << "9- сентябрь" << endl;
		break;
	case 10:
		cout << "10- октябрь" << endl;
		break;
	case 11:
		cout << "11- ноябрь" << endl;
		break;
	case 12:
		cout << "12- декабрь" << endl;
		break;
	}
}

void operator<(Date& o1, Date& o2) {
	if (o1.year > o2.year)
		cout << "Год " << o1.year << " > " << o2.year << " года" << endl;
	else if (o1.year < o2.year)
		cout << "Год " << o1.year << " < " << o2.year << " года" << endl;
	else
		cout << "Год " << o1.year <<" = " << o2.year << endl;
}

void buildLine() {
	cout << "---------------------------------" << endl;
}


int main()
{
	setlocale(LC_ALL, "rus");
	Date obj1;
	cout << obj1;
	obj1.getNameMonth();
	obj1 - 1;
	cout << obj1;
	obj1.getNameMonth();
	buildLine();

	Date obj2(obj1);
	cout << obj2;
	obj2.getNameMonth();
	buildLine();

	Date obj3(5, 2025);
	cout << obj2;
	obj3 - 5;
	obj3.getNameMonth();
	buildLine();

	obj1 < obj2;
	obj2 < obj3;
	obj3 < obj1;
	
}

