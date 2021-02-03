#include "Sum.h"
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Sum> ob1;
    vector<Sum> ob2;


    for (;;) {
        cout << "1. Создать вектора" << endl;
        cout << "2. Посмотреть вектора" << endl;
        cout << "3. Сравнить вектора" << endl;
        int menu;
        int i, j;
        cin >> menu;
        switch (menu) {
        case 1:
            cout << "1й Вектор:" << endl;
            for (int k = 0; k < 3; k++)
            {
                cout << "Введите два значения > " << endl;

                cin >> i;
                cin >> j;
                ob1.push_back(Sum(i, j));
            }

            cout << "2й Вектор:" << endl;
            for (int k = 0; k < 3; k++)
            {
                cout << "Введите два значения > " << endl;

                cin >> i;
                cin >> j;
                ob2.push_back(Sum(i, j));
            }

            break;
        case 2:
            cout << "1й Вектор:" << endl;
            showAll(ob1);
            cout << "2й Вектор:" << endl;
            showAll(ob2);
            break;
        case 3:
            
            biggest(ob1, ob2);
            
        }
        system("pause");
    }
    
    //showAll(ob);
    //
    //for (int i = 0; i < ob.size() - 1; i++)
    //{
    //    biggest(ob, i, i + 1);
    //}

}

/*  v1   1 2  3
         2 4  6
         4 1  5
    
    v2   1 3  4
         1 5  6
         1 1  2

             3<4
             6=6
             5<2
*/
