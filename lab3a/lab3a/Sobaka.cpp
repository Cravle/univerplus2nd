#include "Sobaka.h"

Sobaka::Sobaka() {
	cout << "к" << endl;
}

void Sobaka::golos() {
	if (weight < 10)
		cout << "гав" << endl;
	else
		cout << "ГАВ" << endl;
}

Sobaka::~Sobaka() {
	cout << "Д" << endl;
}

ostream& operator <<(ostream& stream, Sobaka& o1) {
	
	
	stream << "Возраст: " << o1.age <<endl;
	stream << "Вес: " << o1.weight << endl;
	
	return stream;
}

istream& operator >>(istream& stream, Sobaka& o1) {

	cout << "Введите возраст, вес: ";
	stream >> o1.age;
	stream >> o1.weight;

	return stream;
}

//_____SPANIEL_____

void Spaniel::setColor() {
	cout << "Введите цвет: ";
	cin >> color;
	this->color = color;
}

void Spaniel::showColor() {
	cout << "Цвет: " << color << endl;
}

