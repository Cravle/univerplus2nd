#include "sport.h"




int main()
{
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
    setlocale(LC_ALL, "rus");
    string n;
    string c;
    float m;
    int p;

    sport ob[N] = { sport("��������","C",123.7, 2),
                     sport("������","�",79.98, 3),
                     sport("���������","�",134.8, 1)

    };

    //ob[0]("Ivankv","aaa",5.5,11);
    //cout<<ob[1][1111]; //6
    while (true) {
 
        cout << "1.�������� ������� \n2.������� ������ \n3.�������� ������ \n4. �������� �������" << endl;
        cout << "5.��������� ������ ������ ������ \n6.��������� ������� ������ \n7. �����������()"  << endl;
        cout << "8. �����������[]" << endl;
        int menu;
        cin >> menu;
        switch (menu) {
        case 1:
            showAll(ob);
            break;
        case 2:
            int a;
            cout << "����� ������ ������ �������: ";
            cin >> a;
            if (check(a))
                cout << ob[a];
            else cout << "�������� ���� ������" << endl;
            break;
        case 3:

            cout << "����� ������ ������ ��������: ";
            cin >> a;
            if(check(a))
                cin >> ob[a];
            else cout << "�������� ���� ������" << endl;

            break;
        case 4:
            int i, j;
            cout << "������� �������, ������� ������ ��������: ";
            cin >> i;
            cin >> j;
            if(check(i)&&check (j))
                ob[i] == ob[j];
            else cout << "�������� ���� ������" << endl;

            
            break;
        case 5:

            cout << "������� ������, �������� ������ ��������� � ����� ���������: ";
            cin >> i;
            cin >> j;
            if (i != j) {
                if (check(i) && check(j))
                    ob[i] = ob[j];
                else
                    cout << "�������� ���� ������" << endl;

            }
            else cout << "������! ��������� �� ����� ���� ������� ��� � ����" << endl;
            break;
        case 6:
            cout << "������� ������ � �������� ������ ��������� � ������ ������� ������ ���������: ";
            cin >> i;
            cin >> j;
            if (check(i) && check(j))
                ob[i] + ob[j];
            else cout << "�������� ���� ������" << endl;

            break;
        case 7:
            cout << "����� ������ �����������: ";
            cin >> a;
            if (check(a)) {
                ob[a]("Ivanov", "aaa", 5.5, 11);
            }
            else cout << "�������� ���� ������" << endl;

            break;
        case 8:
            cout << "����� ������ �����������: ";
            cin >> a;
            if (check(a)) {
                cout << "����� ������ name: " << ob[a][1] << endl;

            }
            else cout << "�������� ���� ������" << endl;

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

