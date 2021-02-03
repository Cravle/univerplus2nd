#pragma once


#define __SPORT__H

#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS
#define N 3

using namespace std;


class sport {
private:
	string name; //Фамилия
	string cod;  //Команда
	float mark; //Оценка
	int place;  // Место

	friend ostream& operator <<(ostream& stream, sport& o1);
	friend istream& operator >>(istream& stream, sport& o1);

public:
	sport();
	sport(string name, string cod, float mark, int place);
	void set(string name, string cod, float mark, int place);
	void get(string name, string cod, float& mark, int& place);


	sport operator = (sport& o1);
	friend int operator == (sport &o1, sport& o2);
	sport operator + (sport& o1);
	sport operator()(string name, string cod, float mark, int place);
	int operator[](int i);
};

bool check(int a);

void showAll(sport *ob);

void buildHead();
void buildLine();