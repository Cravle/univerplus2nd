#include "Sobaka.h"

Sobaka::Sobaka() {
	cout << "�" << endl;
}

void Sobaka::golos() {
	if (weight < 10)
		cout << "���" << endl;
	else
		cout << "���" << endl;
}

Sobaka::~Sobaka() {
	cout << "�" << endl;
}

ostream& operator <<(ostream& stream, Sobaka& o1) {
	
	
	stream << "�������: " << o1.age <<endl;
	stream << "���: " << o1.weight << endl;
	
	return stream;
}

istream& operator >>(istream& stream, Sobaka& o1) {

	cout << "������� �������, ���: ";
	stream >> o1.age;
	stream >> o1.weight;

	return stream;
}

//_____SPANIEL_____

void Spaniel::setColor() {
	cout << "������� ����: ";
	cin >> color;
	this->color = color;
}

void Spaniel::showColor() {
	cout << "����: " << color << endl;
}

