#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>


#define N 5

using namespace std;

class Transp
{
public:
	Transp();
	Transp(int cost, int vparke, int rent, string name);
	
	int cost;
	int vparke;
	int rent;
	string name;
	


};



void set(Transp &ob,int& cost, int& vparke, int& rent, string& name);
void show();
void sort();