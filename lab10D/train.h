#pragma once
#ifndef __TRAIN__H
	#define __TRAIN__H

	#include <iostream>
	#include <string>
	#include <Windows.h>
	#include <stdlib.h>


	#define DEBUG

	using namespace std;

	class train {
	
	public:
		train();

		train(string city, int number, string time);

		void getInfo();

		string getCity();

		string getTime();

		int getNumber();
	
	private:	
		string city;
		int number;
		string time;
	};


#endif // !__TRAIN__H
