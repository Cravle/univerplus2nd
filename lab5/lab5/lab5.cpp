#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <cctype>
#include <regex>

using namespace std;


void mail() {

    string s;
    cin.get();
    bool check = false;
    regex regular("([\\w-]+)(@)([\\w-]+)(\.)([a-z]{2,5})");//������ ����� �����/����� @ ������ ����� �����/����� . �������� ������ 2-5 ��������

    cout << "������� ��� email" << endl;
    getline(cin, s);
    
    if (regex_match(s.c_str(), regular))
        cout << s;
    else
        cout << "������ �����" << endl;
    cout << endl;
}

void toLower() {
    cin.get();
    cout << "������� ������" << endl;
    string s;
    getline(cin, s);

    std::transform(s.begin(), s.end(), s.begin(), tolower );
    cout << s << endl;
}

void toUpper() {
    cin.get();
    cout << "������� ������" << endl;
    string s;
    getline(cin, s);
    //std::transform(s.begin(), s.end(), s.begin(), toupper);
    cout << s << endl;
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    //nameSurname();

    int menu;
    int temp;
    for (;;) {
        cout << "1 - ����� �������� ������" << endl;
        cout << "2 - Email" << endl;
        cin >> menu;


        switch (menu) {
        case 1:


            cout << "1 - � ������ �������" << endl;
            cout << "2 - � ������� �������" << endl;
            cin >> temp;
            cin.clear();
            if (temp == 1) toLower();
            else if (temp == 2) toUpper();
            break;
        case 2:
            mail();
            break;
        }
        system("pause");

    }
}