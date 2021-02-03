#include "train.h"

train::train() {
	city = "Харьков";
	number = 0000;
	time = "12:00";
}

train::train(string city, int number, string time) {
	setlocale(LC_ALL, "rus");
	this->city = city;
	this->number = number;
	this->time = time;
}

void train::getInfo() {
		cout << this->city << " " << this->number << " " << this->time << endl;
}

string train::getCity() {
	return city;
}

string train::getTime() {
	return time;
}

int train::getNumber() {
	return number;
}


