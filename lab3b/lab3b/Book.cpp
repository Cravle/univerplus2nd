#include "Book.h"

void Book::show() {
	cout << "�������� � �����: " << endl;
	cout << "���: " << name << endl;
	cout << "�����: " << author << endl;
	cout << "���-�� ���: " << pages << endl;
}

Book::Book(string name, string author, int pages) {
	this->name = name;
	this->author = author;
	this->pages = pages;
}

string Book::getBookName() {
	return name;
}



Library::Library(int catalog, int totalCount,string name, string author, int pages): Book( name,  author,  pages) {
	this->catalog = catalog;
	this->totalCount = totalCount;
	this->nalichie = totalCount;
}

string Library::getStringNalichie() {
	if (nalichie)
		return "����� ���� � ����������";
	return "����� ������ � ����-�� �� �����";
}

int Library::getCatalog() {
	return catalog;
}

void Library::nalichieMinus() {
	if (nalichie) {
		nalichie = --nalichie;
		cout << "�� ������� ����� ����� � ��������� " << getBookName() << endl;
	}
	else
		cout << "����� ��� �����������" << endl;
}
void Library::nalichiePlus() {
	if (nalichie != totalCount) {
		nalichie = ++nalichie;
		cout << "�� ������� ������� ����� " << endl;
	}
	else
		cout << "��� ����� �� �����" << endl;
}

void Library::show() {
	Book::show();
	cout << "����� �������� " << catalog << endl;
	if (nalichie) cout << "� ������� " << nalichie << endl;
	else cout << "��� � �������" << endl;
}

int Library::getCountNalichie() {
	return nalichie;
}

int Library::getTotalCount() {
	return totalCount;
}

int findBook(Library* arr, int catalog) {
	bool check = false;
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		if (catalog == arr[i].getCatalog()) {
			check = true;
			t = i;
		}
	}

	if (!check) {
		cout << catalog << ": ��� � ����������" << endl;
		return 0;
	}

	if (check)
	{
		cout << arr[t].getStringNalichie() << endl;
		arr[t].show();
	}
		return 0;
}

void takeBook(Library* arr, int catalog) {
	bool check = false;
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		if (catalog == arr[i].getCatalog()) {
			check = true;
			t = i;
		}
	}
	if(check)
		arr[t].nalichieMinus();
	else
		cout << "�� ������� �����" << endl;
	//cout << "�� ����� ����� � ���������: " << arr[t].getBookName() << endl;
}

void returnBook(Library* arr, int catalog) {
	bool check = false;
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		if (catalog == arr[i].getCatalog()) {
			check = true;
			t = i;
		}
	}
	if (check) {
		arr[t].nalichiePlus();
	}
	else
		cout << "�� ������� �����" << endl;
}

void buildLine() {
	cout << "-------------------" << endl;
}

void availableBooks(Library* arr) {
	for (int i = 0; i < N; i++)
	{
		if (arr[i].getCountNalichie())
			cout << arr[i].getCatalog()<< " ";
	}
}

