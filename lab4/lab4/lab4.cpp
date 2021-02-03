#include "sport.h"
#include "DB.h"



int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    setlocale(LC_ALL, "rus");
    string name;
    string cod;
    float mark;
    int place;

    DB* tmp = new DB("\nБАЗА ДАННЫХ =1\n");

   
    while (true) {
        cout << "В базе: " << tmp->getCol() << " записей" << endl; // В базе
        cout << "1. Добавить запись 11. Добавить готовые данные \n2. Удалить запись \n3. Сортировать базу \n4. Вывести базу" << endl;
        cout << "0. Выход " << endl;
        int menu;
        cin >> menu;
        switch (menu) {
        case 1:
            cout << "Фамилия, код, баллы, место : ";
            cin >> name;
            cin >> cod;
            cin >> mark;
            cin >> place;
            tmp->add_rec(name, cod, mark, place);
            
            break;
        case 11:
            tmp->add_rec("Баландин", "C", 123.7, 2);
            tmp->add_rec("Шишлов", "Ш", 79.98, 3);
            tmp->add_rec("Кравченко", "Д", 134.8, 1);
            break;
        case 2:
            tmp->del_rec();
            break;
        case 3:

            tmp->sortDB();

            break;
        case 4:
            cout << *tmp;
            

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

