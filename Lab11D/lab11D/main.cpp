#include "numbers.h"



int main()
{
    setlocale(LC_ALL, "rus");
   
    int size = 5;
    int min = -10;
    int max = 20;

    cout << "size >";
    cin >> size;
    cout << "min >";
    cin >> min;
    cout << "max >";
    cin >> max;

    srand(time(NULL));


    numbers mn(size, min, max);

    cout << "\n2nd\n";
    cout << "size >";
    cin >> size;
    cout << "min >";
    cin >> min;
    cout << "max >";
    cin >> max;
    numbers mn2(size, min, max);

 
    

        mn.fill();
        mn2.fill();

        mn.print();

        mn.findMax();
        mn2.print();

        mn2.findMax();

        unionArr(mn, mn2);

        crossing(mn, mn2);

        razn(mn2, mn, 1);
        razn(mn, mn2, 2);

        dSum(mn, mn2);
        

        //system("pause");
        //system("cls");
    
}

