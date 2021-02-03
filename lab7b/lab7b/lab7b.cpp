#include "SS.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "¬ведите строку" << endl;
	string s;
	getline(cin, s);
	SS ob(s);
	cout << ob;
}
