#include "Book.h"

int main()
{
    setlocale(LC_ALL, "rus");

    Library arr[N] = {
        Library(11,2,"bookName1", "author1", 243),
        Library(22, 3,"bookName2", "author2", 300),
        Library(33, 1,"bookName3", "author3", 441)
    };

    int menu;

    for (;;) {
        cout << "1. Найти книгу по номеру" << endl;
        cout << "2. Взять книгу по номеру" << endl;
        cout << "3. Вернуть книгу по номеру" << endl;
        cout << "0. Выйти" << endl;
        cout << "Доступные книги с номерами: ";
        availableBooks(arr);
        cout << endl;
        cin >> menu;

        switch (menu) {
        case 1:
            cout << "Введите номер книги" << endl;
            int bookNumber;
            cin >> bookNumber;
            buildLine();
            findBook(arr, bookNumber);
            buildLine();
            break;

        case 2:
            cout << "Введите номер книги" << endl;
           
            cin >> bookNumber;
            buildLine();
            takeBook(arr, bookNumber);
            buildLine();
            break;

        case 3:
            cout << "Введите номер книги" << endl;
            
            cin >> bookNumber;
            buildLine();
            returnBook(arr, bookNumber);
            buildLine();
            break;
        case 0:
            exit(0);
            break;
        }

    }

    
}
// 11     2 (кол.экзм)
//взять 11    1
//взять 11    0
//взять 11   все на руках
//взять 55   такой нет вообще
//вернуть 11    1
//вернуть 11    2
//вернуть 11   все зарегестр. в бибил. книги на месте