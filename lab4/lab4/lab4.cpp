#include "sport.h"
#include "DB.h"



int main()
{
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
    setlocale(LC_ALL, "rus");
    string name;
    string cod;
    float mark;
    int place;

    DB* tmp = new DB("\n���� ������ =1\n");

   
    while (true) {
        cout << "� ����: " << tmp->getCol() << " �������" << endl; // � ����
        cout << "1. �������� ������ 11. �������� ������� ������ \n2. ������� ������ \n3. ����������� ���� \n4. ������� ����" << endl;
        cout << "0. ����� " << endl;
        int menu;
        cin >> menu;
        switch (menu) {
        case 1:
            cout << "�������, ���, �����, ����� : ";
            cin >> name;
            cin >> cod;
            cin >> mark;
            cin >> place;
            tmp->add_rec(name, cod, mark, place);
            
            break;
        case 11:
            tmp->add_rec("��������", "C", 123.7, 2);
            tmp->add_rec("������", "�", 79.98, 3);
            tmp->add_rec("���������", "�", 134.8, 1);
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

