#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class numbers {
public:
	numbers();
	
	numbers(int size, int min, int max); 

	int getMin();
	int getMax();

	int* getArr();
	int getSize();

	int fillCheck(int j);
	void fill();

	void print();
	void findMax();


	
	
	numbers(const numbers& other);
	~numbers();
	

private:
	int size;
	int min;
	int max;
	int* arr;
};

void check(int size1,int size2, numbers mn, numbers mn2);
void unionArr(numbers mn, numbers mn2);

void crossing(numbers mn, numbers mn2);

void razn(numbers mn, numbers mn2, int k);

void dSum(numbers mn, numbers mn2);
