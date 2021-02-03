#pragma once
#include <iostream>

using namespace std;

class B {
	int a;
public:
	B();
	B(int a);
	
	 virtual void show();
};

class D1: public B {
	int b;
public:
	D1(int a, int b);
	void show() override;
};

class D2: private B {
	int c;
public:
	D2(int a , int c);
	void show() override;
};

class D3: private B {
	int d;
public:
	D3(int a, int d);
	void show() override;
};

class D4: public D1 {
	int e;
public:
	D4(int a, int b, int e);
	void show() override;
};

class D5: public D2, private D3 {
	int f;
public:
	D5(int a, int c, int d, int f);
	void show() override;
};

