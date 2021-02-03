#include "FormHero.h"
#include "MyForm.h"
#include "Vectors.h"
#include <iostream>
#include <cliext/vector>



using namespace DbBook;
using namespace System;
using namespace cliext;
using namespace System::IO;


void FormHero::PrintOnGrid() {
	for (int i = 0; i < Vectors::vecHero->size(); i++) {
		dataGridView1->Rows->Add(
			Vectors::vecHero[i]->getHeroId(),
			Vectors::vecHero[i]->getName(),
			Vectors::vecHero[i]->getAge());
			
	}
}

void FormHero::helpHeroId() {
	int newId = 1;
	//int newId = Vectors::vecHero[0]->getHeroId();
	for (int j = 0; j < Vectors::vecHero->size(); j++)
	{
		for (int i = 0; i < Vectors::vecHero->size(); i++)
		{
			if (Vectors::vecHero[i]->getHeroId() == newId)
				newId++;
		}
	}
	

	this->textBox1->Text = Convert::ToString(newId);
}

Void FormHero::button1_Click(Object^ sender, EventArgs^ e) {//выход

	FileStream^ writeHeroTab = gcnew FileStream("HeroTab.dat", FileMode::Create, FileAccess::Write);
	BinaryWriter^ binwriteHeroTab = gcnew BinaryWriter(writeHeroTab);
	for (int i = 0; i < Vectors::vecHero->size(); i++) {
		Vectors::vecHero[i]->Write(binwriteHeroTab);
	}
	writeHeroTab->Close();
	binwriteHeroTab->Close();

	this->Close();

}

Void FormHero::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < dataGridView1->RowCount; i++) {
		dataGridView1->Rows[i]->Selected = false;
	}

	int id;
	if ((textBox2->Text) == "") {
		MessageBox::Show("Поле поиска должно быть заполнено", "Ошибка");
		textBox2->Text = "";
		return;
	}

	String^ numbercheck = textBox2->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("Допустим ввод только чисел", "Ошибка");
			textBox2->Text = "";
			return;
		}
	}

	id = Convert::ToInt32(textBox2->Text);

	if (id <= 0) {
		MessageBox::Show("Не корректный ввод id", "Ошибка");
	}
	else {
		int check = 0;
		for (int i = 0; i < dataGridView1->RowCount; i++) {

			if (id == Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value)) {
				dataGridView1->Rows[i]->Selected = true;
				check++;
			}

		}
		if (check == 0) {
			MessageBox::Show("Не найдено запись с таким id", "Ошибка");
		}
	}
	textBox2->Text = "";

}


Void FormHero::button3_Click(Object^ sender, EventArgs^ e) {//удалить
	if (this->checkBox1->Checked)
	{
		for (int i = 0; i < Vectors::vecRes->size(); i++)
		{
			if (Vectors::vecRes[i]->getHeroId() == Vectors::vecHero[dataGridView1->CurrentRow->Index]->getHeroId()) {
				MessageBox::Show("Нельзя удалить данную строку так как от нее зависит другая таблица", "Ошибка");
				return;
			}
		}
		if (dataGridView1->SelectedRows->Count > 0 && dataGridView1->SelectedRows[0]->Index != dataGridView1->Rows->Count - 1) {
			dataGridView1->Rows->RemoveAt(dataGridView1->SelectedRows[0]->Index);
		}
		Vectors::vecHero->clear();

		Hero^ obj;
		for (int i = 0; i < (dataGridView1->RowCount) - 1; i++)
		{
			obj = gcnew Hero(Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value),
				Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value),
				Convert::ToInt32(dataGridView1->Rows[i]->Cells[2]->Value));
			Vectors::vecHero->push_back(obj);
		}
		this->checkBox1->Checked = false;
		this->helpHeroId();
	}
	else {
		MessageBox::Show("Поставьте галочку, что подтверждаете удаление", "Требуется подтверждение");
	}
	
}


Void FormHero::button4_Click(System::Object^ sender, System::EventArgs^ e) { //добавить
	int HeroId;
	int age;
	String^ name = textBox7->Text;
	

	if ((textBox1->Text) == "") {
		MessageBox::Show("Необходимо заполнить поле Герой id", "Ошибка");
		return;
	}
	if ((textBox6->Text) == "") {
		MessageBox::Show("Необходимо заполнить поле Возраст", "Ошибка");
		return;
	}

	
	String^ numbercheck = textBox1->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("В поле Герой ID допустим ввод только чисел", "Ошибка");
			return;
		}
	}

	numbercheck = textBox6->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("В поле Возраст допустим ввод только чисел", "Ошибка");
			return;
		}
	}

	for (int i = 0; i < name->Length; i++)
	{
		if (Char::IsDigit(name[i])) {
			MessageBox::Show("В поле Имя допустим ввод только букв", "Ошибка");
			return;
		}
	}



	HeroId = Convert::ToInt32(textBox1->Text);
	age = Convert::ToInt32(textBox6->Text);
	if (age <= 0 || age >= 120) {
		MessageBox::Show("Возраст должен быть в диапозоне 0 < age < 120", "Ошибка");
		return;
	}
	if (HeroId < 0 || HeroId == 0) {
		MessageBox::Show("Некорректный ввод герой Id", "Ошибка");
		return;
	}
	else if (HeroId > 0) {
		for (int i = 0; i < Vectors::vecHero->size(); i++) {
			if (HeroId == Vectors::vecHero[i]->getHeroId()) {
				MessageBox::Show("Данный айди Героя уже существует", "Ошибка");
				return;
			}
		}

		if (name == "" ) {
			MessageBox::Show("Поле Имя должно быть заполнено", "Ошибка");
			return;
		}


		
		
	}

	for (int i = 0; i < Vectors::vecHero->size(); i++)
	{
		if (Vectors::vecHero[i]->getName() == textBox7->Text &&
			Vectors::vecHero[i]->getAge() == Convert::ToInt32(textBox6->Text))
		{
			MessageBox::Show("Такой герой с таким возрастом уже создан", "Ошибка");
			return;
		}
	}

	dataGridView1->Rows->Add(textBox1->Text, textBox7->Text, textBox6->Text);
	textBox1->Text = "";
	textBox7->Text = "";
	textBox6->Text = "";

	Vectors::vecHero->clear();


	Hero^ obj;
	for (int i = 0; i < (dataGridView1->RowCount) - 1; i++)
	{

		obj = gcnew Hero(
			Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value),
			Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value),
			Convert::ToInt32(dataGridView1->Rows[i]->Cells[2]->Value));
		Vectors::vecHero->push_back(obj);
	}

	FileStream^ writeHeroTab = gcnew FileStream("HeroTab.dat", FileMode::Create, FileAccess::Write);
	BinaryWriter^ binwriteHeroTab = gcnew BinaryWriter(writeHeroTab);
	for (int i = 0; i < Vectors::vecHero->size(); i++) {
		Vectors::vecHero[i]->Write(binwriteHeroTab);
	}
	writeHeroTab->Close();
	binwriteHeroTab->Close();

	this->helpHeroId();

	
	
}



Void FormHero::FormHero_Load(System::Object^ sender, System::EventArgs^ e) {
	this->helpHeroId();


}