#pragma once

#include <string>
#include <sqlite3.h>
#include "AddNeb.h"
#include "List.h"
#include "AstroCalc.h"

using namespace std;

namespace Astrolib {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::Button^ button_addNeb;

	private: static int create_DB(const char* s) {
		sqlite3* DB;
		int rc = sqlite3_open(s, &DB);

		if (rc != SQLITE_OK) {
			MessageBox::Show(gcnew String(sqlite3_errmsg(DB)), "Error opening database", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return rc;
		}

		sqlite3_close(DB);
		return SQLITE_OK;
	}

	private: static int create_Table(const char* s) {
		sqlite3* DB;
		int rc = sqlite3_open(s, &DB);

		std::string sql_planets = "CREATE TABLE IF NOT EXISTS Planets ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT, "
			"name TEXT, "
			"mass REAL, "
			"mass_stage TEXT, "
			"radius REAL, "
			"planet_type TEXT, "
			"surface_temperature REAL);";

		std::string sql_stars = "CREATE TABLE IF NOT EXISTS Stars ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT, "
			"name TEXT, "
			"mass REAL, "
			"radius REAL, "
			"absolute_magnitude REAL, "
			"surface_temperature REAL);";

		char* messageError = nullptr;
		rc = sqlite3_exec(DB, sql_planets.c_str(), nullptr, 0, &messageError);
		if (rc != SQLITE_OK) {
			sqlite3_free(messageError);
			sqlite3_close(DB);
			return rc;
		}

		rc = sqlite3_exec(DB, sql_stars.c_str(), nullptr, 0, &messageError);
		if (rc != SQLITE_OK) {
			sqlite3_free(messageError);
			sqlite3_close(DB);
			return rc;
		}

		sqlite3_close(DB);
		return SQLITE_OK;
	}

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			   this->button_exit = (gcnew System::Windows::Forms::Button());
			   this->button_addNeb = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // button_exit
			   // 
			   this->button_exit->BackColor = System::Drawing::Color::Red;
			   this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button_exit->Font = (gcnew System::Drawing::Font(L"Arial", 20.25F, System::Drawing::FontStyle::Bold));
			   this->button_exit->ForeColor = System::Drawing::Color::White;
			   this->button_exit->Location = System::Drawing::Point(1423, 15);
			   this->button_exit->Margin = System::Windows::Forms::Padding(4);
			   this->button_exit->Name = L"button_exit";
			   this->button_exit->Size = System::Drawing::Size(55, 50);
			   this->button_exit->TabIndex = 0;
			   this->button_exit->Text = L"X";
			   this->button_exit->UseVisualStyleBackColor = false;
			   this->button_exit->Click += gcnew System::EventHandler(this, &Form1::button_exit_Click);
			   // 
			   // button_addNeb
			   // 
			   this->button_addNeb->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold));
			   this->button_addNeb->Location = System::Drawing::Point(224, 257);
			   this->button_addNeb->Margin = System::Windows::Forms::Padding(4);
			   this->button_addNeb->Name = L"button_addNeb";
			   this->button_addNeb->Size = System::Drawing::Size(180, 100);
			   this->button_addNeb->TabIndex = 1;
			   this->button_addNeb->Text = L"Add new celestial";
			   this->button_addNeb->UseVisualStyleBackColor = true;
			   this->button_addNeb->Click += gcnew System::EventHandler(this, &Form1::button_addNeb_Click);
			   // 
			   // button1
			   // 
			   this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold));
			   this->button1->Location = System::Drawing::Point(660, 257);
			   this->button1->Margin = System::Windows::Forms::Padding(4);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(180, 100);
			   this->button1->TabIndex = 5;
			   this->button1->Text = L"List of celestials";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			   // 
			   // button2
			   // 
			   this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold));
			   this->button2->Location = System::Drawing::Point(1089, 257);
			   this->button2->Margin = System::Windows::Forms::Padding(4);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(180, 100);
			   this->button2->TabIndex = 3;
			   this->button2->Text = L"Astro calculator";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->label1->ForeColor = System::Drawing::Color::White;
			   this->label1->Location = System::Drawing::Point(677, 71);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(145, 42);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"Astrolib";
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			   this->pictureBox1->Location = System::Drawing::Point(402, 228);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(260, 180);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 5;
			   this->pictureBox1->TabStop = false;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox2->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.ErrorImage")));
			   this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			   this->pictureBox2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.InitialImage")));
			   this->pictureBox2->Location = System::Drawing::Point(836, 228);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(260, 180);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox2->TabIndex = 6;
			   this->pictureBox2->TabStop = false;
			   // 
			   // pictureBox3
			   // 
			   this->pictureBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox3->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.ErrorImage")));
			   this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			   this->pictureBox3->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.InitialImage")));
			   this->pictureBox3->Location = System::Drawing::Point(224, 520);
			   this->pictureBox3->Name = L"pictureBox3";
			   this->pictureBox3->Size = System::Drawing::Size(260, 180);
			   this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox3->TabIndex = 7;
			   this->pictureBox3->TabStop = false;
			   this->pictureBox3->Click += gcnew System::EventHandler(this, &Form1::pictureBox3_Click);
			   // 
			   // pictureBox4
			   // 
			   this->pictureBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox4->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.ErrorImage")));
			   this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			   this->pictureBox4->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.InitialImage")));
			   this->pictureBox4->Location = System::Drawing::Point(1120, 540);
			   this->pictureBox4->Name = L"pictureBox4";
			   this->pictureBox4->Size = System::Drawing::Size(81, 78);
			   this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox4->TabIndex = 8;
			   this->pictureBox4->TabStop = false;
			   // 
			   // pictureBox5
			   // 
			   this->pictureBox5->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox5->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.ErrorImage")));
			   this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			   this->pictureBox5->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.InitialImage")));
			   this->pictureBox5->Location = System::Drawing::Point(201, 55);
			   this->pictureBox5->Name = L"pictureBox5";
			   this->pictureBox5->Size = System::Drawing::Size(74, 68);
			   this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox5->TabIndex = 9;
			   this->pictureBox5->TabStop = false;
			   // 
			   // pictureBox6
			   // 
			   this->pictureBox6->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox6->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.ErrorImage")));
			   this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			   this->pictureBox6->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.InitialImage")));
			   this->pictureBox6->Location = System::Drawing::Point(273, 419);
			   this->pictureBox6->Name = L"pictureBox6";
			   this->pictureBox6->Size = System::Drawing::Size(42, 44);
			   this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox6->TabIndex = 10;
			   this->pictureBox6->TabStop = false;
			   // 
			   // pictureBox7
			   // 
			   this->pictureBox7->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox7->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.ErrorImage")));
			   this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			   this->pictureBox7->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.InitialImage")));
			   this->pictureBox7->Location = System::Drawing::Point(1120, 30);
			   this->pictureBox7->Name = L"pictureBox7";
			   this->pictureBox7->Size = System::Drawing::Size(56, 54);
			   this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox7->TabIndex = 11;
			   this->pictureBox7->TabStop = false;
			   // 
			   // pictureBox8
			   // 
			   this->pictureBox8->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox8->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox8->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.ErrorImage")));
			   this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			   this->pictureBox8->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.InitialImage")));
			   this->pictureBox8->Location = System::Drawing::Point(670, 611);
			   this->pictureBox8->Name = L"pictureBox8";
			   this->pictureBox8->Size = System::Drawing::Size(56, 54);
			   this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox8->TabIndex = 12;
			   this->pictureBox8->TabStop = false;
			   // 
			   // pictureBox9
			   // 
			   this->pictureBox9->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox9->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox9->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.ErrorImage")));
			   this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			   this->pictureBox9->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.InitialImage")));
			   this->pictureBox9->Location = System::Drawing::Point(583, 380);
			   this->pictureBox9->Name = L"pictureBox9";
			   this->pictureBox9->Size = System::Drawing::Size(109, 106);
			   this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox9->TabIndex = 13;
			   this->pictureBox9->TabStop = false;
			   // 
			   // pictureBox10
			   // 
			   this->pictureBox10->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->pictureBox10->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox10->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.ErrorImage")));
			   this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			   this->pictureBox10->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.InitialImage")));
			   this->pictureBox10->Location = System::Drawing::Point(496, 118);
			   this->pictureBox10->Name = L"pictureBox10";
			   this->pictureBox10->Size = System::Drawing::Size(56, 54);
			   this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox10->TabIndex = 14;
			   this->pictureBox10->TabStop = false;
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				   static_cast<System::Int32>(static_cast<System::Byte>(126)));
			   this->ClientSize = System::Drawing::Size(1493, 775);
			   this->Controls->Add(this->pictureBox10);
			   this->Controls->Add(this->pictureBox9);
			   this->Controls->Add(this->pictureBox8);
			   this->Controls->Add(this->pictureBox7);
			   this->Controls->Add(this->pictureBox6);
			   this->Controls->Add(this->pictureBox5);
			   this->Controls->Add(this->pictureBox4);
			   this->Controls->Add(this->pictureBox3);
			   this->Controls->Add(this->pictureBox2);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->button_addNeb);
			   this->Controls->Add(this->button_exit);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Form1";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Form1";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		Application::Exit();
	}
	private: System::Void button_addNeb_Click(System::Object^ sender, System::EventArgs^ e) {
		AddNeb^ f2 = gcnew AddNeb();
		f2->Owner = this;
		f2->Show();
		this->Hide();
		const char* db_path = "Stars.db";
		int rc = create_DB(db_path);
		if (rc != SQLITE_OK) {
			MessageBox::Show("Error creating database!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		rc = create_Table(db_path);
		if (rc != SQLITE_OK) {
			MessageBox::Show("Error creating table!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		List^ f3 = gcnew List();
		f3->Owner = this;
		f3->Show();
		this->Hide();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		AstroCalc^ f4 = gcnew AstroCalc();
		f4->Owner = this;
		f4->Show();
	}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(this, "ROCKET BLOWED UP!!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
};
}
