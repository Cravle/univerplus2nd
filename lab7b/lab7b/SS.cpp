#include "SS.h"

SS::SS(string s)
{
	
	this->s = s;
}

string SS::GetS() {
	return s;
}

ostream& operator<<(ostream& stream, SS& o1) {
    ofstream fout;
    fout.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        string s = o1.GetS();
        cout << "������� ������� ����" << endl;
        fout.open("write.txt");
        cout << "���� ������� ������" << endl;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z' ||
                s[i] >= '�' && s[i] <= '�' ||
                s[i] >= '0' && s[i] <= '9')
                cout << s[i] << " �� ��������" << endl;
            else
                fout << s[i];

        }
    }
    catch (const ofstream::failure& ex) {
        if (!fout.is_open())
            cout << "���������� ������� ����" << endl << ex.what() << endl << ex.code() << endl;
    }
    fout.close();
    return stream;
}