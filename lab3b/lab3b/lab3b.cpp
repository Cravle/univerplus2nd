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
        cout << "1. ����� ����� �� ������" << endl;
        cout << "2. ����� ����� �� ������" << endl;
        cout << "3. ������� ����� �� ������" << endl;
        cout << "0. �����" << endl;
        cout << "��������� ����� � ��������: ";
        availableBooks(arr);
        cout << endl;
        cin >> menu;

        switch (menu) {
        case 1:
            cout << "������� ����� �����" << endl;
            int bookNumber;
            cin >> bookNumber;
            buildLine();
            findBook(arr, bookNumber);
            buildLine();
            break;

        case 2:
            cout << "������� ����� �����" << endl;
           
            cin >> bookNumber;
            buildLine();
            takeBook(arr, bookNumber);
            buildLine();
            break;

        case 3:
            cout << "������� ����� �����" << endl;
            
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
// 11     2 (���.����)
//����� 11    1
//����� 11    0
//����� 11   ��� �� �����
//����� 55   ����� ��� ������
//������� 11    1
//������� 11    2
//������� 11   ��� ���������. � �����. ����� �� �����