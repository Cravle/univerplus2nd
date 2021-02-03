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
    regex regular("([\\w-]+)(@)([\\w-]+)(\.)([a-z]{2,5})");//больше одной буквы/цифры @ больше одной буквы/цифры . название домена 2-5 символов

    cout << "Введите ваш email" << endl;
    getline(cin, s);
    
    if (regex_match(s.c_str(), regular))
        cout << s;
    else
        cout << "Ошибка ввода" << endl;
    cout << endl;
}

void toLower() {
    cin.get();
    cout << "Введите строку" << endl;
    string s;
    getline(cin, s);

    std::transform(s.begin(), s.end(), s.begin(), tolower );
    cout << s << endl;
}

void toUpper() {
    cin.get();
    cout << "Введите строку" << endl;
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
        cout << "1 - Смена регистра строки" << endl;
        cout << "2 - Email" << endl;
        cin >> menu;


        switch (menu) {
        case 1:


            cout << "1 - В низкий регистр" << endl;
            cout << "2 - В верхний регистр" << endl;
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