#include "Book.h"

void Book::show() {
	cout << "Сведенья о книге: " << endl;
	cout << "Имя: " << name << endl;
	cout << "Автор: " << author << endl;
	cout << "Кол-во стр: " << pages << endl;
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
		return "Книга есть в библиотеке";
	return "Книга сейчас у кого-то на руках";
}

int Library::getCatalog() {
	return catalog;
}

void Library::nalichieMinus() {
	if (nalichie) {
		nalichie = --nalichie;
		cout << "Вы успешно взяли книгу с названием " << getBookName() << endl;
	}
	else
		cout << "Книги уже закончились" << endl;
}
void Library::nalichiePlus() {
	if (nalichie != totalCount) {
		nalichie = ++nalichie;
		cout << "Вы успешно вернули книгу " << endl;
	}
	else
		cout << "Все книги на месте" << endl;
}

void Library::show() {
	Book::show();
	cout << "Номер каталога " << catalog << endl;
	if (nalichie) cout << "В наличии " << nalichie << endl;
	else cout << "Нет в наличии" << endl;
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
		cout << catalog << ": нет в библиотеке" << endl;
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
		cout << "Не найдена книга" << endl;
	//cout << "Вы взяли книгу с названием: " << arr[t].getBookName() << endl;
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
		cout << "Не найдена книга" << endl;
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

