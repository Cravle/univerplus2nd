#include "Figure.h"

int main()
{
    setlocale(LC_ALL, "rus");
    for (;;) {
        //cout << "1. ������� ������" << endl;
        cout << "2. �����������" << endl;
        cout << "3. �������������" << endl;
        cout << "4. ����" << endl;
        int menu = 0;
        cin >> menu ;
        int a = 0, b = 0, c = 0;
        switch (menu) {
        //case 1:
        //{
        //    cout << "������� 2 ��������> " << endl;;
        //    cin >> a;
        //    cin >> b;
        //    Figure ob1(a, b);  //!!!!!!!!!
        //    ob1.show();
        //}
            break;
        case 2:
        {
            cout << "������� 3 ��������>" << endl;
             cin >> a;
             cin >> b;
             cin >> c;
             Triangle ob2(a, b, c);
             ob2.show();
        }
            break;
        case 3:
        {
            cout << "������� 2 ��������> " << endl;
            cin >> a;
            cin >> b;
            Rectangle ob3(a, b);
            ob3.show();
        }
            break;
        case 4:
        {
            cout << "������� 1 ��������>" << endl;
            cin >> a;
            Circle ob4(a);
            ob4.show();
        }
            break;
        default:
            break;
        }
    }
}


