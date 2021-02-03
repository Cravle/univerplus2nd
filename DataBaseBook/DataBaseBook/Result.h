#pragma once
#include <iostream>
#include <string>
using namespace std;

ref class Result {

	int IzdanieId;
	int HeroId;
	int BookId;
public:
	Result();
	Result(int IzdanieId, int HeroId, int BookId);
	int getIzdanieId();
	int getHeroId();
	int getBookId();
};

ref class Hero : public Result{
	int HeroId;
	String^ name;

}


