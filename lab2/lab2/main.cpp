#include "sport.h"




int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    setlocale(LC_ALL, "rus");
    string n;
    string c;
    float m;
    int p;

    sport ob[N] = { sport("Баландин","C",123.7, 2),
                     sport("Шишлов","Ш",79.98, 3),
                     sport("Кравченко","Д",134.8, 1)

    };

    //ob[0]("Ivankv","aaa",5.5,11);
    //cout<<ob[1][1111]; //6
    while (true) {
 
        cout << "1.Показать таблицу \n2.Вывести объект \n3.Изменить объект \n4. Сравнить объекты" << endl;
        cout << "5.Присвоить объект другой объект \n6.Прибавить объекту объект \n7. Перегрузить()"  << endl;
        cout << "8. Перегрузить[]" << endl;
        int menu;
        cin >> menu;
        switch (menu) {
        case 1:
            showAll(ob);
            break;
        case 2:
            int a;
            cout << "Какой объект хотите вывести: ";
            cin >> a;
            if (check(a))
                cout << ob[a];
            else cout << "Неверный ввод данных" << endl;
            break;
        case 3:

            cout << "Какой объект хотите изменить: ";
            cin >> a;
            if(check(a))
                cin >> ob[a];
            else cout << "Неверный ввод данных" << endl;

            break;
        case 4:
            int i, j;
            cout << "Введите объекты, которые хотите сравнить: ";
            cin >> i;
            cin >> j;
            if(check(i)&&check (j))
                ob[i] == ob[j];
            else cout << "Неверный ввод данных" << endl;

            
            break;
        case 5:

            cout << "Введите объект, которому хотите присвоить и какой присвоить: ";
            cin >> i;
            cin >> j;
            if (i != j) {
                if (check(i) && check(j))
                    ob[i] = ob[j];
                else
                    cout << "Неверный ввод данных" << endl;

            }
            else cout << "Ошибка! Экземпляр не может быть записан сам в себя" << endl;
            break;
        case 6:
            cout << "Введите объект к которому хотите прибавить и объект который хотите прибавить: ";
            cin >> i;
            cin >> j;
            if (check(i) && check(j))
                ob[i] + ob[j];
            else cout << "Неверный ввод данных" << endl;

            break;
        case 7:
            cout << "Какой объект перегрузить: ";
            cin >> a;
            if (check(a)) {
                ob[a]("Ivanov", "aaa", 5.5, 11);
            }
            else cout << "Неверный ввод данных" << endl;

            break;
        case 8:
            cout << "Какой объект перегрузить: ";
            cin >> a;
            if (check(a)) {
                cout << "Длина строки name: " << ob[a][1] << endl;

            }
            else cout << "Неверный ввод данных" << endl;

            break;
        case 0: 
            system("cls");
            break;
        default:
            return 0;
            break;
        }

       

    }
}

