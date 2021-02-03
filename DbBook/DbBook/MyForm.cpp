#include "MyForm.h"


using namespace DbBook; // Название проекта

void MyForm::ReadFromFile() {

	FileStream^ readHeroTab = gcnew FileStream("HeroTab.dat", FileMode::Open, FileAccess::Read);
	BinaryReader^ binHeroTab = gcnew BinaryReader(readHeroTab);
	Hero^ heroo;
	while (binHeroTab->BaseStream->Position < binHeroTab->BaseStream->Length) {
		heroo = gcnew Hero();
		heroo->Read(binHeroTab);
		Vectors::vecHero->push_back(heroo);
	}
	readHeroTab->Close();
	binHeroTab->Close();


	FileStream^ readcomtab = gcnew FileStream("BookTab.dat", FileMode::Open, FileAccess::Read);
	BinaryReader^ bincomtab = gcnew BinaryReader(readcomtab);
	Book^ boock;
	while (bincomtab->BaseStream->Position < bincomtab->BaseStream->Length) {
		boock = gcnew Book();
		boock->Read(bincomtab);
		Vectors::vecBook->push_back(boock);
	}
	readcomtab->Close();
	bincomtab->Close();


	FileStream^ readdistab = gcnew FileStream("IzdTab.dat", FileMode::Open, FileAccess::Read);
	BinaryReader^ bindistab = gcnew BinaryReader(readdistab);
	Izdatelstvo^ izd;
	while (bindistab->BaseStream->Position < bindistab->BaseStream->Length) {
		izd = gcnew Izdatelstvo();
		izd->Read(bindistab);
		Vectors::vecIzd->push_back(izd);
	}
	readdistab->Close();
	bindistab->Close();


	FileStream^ readreztab = gcnew FileStream("ResTab.dat", FileMode::Open, FileAccess::Read);
	BinaryReader^ binreztab = gcnew BinaryReader(readreztab);
	Result^ res;
	while (binreztab->BaseStream->Position < binreztab->BaseStream->Length) {
		res = gcnew Result();
		res->Read(binreztab);
		Vectors::vecRes->push_back(res);
	}
	readreztab->Close();
	binreztab->Close();

}

	System::Void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Visible = false;
		FormRes^ formres = gcnew FormRes;
		formres->ShowDialog();
		this->Visible = true;
		
	}

	System::Void MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Visible = false;
		FormHero^ formhero = gcnew FormHero;
		formhero->ShowDialog();
		this->Visible = true;

	}

	System::Void MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Visible = false;
		FormBook^ formbook = gcnew FormBook;
		formbook->ShowDialog();
		this->Visible = true;

	}

	System::Void MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Visible = false;
		FormIzd^ formizd = gcnew FormIzd;
		formizd->ShowDialog();
		this->Visible = true;

	}

	System::Void MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Visible = false;
		BookInfo^ formbook = gcnew BookInfo;
		formbook->ShowDialog();
		this->Visible = true;

	}
	
	System::Void MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->Close();

	}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}