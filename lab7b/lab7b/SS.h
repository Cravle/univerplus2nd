#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

class SS
{
public:
	SS(string s);
	string GetS();
	friend ostream& operator<<(ostream& stream, SS& o1);
private:
	string s;
};



