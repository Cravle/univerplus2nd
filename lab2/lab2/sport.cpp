#include "sport.h"

using namespace std;

sport::sport() {
	name = "Name";
	cod = 'A';
	mark = 0;
	place = 0;

}

sport::sport(string name, string cod, float mark, int place) {
	this->name = name;
	this->cod = cod;
	this->mark = mark;
	this->place = place;
}


void sport::set(string name, string cod, float mark, int place)
{
	this->name = name;
	this->cod = cod;
	this->mark = mark;
	this->place = place;
}

void sport::get(string name, string cod, float& mark, int& place)
{

	name = this->name;
	cod = this->cod;
	mark = this->mark;
	place = this->place;

}

ostream& operator <<(ostream& stream, sport& o1) {

	
	stream << "|" << setw(17) << o1.name << "  |  ";
	stream  << setw(9) << o1.cod << "  |  ";
	stream  << setw(7) << o1.mark << "  |  ";	
	stream  << setw(9) << o1.place << "  |  ";
	buildLine();
	return stream;
}

istream& operator >>(istream& stream, sport & o1) {

	cout << "Фамилия, код, баллы, место : ";
	stream >> o1.name;
	stream >> o1.cod;
	stream >> o1.mark;
	stream >> o1.place;
	return stream;
}

sport sport::operator = (sport &o1) {

	name = o1.name;
	cod = o1.cod;
	mark = o1.mark;
	place = o1.place;

	return *this;
}

int operator==(sport& o1, sport &o2) {

	if (o2.name != o1.name) cout << "Данные экземпляры класса не равны." << endl;
	else if (o2.cod != o1.cod) cout << "Данные экземпляры класса не равны." << endl;
	else if (o2.mark != o1.mark) cout << "Данные экземпляры класса не равны." << endl;
	else if (o2.place != o1.place) cout << "Данные экземпляры класса не равны." << endl;
	else cout << "Экземпляры класса равны." << endl;
	return 0;
}

sport sport::operator+(sport& o1) {
	name = name + o1.name;
	cod = cod + o1.cod;
	mark = mark + o1.mark;
	place = place + o1.place;
	return *this;
}

sport sport::operator()(string name, string cod, float mark, int place) {
	
	this->name = name;
	this->cod = cod;
	this->mark = mark;
	this->place = place;
	return *this;
}

int sport::operator[](int i) {
	int length;
	length = name.length();
	return length;
}

void showAll(sport *ob) {
	buildHead();
	for (int i = 0; i < N; i++)
	{
		cout << ob[i];

	}
}

bool check(int a) {
	if (a < N && a>=0)
		return true;
	return false;
}

void buildHead() {
	printf("|-----------------------------------------------------------|\n");
	printf("|               Ведомость спортивных сотязаний              |\n");
	printf("|-----------------------------------------------------------|\n");
	printf("| Фамилия участника | Код команды | Количество|Места в итоге|\n");
	printf("|                   |             |    баллов |             |\n");
	
}

void buildLine() {
	printf("\n|-------------------|-------------|-----------|-------------|\n");
}