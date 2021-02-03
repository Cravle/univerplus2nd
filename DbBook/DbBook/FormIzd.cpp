#include "FormIzd.h"
#include "MyForm.h"

#include "Vectors.h"
#include <iostream>
#include <cliext/vector>
#include <algorithm>

using namespace DbBook;
using namespace System;
using namespace std;

void FormIzd::PrintOnGrid() {

	for (int i = 0; i < Vectors::vecIzd->size(); i++) {
		dataGridView1->Rows->Add(
			Vectors::vecIzd[i]->getIzdatelstvoId(),
			Vectors::vecIzd[i]->getName(),
			Vectors::vecIzd[i]->getCountry(),
			Vectors::vecIzd[i]->getDirector(),
			Vectors::vecIzd[i]->getYear());

	}
}

void FormIzd::helpId() {
	int newId = 1;
	/*if(Vectors::vecIzd[0])
		newId = Vectors::vecIzd[0]->getIzdatelstvoId();*/
	for (int j = 0; j < Vectors::vecIzd->size(); j++)
	{
	
	
		for (int i = 0; i < Vectors::vecIzd->size(); i++)
		{
			if (Vectors::vecIzd[i]->getIzdatelstvoId() == newId)
				newId++;
		}
	}

	this->textBox1->Text = Convert::ToString(newId);
}


//Выход
Void FormIzd::button1_Click(Object^ sender, EventArgs^ e) { 
	FileStream^ writeIzdTab = gcnew FileStream("IzdTab.dat", FileMode::Create, FileAccess::Write);
	BinaryWriter^ binwriteIzdTab = gcnew BinaryWriter(writeIzdTab);
	for (int i = 0; i < Vectors::vecIzd->size(); i++) {
		Vectors::vecIzd[i]->Write(binwriteIzdTab);
	}
	writeIzdTab->Close();
	binwriteIzdTab->Close();
	this->Close();
}

//Поиск
Void FormIzd::button2_Click(System::Object^ sender, System::EventArgs^ e) {
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

//Удалить
Void FormIzd::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox1->Checked)
	{
		for (int i = 0; i < Vectors::vecRes->size(); i++)
		{
			if (Vectors::vecRes[i]->getIzdanieId() == Vectors::vecIzd[dataGridView1->CurrentRow->Index]->getIzdatelstvoId()) {
				MessageBox::Show("Нельзя удалить данную строку так как от нее зависит другая таблица", "Ошибка");
				return;
			}
		}
		if (dataGridView1->SelectedRows->Count > 0 && dataGridView1->SelectedRows[0]->Index != dataGridView1->Rows->Count - 1) {
			dataGridView1->Rows->RemoveAt(dataGridView1->SelectedRows[0]->Index);
		}
		Vectors::vecIzd->clear();

		Izdatelstvo^ obj;
		for (int i = 0; i < (dataGridView1->RowCount) - 1; i++)
		{
			obj =  gcnew Izdatelstvo(
				Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value),
				Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value),
				Convert::ToString(dataGridView1->Rows[i]->Cells[2]->Value),
				Convert::ToString(dataGridView1->Rows[i]->Cells[3]->Value),
				Convert::ToInt32(dataGridView1->Rows[i]->Cells[4]->Value));
			Vectors::vecIzd->push_back(obj);
		}

		this->checkBox1->Checked = false;
		this->helpId();
	}
	else {
		MessageBox::Show("Поставьте галочку, что подтверждаете удаление", "Требуется подтверждение");
	}
}

//Добавить
Void FormIzd::button4_Click(System::Object^ sender, System::EventArgs^ e) { 
	int ID;
	int year;
	String^ name = textBox7->Text;
	String^ Country = textBox6->Text;
	String^ Director = textBox5->Text;


	if ((textBox1->Text) == "") {
		MessageBox::Show("Необходимо заполнить поле Издательстов id", "Ошибка");
		return;
	}
	if ((textBox4->Text) == "") {
		MessageBox::Show("Необходимо заполнить поле Год издания", "Ошибка");
		return;
	}

	if (name == "" || Director == "" || Country == "") {
		MessageBox::Show("Все поля должны быть заполнены", "Ошибка");
		return;
	} 

	for (int i = 0; i < name ->Length; i++)
	{
		if (Char::IsDigit(name[i])) {
			MessageBox::Show("В поле Название допустим ввод только букв", "Ошибка");
			return;
		}
	}



	for (int i = 0; i < Country->Length; i++)
	{
		if (Char::IsDigit(Country[i])) {
			MessageBox::Show("В поле Страна допустим ввод только букв", "Ошибка");
			return;
		}
	}



	for (int i = 0; i < Director->Length; i++)
	{
		if (Char::IsDigit(Director[i])) {
			MessageBox::Show("В поле Директор допустим ввод только букв", "Ошибка");
			return;
		}
	}


	String^ numbercheck = textBox1->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("В поле Издательство ID допустим ввод только чисел", "Ошибка");
			return;
		}
	}

	numbercheck = textBox4->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("В поле Год создания допустим ввод только чисел", "Ошибка");
			return;
		}
	}



	ID = Convert::ToInt32(textBox1->Text);
	year = Convert::ToInt32(textBox4->Text);
	if (year <= 1900 || year >= 2020) {
		MessageBox::Show("Год должен быть в диапозоне 1900 < year < 2020", "Ошибка");
		return;
	}
	if (ID < 0 || ID == 0) {
		MessageBox::Show("Некорректный ввод герой Id", "Ошибка");
		return;
	}
	else if (ID > 0) {
		for (int i = 0; i < Vectors::vecIzd->size(); i++) {
			if (ID == Vectors::vecIzd[i]->getIzdatelstvoId()) {
				MessageBox::Show("Данный айди Издательства уже существует", "Ошибка");
				return;
			}
		}

		




	}

	for (int i = 0; i < Vectors::vecIzd->size(); i++)
	{
		if (Vectors::vecIzd[i]->getName() == textBox7->Text && Vectors::vecIzd[i]->getCountry() == textBox6->Text)
		{
			MessageBox::Show("Такое издание с такой страной уже создана", "Ошибка");
			return;
		}
	}

	dataGridView1->Rows->Add(textBox1->Text, textBox7->Text, textBox6->Text, textBox5->Text, textBox4->Text);
	textBox1->Text = ""; //IzdID int
	textBox7->Text = ""; //Имя
	textBox6->Text = ""; //Страна
	textBox5->Text = ""; //Директор
	textBox4->Text = ""; // год создания int

	Vectors::vecIzd->clear();


	Izdatelstvo^ obj;
	for (int i = 0; i < (dataGridView1->RowCount) - 1; i++)
	{

		obj = gcnew Izdatelstvo(
			Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value),
			Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value),
			Convert::ToString(dataGridView1->Rows[i]->Cells[2]->Value),
			Convert::ToString(dataGridView1->Rows[i]->Cells[3]->Value),
			Convert::ToInt32(dataGridView1->Rows[i]->Cells[4]->Value));
		Vectors::vecIzd->push_back(obj);
	}

	FileStream^ writeHeroTab = gcnew FileStream("IzdTab.dat", FileMode::Create, FileAccess::Write);
	BinaryWriter^ binwriteHeroTab = gcnew BinaryWriter(writeHeroTab);
	for (int i = 0; i < Vectors::vecIzd->size(); i++) {
		Vectors::vecIzd[i]->Write(binwriteHeroTab);
	}
	writeHeroTab->Close();
	binwriteHeroTab->Close();

	this->helpId();


}