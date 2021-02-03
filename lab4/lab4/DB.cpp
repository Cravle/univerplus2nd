#include "DB.h"

DB::DB(string title) {
	this->title = title;
	col = 0;
	sorted = false;
}

DB::~DB() {
	if (col)
		for (int i = 0; i < col; i++) delete rows[i];

}

void DB::add_rec(string name, string cod, float mark, int place) {
	if (col >= 12) return;
	else col++;
	rows[col - 1] = new sport(name, cod, mark, place);	
}

void DB::del_rec() {
	if (col <= 0)return;
	delete rows[col - 1];
	col--;
}

int DB::getCol() {
	return col;
}

void DB::sortDB() {
	string s1;
	string s2;
	if (col < 2) return;
	sport* temp;

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col; j++)
		{
			s1 = rows[i]->retName();
			s2 = rows[j]->retName();
			if (s1 > s2) {
				temp = rows[i];
				rows[i] = rows[j];
				rows[j] = temp;
			}
		}
	}

	sorted = true;
}

ostream& operator <<(ostream& stream, DB& o1) {


	stream << o1.title << endl;
	if (!o1.sorted)stream << "������� �� �������������." << endl;
	else stream << "������� �������������." << endl;
	buildHead();
	if (!o1.col) stream << "������� �����." << endl;
	else {
		for (int i = 0; i < o1.col; i++)
		{
			stream << *o1.rows[i];
		}
	}

	return stream;
}

