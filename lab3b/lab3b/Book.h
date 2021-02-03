#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#define N 3

using namespace std;

class Book
{
public:
	
	Book(string,string,int);
	virtual void show();
	string getBookName();
	


private:
	string name;
	string author;
	int pages;
};



class Library : public Book
{
public:
	Library(int catalog, int vsego, string name, string author, int pages);
	
	void show() override;
	string getStringNalichie();
	int getCountNalichie();
	int getTotalCount();
	int getCatalog();
	void nalichieMinus();
	void nalichiePlus();
private:

	int catalog;
	int nalichie; // ==кол- экз
	int totalCount;// кол экз 
};

 void availableBooks(Library* arr);
 int findBook(Library *arr,int catalog);
 void takeBook(Library* arr, int catalog);
 void returnBook(Library* arr, int catalog);
 void buildLine();






