#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

#define N 100
using namespace std;

class Numbers
{
public:
	Numbers();
	virtual int getX(int i);
	virtual void show();
private:
	int x[N];  //  x
};



class Numbers7 : public Numbers
{
public:
	Numbers7();
	void show()override;
	int getSize();
	int getX(int i) override;
private:
	vector<int> x;  //a
};

class Numbers5 : public Numbers7
{
public:
	Numbers5();
	void show()override;  //if(a==2&&b==3) cout<<x;

private:
	vector<int> x;  //b
};






