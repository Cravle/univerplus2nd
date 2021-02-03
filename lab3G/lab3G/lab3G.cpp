#include "Figure.h"

int main()
{
    setlocale(LC_ALL, "rus");
    for (;;) {
        //cout << "1. Плоская фигура" << endl;
        cout << "2. Триугольник" << endl;
        cout << "3. Прямоугольник" << endl;
        cout << "4. Круг" << endl;
        int menu = 0;
        cin >> menu ;
        int a = 0, b = 0, c = 0;
        switch (menu) {
        //case 1:
        //{
        //    cout << "Введите 2 значения> " << endl;;
        //    cin >> a;
        //    cin >> b;
        //    Figure ob1(a, b);  //!!!!!!!!!
        //    ob1.show();
        //}
            break;
        case 2:
        {
            cout << "Введите 3 значения>" << endl;
             cin >> a;
             cin >> b;
             cin >> c;
             Triangle ob2(a, b, c);
             ob2.show();
        }
            break;
        case 3:
        {
            cout << "Введите 2 значения> " << endl;
            cin >> a;
            cin >> b;
            Rectangle ob3(a, b);
            ob3.show();
        }
            break;
        case 4:
        {
            cout << "Введите 1 значение>" << endl;
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


