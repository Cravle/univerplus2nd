#pragma once

#include "Result.h"
ref class Vectors {
public:
	static vector<Result^>^ vecRes;
	static vector<Hero^>^ vecHero;
	static vector<Book^>^ vecBook;
	static vector<Izdatelstvo^>^ vecIzd;

	Vectors(){
		vecRes = gcnew vector<Result^>();
		vecHero = gcnew vector<Hero^>();
		vecBook = gcnew vector<Book^>();
		vecIzd = gcnew vector<Izdatelstvo^>();
	}
};