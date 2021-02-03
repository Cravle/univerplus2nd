#include "Comp.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Comp> arr;

    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit);

    try
    {
        cout << "������� ������� ����" << endl;
        fin.open("read.txt");
        cout << "���� ������� ������" << endl;
        if (fin.is_open()) {
            int a , b ;
            while (fin >> a >> b) {
                arr.emplace_back(a, b);
            }
        }
    }
    catch (const ifstream::failure& ex)
    {
        if(!fin.is_open())
            cout << "���������� ������� ����" << endl << ex.what() << endl << ex.code() << endl;

    }



    fin.close();


    for (auto& p : arr)
        cout << p.getZ() << endl;

    ofstream fout;
    try
    {
        cout << "������� ������� ����" << endl;
        fout.open("write.txt");
        cout << "���� ������� ������" << endl;
        for (auto& p : arr)
            fout << p.getZ() << endl;
    }
    catch (const ofstream::failure& ex) {
        if (!fout.is_open())
            cout << "���������� ������� ����" << endl << ex.what() << endl << ex.code() << endl;
    }
    fout.close();


    
    system("pause");
}
