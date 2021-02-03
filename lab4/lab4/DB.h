#pragma once
#include "sport.h"

class DB
{
public:
	DB(string title);
	~DB();
	friend ostream& operator <<(ostream& stream, DB& o1);

	int getCol();
	void add_rec(string name, string cod, float mark, int place);
	void del_rec();
	void sortDB();

private:
	string title;
	sport* rows[12];
	int col;
	bool sorted;
};

