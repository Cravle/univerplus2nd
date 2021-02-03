#include "train.h"
#include "func.h"


int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
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

        cout << "Введите город >";
        cin >> city;
        cout << "Введите номер >";
        cin >> number;
        cout << "Введите время >";
        cin >> time;


        arr[i] = train(city, number, time);
    }
#else 
    train arr[LENGTH]
    {
        train("Харьков", 4653, "21:52"),
        train("Ужгород", 3214, "19:45"),
        train("Харьков", 5324, "06:52"),
        train("Киев", 1110, "17:32"),
        train("Сумы", 1234, "04:37"),

    };
    

    

#endif // !DEBUG

    
    for (;;) {

        char menu;

        cout << "1. Вывести все поезда 2. Сортировка поездов 3. Вывод поезда по номеру >";
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
            cout << "Введите номер поезда >";
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

