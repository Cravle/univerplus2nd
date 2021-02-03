#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Sobaka {
	int weight;
	int age;
public:
	Sobaka();
	void golos();
	~Sobaka();


	friend ostream& operator <<(ostream& stream, Sobaka& o1);
	friend istream& operator >>(istream& stream, Sobaka& o1);
};

class Spaniel: public Sobaka {
	string color;
public:
	void setColor();
	void showColor();
};

