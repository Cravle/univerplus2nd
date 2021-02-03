#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <iomanip>
using namespace std;

class Sum
{
public:
	Sum();
	Sum(int a, int b);
	int getSum();
	Sum operator==(Sum& o1);

private:
	int a;
	int b;
	int sum;
	void createSum();
};


void showAll(vector<Sum> ob);
void biggest(vector<Sum> ob1, vector<Sum> ob2);
void buildLine();