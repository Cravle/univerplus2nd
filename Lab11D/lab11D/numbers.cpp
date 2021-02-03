#include "numbers.h"

numbers::numbers(int size , int min, int max) {
	//cout << "�������� ����������� " << this << endl;

	this->size = size;
	this->min = min;
	this->max = max;
	this->arr = new int[size];
	
}

int numbers::fillCheck(int j) {
	int num;
	bool check = true;
	for (int k = 0; k < 10; k++)
	{
		num = rand() % (max + abs(min) + 1) + min;
		for (int i = 0; i < j; i++) {
			check = true;
			if (num == arr[i]) {
				check = false;

				break;
			}
			else check = true;

		}
		if (check) return num;
	}
	
}


void numbers::fill() {
	
	for (int i = 0; i < size; i++)
	{
		arr[i] = fillCheck(i);
		
	}
}



numbers::numbers() {
//cout << "�������� ����������� " << this <<endl;
	this->size = 10;
	this->min = -20;
	this->max = 20;
	this->arr = new int[size];

}

int numbers::getMin() {
	return min;
}

int numbers::getMax() {
	return max;
}

int* numbers::getArr(){
	return arr;
}

int numbers::getSize() {
	return size;
}



void numbers::print() {
	/*cout << "size " << size << endl;
	cout << "min " << min << endl;
	cout << "max " << max << endl;*/

	for (int i = 0; i < size; i++) {
		cout << setw(4) << arr[i];
	}
	cout << endl;
}

void numbers::findMax() {
	int max = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = this->arr[i];
		}
	}
	cout << "max = " << max << endl;
}

numbers::numbers(const numbers &other)
{
	//cout << "�������� ����������� �����������" << this << endl;

	this->size = other.size;
	this->min = other.min;
	this->max = other.max;

	this->arr = new int[other.size];
	for (int i = 0; i < other.size; i++)
	{
		this->arr[i] = other.arr[i];
	}
	

}



numbers::~numbers()
{
	
	//cout << "�������� ���������� " << this << endl;	
		delete[] this->arr;
	
	

}


void check(int size1, int size2,  numbers mn, numbers mn2) {
	bool check = true;
	for (int i = 0; i < size1; i++)
	{
		check = true;
		for (int j = 0; j < size2; j++)
		{
			if (mn2.getArr()[i] == mn.getArr()[j]) {
				check = false;
				break;
			}
		}

		if (check) cout << setw(4) << mn2.getArr()[i];
	}
	
	
}


void unionArr(numbers mn, numbers mn2) {


	int size1 = mn.getSize();//get 1st size
	int size2 = mn2.getSize();//get 2nd size

	cout << "\n �����������\n" << endl;

	for (int i = 0; i < size1; i++)
	{
		cout << setw(4) << mn.getArr()[i];
	}

	
	check(size2, size1, mn, mn2);
	cout << endl;


}



void crossing(numbers mn, numbers mn2) {

	int size1 = mn.getSize();//get 1st size
	int size2 = mn2.getSize();//get 2nd size
	bool check = false;

	cout << "�����������" << endl;

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (mn.getArr()[i] == mn2.getArr()[j] ) {
				cout << setw(4) << mn.getArr()[i];
				check = true;
			}
		}
	}
	cout << endl;

	if (!check) cout << "��� ������������ ���������" << endl;

	
}

void razn( numbers mn, numbers mn2, int k) {
	int size1 = mn.getSize();//get 1st size
	int size2 = mn2.getSize();//get 2nd size
	if(k == 1)
		cout << "\n�������� " << k << "�� � " << k + 1 << "�� ���������" << endl;
	else
		cout << "\n�������� " << k << "�� � " << k - 1 << "�� ���������" << endl;


	check(size2, size1, mn, mn2);
	cout << endl;
}

void dSum(numbers mn, numbers mn2) {
	int size1 = mn.getSize();//get 1st size
	int size2 = mn2.getSize();//get 2nd size
	cout << "\n ������������ ����� \n" << endl;
	check(size1, size2, mn2, mn);
	check(size2, size1, mn, mn2);
	cout << endl;
}