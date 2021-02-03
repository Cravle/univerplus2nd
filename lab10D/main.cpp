#include "train.h"
#include "func.h"


int main()
{
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
    setlocale(LC_ALL, "rus");
    const int LENGTH = 5;

    int nomer;
    

    

    
#ifndef DEBUG
    train arr[LENGTH];
    for (int i = 0; i < LENGTH; i++)
    {
        string city;
        int number;
        string time;

        cout << "������� ����� >";
        cin >> city;
        cout << "������� ����� >";
        cin >> number;
        cout << "������� ����� >";
        cin >> time;


        arr[i] = train(city, number, time);
    }
#else 
    train arr[LENGTH]
    {
        train("�������", 4653, "21:52"),
        train("�������", 3214, "19:45"),
        train("�������", 5324, "06:52"),
        train("����", 1110, "17:32"),
        train("����", 1234, "04:37"),

    };
    

    

#endif // !DEBUG

    
    for (;;) {

        char menu;

        cout << "1. ������� ��� ������ 2. ���������� ������� 3. ����� ������ �� ������ >";
        cin >> menu;

        switch (menu)
        {

        case '1':
            for (int i = 0; i < LENGTH; i++)
            {
                arr[i].getInfo();
            }
            break;
        case '2':
            for (int i = 0; i < LENGTH - 1; i++)
            {
                sortTrain(arr, LENGTH);
            }
            
            break;

        case '3':
            cout << "������� ����� ������ >";
            cin >> nomer;

            if (nomer == 0000) {
                break;
            }

            getTrainInfo(arr, nomer, LENGTH);
            break;

        default:
            
            exit(0);
            break;
        }

        
        
        

        

        

    }
    return 0;
}

