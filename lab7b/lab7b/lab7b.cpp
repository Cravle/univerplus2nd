#include "SS.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "������� ������" << endl;
	string s;
	getline(cin, s);
	SS ob(s);
	cout << ob;
}
