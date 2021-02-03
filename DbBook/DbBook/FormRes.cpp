#include "FormRes.h"
#include "MyForm.h"
#include <iostream>
#include <Windows.h>

using namespace DbBook;
using namespace System;



void FormRes::PrintOnGrid() {
	for (int i = 0; i < Vectors::vecRes->size(); i++) {
		dataGridView1->Rows->Add(
			Vectors::vecRes[i]->getIzdanieId(),
			Vectors::vecRes[i]->getHeroId(),
			Vectors::vecRes[i]->getBookId()
			
		);

	}
}

Void FormRes::button1_Click(Object^ sender, EventArgs^ e) {
	FileStream^ writeResTab = gcnew FileStream("ResTab.dat", FileMode::Create, FileAccess::Write);
	BinaryWriter^ binwriteResTab = gcnew BinaryWriter(writeResTab);
	for (int i = 0; i < Vectors::vecRes->size(); i++) {
		Vectors::vecRes[i]->Write(binwriteResTab);
	}
	writeResTab->Close();
	binwriteResTab->Close();
	this->Close();
	
}

Void FormRes::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox1->Checked)
	{
		if (dataGridView1->SelectedRows->Count > 0 && dataGridView1->SelectedRows[0]->Index != dataGridView1->Rows->Count - 1) {
			dataGridView1->Rows->RemoveAt(dataGridView1->SelectedRows[0]->Index);
		}
		Vectors::vecRes->clear();

		Result^ obj;
		for (int i = 0; i < (dataGridView1->RowCount) - 1; i++)
		{
			obj = gcnew Result(
				Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value),
				Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value),
				Convert::ToInt32(dataGridView1->Rows[i]->Cells[2]->Value));
			Vectors::vecRes->push_back(obj);
		}

		this->checkBox1->Checked = false;
	
	}
	else {
		MessageBox::Show("Поставьте галочку, что подтверждаете удаление", "Требуется подтверждение");
	}
}

Void FormRes::button4_Click(System::Object^ sender, System::EventArgs^ e) {

	if ((textBox1->Text) == "" ||textBox2->Text == "" || textBox3->Text == "") {
		MessageBox::Show("Все поля должны быть заполнены", "Ошибка");
		return;
	}

	String^ numbercheck = textBox1->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("В поле Издательство Id допустим ввод только чисел", "Ошибка");
			return;
		}
	}

	numbercheck = textBox2->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("В поле Герой Id допустим ввод только чисел", "Ошибка");
			return;
		}
	}

	numbercheck = textBox3->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("В поле Книга Id допустим ввод только чисел", "Ошибка");
			return;
		}
	}

	bool check = true;

	int IzdId = Convert::ToInt32(textBox1->Text);
	int HeroId = Convert::ToInt32(textBox2->Text);
	int BookId = Convert::ToInt32(textBox3->Text);
	
	if (IzdId < 0 || IzdId == 0) {
		MessageBox::Show("Некорректный ввод Издательство Id", "Ошибка");
		check = false;
		return;
	}	
	if (HeroId < 0 || HeroId == 0) {
		MessageBox::Show("Некорректный ввод Издательство Id", "Ошибка");
		check = false;
		return;
	}	
	if (BookId < 0 || BookId == 0) {
		MessageBox::Show("Некорректный ввод Издательство Id", "Ошибка");
		check = false;
		return;
	}

	for (int i = 0; i < Vectors::vecRes->size(); i++) {
		if (IzdId == Vectors::vecRes[i]->getIzdanieId() &&
			HeroId == Vectors::vecRes[i]->getHeroId() &&
			BookId == Vectors::vecRes[i]->getBookId()
			) {
			MessageBox::Show("Данная связь уже существует", "Ошибка");
			return;
		}
	}

	dataGridView1->Rows->Add(textBox1->Text, textBox2->Text, textBox3->Text);
	textBox1->Text = ""; //IzdId int
	textBox2->Text = ""; //HeroId int
	textBox3->Text = ""; //BookId int



	Vectors::vecRes->clear();


	Result^ obj;
	for (int i = 0; i < (dataGridView1->RowCount) - 1; i++)
	{

		obj = gcnew Result(
			Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value),
			Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value),
			Convert::ToInt32(dataGridView1->Rows[i]->Cells[2]->Value));
		Vectors::vecRes->push_back(obj);
	}

	FileStream^ writeHeroTab = gcnew FileStream("ResTab.dat", FileMode::Create, FileAccess::Write);
	BinaryWriter^ binwriteHeroTab = gcnew BinaryWriter(writeHeroTab);
	for (int i = 0; i < Vectors::vecRes->size(); i++) {
		Vectors::vecRes[i]->Write(binwriteHeroTab);
	}
	writeHeroTab->Close();
	binwriteHeroTab->Close();


}
