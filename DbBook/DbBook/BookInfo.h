#pragma once

namespace DbBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BookInfo
	/// </summary>
	public ref class BookInfo : public System::Windows::Forms::Form
	{
	public:
		BookInfo(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			ListForBookName();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BookInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox1;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(132, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Автор";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(96, 155);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(151, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(343, 476);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 57);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Выход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BookInfo::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(-541, -149);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(151, 22);
			this->textBox2->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(530, 28);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 41);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Вывести";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &BookInfo::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(348, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Название";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(323, 155);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(151, 22);
			this->textBox3->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(544, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(126, 25);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Год выпуска";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(38, 37);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(251, 25);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Выберите название книги";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(323, 37);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(151, 24);
			this->comboBox1->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(38, 211);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(347, 25);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Издания, которые выпускают книгу ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(546, 211);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(124, 25);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Герои книги";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(549, 155);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(151, 22);
			this->textBox4->TabIndex = 1;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(61, 258);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(293, 151);
			this->textBox5->TabIndex = 1;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(455, 258);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(293, 151);
			this->textBox6->TabIndex = 1;
			// 
			// BookInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Coral;
			this->ClientSize = System::Drawing::Size(837, 599);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label1);
			this->Name = L"BookInfo";
			this->Text = L"BookInfo";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void ListForBookName();
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
