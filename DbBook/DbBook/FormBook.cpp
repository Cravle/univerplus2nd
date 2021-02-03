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
		MessageBox::Show("���� ������ ������ ���� ���������", "������");
		textBox2->Text = "";
		return;
	}

	String^ numbercheck = textBox2->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("�������� ���� ������ �����", "������");
			textBox2->Text = "";
			return;
		}
	}

	id = Convert::ToInt32(textBox2->Text);

	if (id <= 0) {
		MessageBox::Show("�� ���������� ���� id", "������");
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
			MessageBox::Show("�� ������� ������ � ����� id", "������");
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
				MessageBox::Show("������ ������� ������ ������ ��� ��� �� ��� ������� ������ �������", "������");
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
		MessageBox::Show("��������� �������, ��� ������������� ��������", "��������� �������������");
	}
}

Void FormBook::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	int ID;
	int year;
	String^ name = textBox6->Text;
	String^ author = textBox7->Text;
	


	if ((textBox1->Text) == "") {
		MessageBox::Show("���������� ��������� ���� ����� id", "������");
		return;
	}

	if (name == "" || author == "") {
		MessageBox::Show("��� ���� ������ ���� ���������", "������");
		return;
	}

	for (int i = 0; i < name->Length; i++)
	{
		if (Char::IsDigit(name[i])) {
			MessageBox::Show("� ���� �������� �������� ���� ������ ����", "������");
			return;
		}
	}



	for (int i = 0; i < author->Length; i++)
	{
		if (Char::IsDigit(author[i])) {
			MessageBox::Show("� ���� ����� �������� ���� ������ ����", "������");
			return;
		}
	}





	String^ numbercheck = textBox1->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("� ���� ������������ ID �������� ���� ������ �����", "������");
			return;
		}
	}

	numbercheck = textBox5->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("� ���� ��� ���������� �������� ���� ������ �����", "������");
			return;
		}
	}



	ID = Convert::ToInt32(textBox1->Text);
	year = Convert::ToInt32(textBox5->Text);
	if (year <= 1600 || year >= 2020) {
		MessageBox::Show("��� ������ ���� � ��������� 1600 < year <= 2020", "������");
		return;
	}
	if (ID < 0 || ID == 0) {
		MessageBox::Show("������������ ���� ����� Id", "������");
		return;
	}
	else if (ID > 0) {
		for (int i = 0; i < Vectors::vecBook->size(); i++) {
			if (ID == Vectors::vecBook[i]->getBookId()) {
				MessageBox::Show("������ ���� ������������ ��� ����������", "������");
				return;
			}
		}
	}

	for (int i = 0; i < Vectors::vecBook->size(); i++)
	{
		if (Vectors::vecBook[i]->getName() == textBox6->Text && Vectors::vecBook[i]->getAuthor() == textBox7->Text)
		{
			MessageBox::Show("����� ����� � ����� ������� ��� �������", "������");
			return;
		}
	}

	dataGridView1->Rows->Add(textBox1->Text, textBox7->Text, textBox6->Text, textBox5->Text);
	textBox1->Text = ""; //BookId int
	textBox7->Text = ""; //�����
	textBox6->Text = ""; //��������
	textBox5->Text = ""; //��� int 
	

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