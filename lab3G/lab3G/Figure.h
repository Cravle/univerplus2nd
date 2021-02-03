#pragma once
#include <iostream>
#include <math.h>


using namespace std;
//зависит только от своих аргументов
//всегда возвращает то же значение для тех же переданных аргументов
//не изменяет входных аргуметов

class Figure
{
public:
	Figure();
	Figure(int a, int b);
	virtual void show()=0;
	int getA();
	int getB();

private:
	int a;
	int b;
};

class Triangle : public Figure
{
public:
	Triangle(int a, int b, int c);
	void show() override;
private:
	int c;
};

class Rectangle : public Figure
{
public:
	Rectangle(int a, int b);
	void show() override;

private:

};

class Circle: public Figure
{
public:
	Circle(int a, int b = 0);
	void show()override;

private:

};












