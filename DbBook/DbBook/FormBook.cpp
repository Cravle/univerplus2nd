#include "FormBook.h"

#include "MyForm.h"

using namespace DbBook;
using namespace System;

void FormBook::PrintOnGrid() {
	for (int i = 0; i < Vectors::vecBook->size(); i++) {
		dataGridView1->Rows->Add(
			Vectors::vecBook[i]->getBookId(),
			Vectors::vecBook[i]->getAuthor(),
			Vectors::vecBook[i]->getName(),
			Vectors::vecBook[i]->getYear()
		);

	}
}


void FormBook::helpId() {
	int newId = 1;
	/*if(Vectors::vecBook[0])
		newId = Vectors::vecBook[0]->getIzdatelstvoId();*/
	for (int i = 0; i < Vectors::vecBook->size(); i++)
	{
		if (Vectors::vecBook[i]->getBookId() == newId)
			newId++;
	}

	this->textBox1->Text = Convert::ToString(newId);
}

Void FormBook::button1_Click(Object^ sender, EventArgs^ e) {
	FileStream^ writeBookTab = gcnew FileStream("BookTab.dat", FileMode::Create, FileAccess::Write);
	BinaryWriter^ binwriteBookTab = gcnew BinaryWriter(writeBookTab);
	for (int i = 0; i < Vectors::vecBook->size(); i++) {
		Vectors::vecBook[i]->Write(binwriteBookTab);
	}
	writeBookTab->Close();
	binwriteBookTab->Close();

	this->Close();

}

Void FormBook::button2_Click(System::Object^ sender, System::EventArgs^ e) {
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

Void FormBook::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox1->Checked)
	{
		bool checkRes = true;

		for (int i = 0; i < Vectors::vecRes->size(); i++)
		{
			if (Vectors::vecRes[i]->getBookId() == Vectors::vecBook[dataGridView1->CurrentRow->Index]->getBookId()) {
				MessageBox::Show("Нельзя удалить данную строку так как от нее зависит другая таблица", "Ошибка");
				return;
			}
		}

		if (dataGridView1->SelectedRows->Count > 0 && dataGridView1->SelectedRows[0]->Index != dataGridView1->Rows->Count - 1) {
			dataGridView1->Rows->RemoveAt(dataGridView1->SelectedRows[0]->Index);
		}
		Vectors::vecBook->clear();

		Book^ obj;
		for (int i = 0; i < (dataGridView1->RowCount) - 1; i++)
		{
			obj = gcnew Book(
				Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value),
				Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value),
				Convert::ToString(dataGridView1->Rows[i]->Cells[2]->Value),
				Convert::ToInt32(dataGridView1->Rows[i]->Cells[3]->Value));
			Vectors::vecBook->push_back(obj);
		}

		this->checkBox1->Checked = false;
		this->helpId();
	}
	else {
		MessageBox::Show("Поставьте галочку, что подтверждаете удаление", "Требуется подтверждение");
	}
}

Void FormBook::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	int ID;
	int year;
	String^ name = textBox6->Text;
	String^ author = textBox7->Text;
	


	if ((textBox1->Text) == "") {
		MessageBox::Show("Необходимо заполнить поле Книга id", "Ошибка");
		return;
	}

	if (name == "" || author == "") {
		MessageBox::Show("Все поля должны быть заполнены", "Ошибка");
		return;
	}

	for (int i = 0; i < name->Length; i++)
	{
		if (Char::IsDigit(name[i])) {
			MessageBox::Show("В поле Название допустим ввод только букв", "Ошибка");
			return;
		}
	}



	for (int i = 0; i < author->Length; i++)
	{
		if (Char::IsDigit(author[i])) {
			MessageBox::Show("В поле Автор допустим ввод только букв", "Ошибка");
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

	numbercheck = textBox5->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("В поле Год публикации допустим ввод только чисел", "Ошибка");
			return;
		}
	}



	ID = Convert::ToInt32(textBox1->Text);
	year = Convert::ToInt32(textBox5->Text);
	if (year <= 1600 || year >= 2020) {
		MessageBox::Show("Год должен быть в диапозоне 1600 < year <= 2020", "Ошибка");
		return;
	}
	if (ID < 0 || ID == 0) {
		MessageBox::Show("Некорректный ввод герой Id", "Ошибка");
		return;
	}
	else if (ID > 0) {
		for (int i = 0; i < Vectors::vecBook->size(); i++) {
			if (ID == Vectors::vecBook[i]->getBookId()) {
				MessageBox::Show("Данный айди Издательства уже существует", "Ошибка");
				return;
			}
		}
	}

	for (int i = 0; i < Vectors::vecBook->size(); i++)
	{
		if (Vectors::vecBook[i]->getName() == textBox6->Text && Vectors::vecBook[i]->getAuthor() == textBox7->Text)
		{
			MessageBox::Show("Такая книга с таким автором уже создана", "Ошибка");
			return;
		}
	}

	dataGridView1->Rows->Add(textBox1->Text, textBox7->Text, textBox6->Text, textBox5->Text);
	textBox1->Text = ""; //BookId int
	textBox7->Text = ""; //Автор
	textBox6->Text = ""; //Название
	textBox5->Text = ""; //Год int 
	

	Vectors::vecBook->clear();


	Book^ obj;
	for (int i = 0; i < (dataGridView1->RowCount) - 1; i++)
	{

		obj = gcnew Book(
			Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value),
			Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value),
			Convert::ToString(dataGridView1->Rows[i]->Cells[2]->Value),
			Convert::ToInt32(dataGridView1->Rows[i]->Cells[3]->Value));
		Vectors::vecBook->push_back(obj);
	}

	FileStream^ writeHeroTab = gcnew FileStream("BookTab.dat", FileMode::Create, FileAccess::Write);
	BinaryWriter^ binwriteHeroTab = gcnew BinaryWriter(writeHeroTab);
	for (int i = 0; i < Vectors::vecBook->size(); i++) {
		Vectors::vecBook[i]->Write(binwriteHeroTab);
	}
	writeHeroTab->Close();
	binwriteHeroTab->Close();

	this->helpId();
}