#include "BookInfo.h"
#include "MyForm.h"
#include <iostream>
#include <Windows.h>

using namespace DbBook;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::IO;

void BookInfo::ListForBookName() {

	for (int i = 0; i < Vectors::vecBook->size(); i++) {
		comboBox1->Items->Add(Vectors::vecBook[i]->getName());
	}
}

Void BookInfo::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

Void BookInfo::button2_Click(System::Object^ sender, System::EventArgs^ e) {

	if (comboBox1->Text == "") {
		MessageBox::Show("Необходимо выбрать название книги", "Ошибка");
		return;
	}
	else {
		textBox1->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		textBox5->Text = "";
		textBox6->Text = "";



		vector<String^> checkIzd;
		vector<String^> checkHeroes;

		int rem;

		for (int i = 0; i < Vectors::vecBook->size(); i++) {
			if (comboBox1->Text == Vectors::vecBook[i]->getName()) {
				textBox1->Text = Vectors::vecBook[i]->getAuthor();
				textBox3->Text = Vectors::vecBook[i]->getName();
				textBox4->Text = Convert::ToString(Vectors::vecBook[i]->getYear());

				rem = i;
			}
		}

		for (int i = 0; i < Vectors::vecRes->size(); i++)
		{
			if (Vectors::vecRes[i]->getBookId() == Vectors::vecBook[rem]->getBookId()) {
				for (int j = 0; j < Vectors::vecIzd->size(); j++) {
					if (Vectors::vecRes[i]->getIzdanieId() == Vectors::vecIzd[j]->getIzdatelstvoId()) {

						checkIzd.push_back(Vectors::vecIzd[j]->getName());
					}
				}

				for (int k = 0; k < Vectors::vecHero->size(); k++) {
					if (Vectors::vecRes[i]->getHeroId() == Vectors::vecHero[k]->getHeroId()) {

						checkHeroes.push_back(Vectors::vecHero[k]->getName());
					}
				}


			}
		}

		for (int i = 0; i < checkIzd.size(); i++) {
			for (int j = 0; j < checkIzd.size(); j++) {
				if (checkIzd[i] == checkIzd[j] && i != j) {

					checkIzd.erase(checkIzd.begin() + j);
					j--;
				}
			}
		}

		for (int i = 0; i < checkHeroes.size(); i++) {
			for (int j = 0; j < checkHeroes.size(); j++) {
				if (checkHeroes[i] == checkHeroes[j] && i != j) {

					checkHeroes.erase(checkHeroes.begin() + j);
					j--;
				}
			}
		}

		for (int i = 0; i < checkIzd.size(); i++) {
			textBox5->Text += checkIzd[i] + Environment::NewLine;
			
		}

		for (int i = 0; i < checkHeroes.size(); i++) {
			
			textBox6->Text += checkHeroes[i] + Environment::NewLine;
		}

		checkIzd.clear();
		checkHeroes.clear();
	}
}
