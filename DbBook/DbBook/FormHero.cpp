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

Void FormHero::button1_Click(Object^ sender, EventArgs^ e) {//�����

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


Void FormHero::button3_Click(Object^ sender, EventArgs^ e) {//�������
	if (this->checkBox1->Checked)
	{
		for (int i = 0; i < Vectors::vecRes->size(); i++)
		{
			if (Vectors::vecRes[i]->getHeroId() == Vectors::vecHero[dataGridView1->CurrentRow->Index]->getHeroId()) {
				MessageBox::Show("������ ������� ������ ������ ��� ��� �� ��� ������� ������ �������", "������");
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
		MessageBox::Show("��������� �������, ��� ������������� ��������", "��������� �������������");
	}
	
}


Void FormHero::button4_Click(System::Object^ sender, System::EventArgs^ e) { //��������
	int HeroId;
	int age;
	String^ name = textBox7->Text;
	

	if ((textBox1->Text) == "") {
		MessageBox::Show("���������� ��������� ���� ����� id", "������");
		return;
	}
	if ((textBox6->Text) == "") {
		MessageBox::Show("���������� ��������� ���� �������", "������");
		return;
	}

	
	String^ numbercheck = textBox1->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("� ���� ����� ID �������� ���� ������ �����", "������");
			return;
		}
	}

	numbercheck = textBox6->Text;
	for (int i = 0; i < numbercheck->Length; i++)
	{
		if (!Char::IsDigit(numbercheck[i])) {
			MessageBox::Show("� ���� ������� �������� ���� ������ �����", "������");
			return;
		}
	}

	for (int i = 0; i < name->Length; i++)
	{
		if (Char::IsDigit(name[i])) {
			MessageBox::Show("� ���� ��� �������� ���� ������ ����", "������");
			return;
		}
	}



	HeroId = Convert::ToInt32(textBox1->Text);
	age = Convert::ToInt32(textBox6->Text);
	if (age <= 0 || age >= 120) {
		MessageBox::Show("������� ������ ���� � ��������� 0 < age < 120", "������");
		return;
	}
	if (HeroId < 0 || HeroId == 0) {
		MessageBox::Show("������������ ���� ����� Id", "������");
		return;
	}
	else if (HeroId > 0) {
		for (int i = 0; i < Vectors::vecHero->size(); i++) {
			if (HeroId == Vectors::vecHero[i]->getHeroId()) {
				MessageBox::Show("������ ���� ����� ��� ����������", "������");
				return;
			}
		}

		if (name == "" ) {
			MessageBox::Show("���� ��� ������ ���� ���������", "������");
			return;
		}


		
		
	}

	for (int i = 0; i < Vectors::vecHero->size(); i++)
	{
		if (Vectors::vecHero[i]->getName() == textBox7->Text &&
			Vectors::vecHero[i]->getAge() == Convert::ToInt32(textBox6->Text))
		{
			MessageBox::Show("����� ����� � ����� ��������� ��� ������", "������");
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