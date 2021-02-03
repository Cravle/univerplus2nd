#include "Result.h"

Result::Result() {}
Result::Result(int IzdatelstvoId, int HeroId, int BookId) {
	this->IzdatelstvoId = IzdatelstvoId;
	this->HeroId = HeroId;
	this->BookId = BookId;
}


int Result::getIzdanieId() {
	return IzdatelstvoId;
}
int Result::getHeroId() {
	return HeroId;
}
int Result::getBookId() {
	return BookId;
}

void Result::Write(BinaryWriter^ bw) {
	bw->Write(IzdatelstvoId);
	bw->Write(HeroId);
	bw->Write(BookId);
}

void Result::Read(BinaryReader^ br) {
	IzdatelstvoId = br->ReadInt32();
	HeroId = br->ReadInt32();
	BookId = br->ReadInt32();
}

//-------------HERO -----------------

Hero::Hero(){}

Hero::Hero(int HeroId, String^ name, int age) {
	this->HeroId = HeroId;
	this->name = name;
	this->age = age;
}
int Hero::getHeroId() {
	return HeroId;
}

String^ Hero::getName() {
	return name;
}
int Hero::getAge() {
	return age;
}
void Hero::Write(BinaryWriter^ bw) {
	bw->Write(HeroId);
	bw->Write(name);
	bw->Write(age);
}
void Hero::Read(BinaryReader^ br) {
	HeroId = br->ReadInt32();
	name = br->ReadString();
	age = br->ReadInt32();
}

//-------------BOOK -----------------

Book::Book() {}
Book::Book(int BookId, System::String^ author, System::String^ name, int year) {
	this->BookId = BookId;
	this->author = author;
	this->name = name;
	this->year = year;
}

int Book::getBookId() {
	return BookId;
}

System::String^ Book::getAuthor() {
	return author;
}

System::String^ Book::getName() {
	return name;
}

int Book::getYear() {
	return year;
}

void Book::Write(BinaryWriter^ bw) {
	bw->Write(BookId);
	bw->Write(author);
	bw->Write(name);
	bw->Write(year);
}
void Book::Read(BinaryReader^ br) {
	BookId = br->ReadInt32();
	author = br->ReadString();
	name = br->ReadString();
	year = br->ReadInt32();
}

//-------------Izdatelstvo -----------------
	Izdatelstvo::Izdatelstvo(){}
	Izdatelstvo::Izdatelstvo(int IzdatelstvoId, System::String^ name, System::String^ country, System::String^ director, int year) {
		this->IzdatelstvoId = IzdatelstvoId;
		this->name = name;
		this->country = country;
		this->director = director;
		this->year = year;
	}

	int Izdatelstvo::getIzdatelstvoId() {
		return IzdatelstvoId;
	}

	System::String^ Izdatelstvo::getName(){
		
		return name;
	}

	System::String^ Izdatelstvo::getCountry(){
		return country;
	}

	System::String^ Izdatelstvo::getDirector() {
		return director;
	}

	int Izdatelstvo::getYear(){
		return year;
	}

	void Izdatelstvo::Write(BinaryWriter^ bw){
		bw->Write(IzdatelstvoId);
		bw->Write(name);
		bw->Write(country);
		bw->Write(director);
		bw->Write(year);
	}

	void Izdatelstvo::Read(BinaryReader^ br) {
		IzdatelstvoId = br->ReadInt32();
		name = br->ReadString();
		country = br->ReadString();
		director = br->ReadString();
		year = br->ReadInt32();
	}
	