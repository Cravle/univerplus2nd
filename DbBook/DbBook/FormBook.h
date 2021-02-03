#pragma once

namespace DbBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormBook
	/// </summary>
	public ref class FormBook : public System::Windows::Forms::Form
	{
	public:
		FormBook(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			PrintOnGrid();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormBook()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox2;
	protected:

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;

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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Location = System::Drawing::Point(747, 22);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(442, 341);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(150, 282);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 37);
			this->button4->TabIndex = 18;
			this->button4->Text = L"Добавить запись";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &FormBook::button4_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(217, 224);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(208, 22);
			this->textBox5->TabIndex = 2;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(217, 171);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(208, 22);
			this->textBox6->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(217, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(208, 22);
			this->textBox1->TabIndex = 2;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(219, 114);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(208, 22);
			this->textBox7->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(18, 167);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 25);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Название";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(18, 220);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(160, 25);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Год публикации";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(18, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Книга Id";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(18, 114);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(69, 25);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Автор";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(128, 10);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(172, 25);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Добавить запись";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(18, 22);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(723, 430);
			this->dataGridView1->TabIndex = 10;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Книга ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Автор";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Название";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Год публикации";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(897, 459);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 37);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Найти запись";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FormBook::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(18, 507);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 37);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Удалить запись";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FormBook::button3_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1112, 507);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 52);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Выход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormBook::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(966, 419);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(208, 22);
			this->textBox2->TabIndex = 14;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(807, 377);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(320, 25);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Найти запись по id издательства";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(779, 419);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 25);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Книга Id";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(18, 475);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(183, 21);
			this->checkBox1->TabIndex = 25;
			this->checkBox1->Text = L"Подтвердить удаление";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// FormBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Coral;
			this->ClientSize = System::Drawing::Size(1245, 580);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"FormBook";
			this->Text = L"FormBook";
			this->Load += gcnew System::EventHandler(this, &FormBook::FormBook_Load);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void PrintOnGrid();
		void helpId();
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e); //поиск
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void FormBook_Load(System::Object^ sender, System::EventArgs^ e) {
	helpId();
}
};
}
