#pragma once
#include <iostream>
#include <string>
#include <cliext/vector>
using namespace System;
using namespace cliext;
using namespace System::IO;
using namespace System::Xml;

ref class Result {

	int IzdatelstvoId;
	int HeroId;
	int BookId;
public:
	Result();
	Result(int IzdatelstvoId, int HeroId, int BookId);
	int getIzdanieId();
	int getHeroId();
	int getBookId();
	void Write(BinaryWriter^ bw);
	void Read(BinaryReader^ br);
};


//-------------HERO -----------------

ref class Hero : public Result {
	int HeroId;
	System::String^ name;
	int age;
public:
	Hero();
	Hero(int HeroId, System::String^ name, int age);
	int getHeroId();
	System::String^ getName();
	int getAge();
	void Write(BinaryWriter^ bw);
	void Read(BinaryReader^ br);
};
//-------------BOOK -----------------

ref class Book : public Result {
	int BookId;
	System::String^ author;
	System::String^ name;
	int year;
public:
	Book();
	Book(int BookId, System::String^ author, System::String^ name, int year);
	int getBookId();
	System::String^ getAuthor();
	System::String^ getName();
	int getYear();
	void Write(BinaryWriter^ bw);
	void Read(BinaryReader^ br);
};
//-------------Izdatelstvo -----------------

ref class Izdatelstvo : public Result {
	int IzdatelstvoId;
	System::String^ name;
	System::String^ country;
	System::String^ director;
	int year;
public:
	Izdatelstvo();
	Izdatelstvo(int IzdatelstvoId, System::String^ name, System::String^ country, System::String^ director,	int year);
	int getIzdatelstvoId();
	System::String^ getName();
	System::String^ getCountry();
	System::String^ getDirector();
	int getYear();
	void Write(BinaryWriter^ bw);
	void Read(BinaryReader^ br);
};


