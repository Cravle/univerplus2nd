#include "Numbers.h"

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
   

    for (;;) {

        Numbers5 ob3;
        //for 1..100          //17   52  87
        ob3.show();
        system("pause");
        system("cls");
    }
}
