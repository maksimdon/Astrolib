#pragma once

#include <string>
#include <sqlite3.h>
#include <thread>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

namespace Astrolib {

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddNeb
	/// </summary>
	public ref class AddNeb : public System::Windows::Forms::Form
	{
	public:
		AddNeb(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddNeb()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_addNeb_close;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_name;
	private: System::Windows::Forms::TextBox^ textBox_name;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox_type;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ box1;

	private: System::Windows::Forms::Label^ mass;
	private: System::Windows::Forms::ComboBox^ comboBox_mass;

	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ radius;
	private: System::Windows::Forms::TextBox^ textBox_radius;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ planetType_box;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox_temp;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_toMain;
	private: void clode_window() {
		this->Close();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	private: static int insert_Data_Planet(const char* s, std::string name, std::string mass, std::string mass_stage, std::string radius, std::string planet_type, std::string surface_temperature) {
		sqlite3* DB;
		char* messageError;
		int rc = sqlite3_open(s, &DB);

		std::string sql = "INSERT INTO Planets (name, mass, mass_stage, radius, planet_type, surface_temperature) VALUES ('" +
			name + "', " + mass + ", '" + mass_stage + "', " + radius + ", '" + planet_type + "', " + surface_temperature + ");";

		rc = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

		if (rc != SQLITE_OK) {
			MessageBox::Show(gcnew System::String(messageError ? messageError : "Unknown error"), "Error inserting planet data");
			sqlite3_free(messageError);
			sqlite3_close(DB);
			return rc;
		}

		sqlite3_close(DB);
		return SQLITE_OK;
	}

	private: static int insert_Data_Star(const char* s, std::string name, std::string mass, std::string radius, std::string absolute_magnitude, std::string surface_temperature) {
		sqlite3* DB;
		char* messageError;
		int rc = sqlite3_open(s, &DB);

		std::string sql = "INSERT INTO Stars (name, mass, radius, absolute_magnitude, surface_temperature) VALUES ('" +
			name + "', " + mass + ", " + radius + ", " + absolute_magnitude + ", " + surface_temperature + ");";

		rc = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &messageError);

		if (rc != SQLITE_OK) {
			MessageBox::Show(gcnew System::String(messageError ? messageError : "Unknown error"), "Error inserting star data");
			sqlite3_free(messageError);
			sqlite3_close(DB);
			return rc;
		}

		sqlite3_close(DB);
		return SQLITE_OK;
	}

	private: System::Windows::Forms::TextBox^ blesk;
	private: void CheckConditionAndInitialize() {
		bool condition = NebType_CondCheck();
	}
	private: bool NebType_CondCheck() {
		if (this->comboBox_type->Text == "") {
			return true;
		}
	}

	public: event System::EventHandler^ ReturnToMain;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddNeb::typeid));
			this->button_addNeb_close = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox_type = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->box1 = (gcnew System::Windows::Forms::TextBox());
			this->mass = (gcnew System::Windows::Forms::Label());
			this->comboBox_mass = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->radius = (gcnew System::Windows::Forms::Label());
			this->textBox_radius = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->planetType_box = (gcnew System::Windows::Forms::ComboBox());
			this->blesk = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox_temp = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_toMain = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_addNeb_close
			// 
			this->button_addNeb_close->BackColor = System::Drawing::Color::Red;
			this->button_addNeb_close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_addNeb_close->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_addNeb_close->ForeColor = System::Drawing::Color::White;
			this->button_addNeb_close->Location = System::Drawing::Point(1423, 15);
			this->button_addNeb_close->Margin = System::Windows::Forms::Padding(4);
			this->button_addNeb_close->Name = L"button_addNeb_close";
			this->button_addNeb_close->Size = System::Drawing::Size(55, 50);
			this->button_addNeb_close->TabIndex = 0;
			this->button_addNeb_close->Text = L"X";
			this->button_addNeb_close->UseVisualStyleBackColor = false;
			this->button_addNeb_close->Click += gcnew System::EventHandler(this, &AddNeb::button_addNeb_close_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(404, 61);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(611, 42);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ADDING NEW CELESTIAL BODY";
			// 
			// label_name
			// 
			this->label_name->AutoSize = true;
			this->label_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name->ForeColor = System::Drawing::Color::White;
			this->label_name->Location = System::Drawing::Point(200, 200);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(89, 29);
			this->label_name->TabIndex = 2;
			this->label_name->Text = L"Name:";
			// 
			// textBox_name
			// 
			this->textBox_name->Location = System::Drawing::Point(411, 200);
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(310, 22);
			this->textBox_name->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(200, 280);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 29);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Type:";
			// 
			// comboBox_type
			// 
			this->comboBox_type->FormattingEnabled = true;
			this->comboBox_type->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Planet", L"Star", L"Comet" });
			this->comboBox_type->Location = System::Drawing::Point(411, 280);
			this->comboBox_type->Name = L"comboBox_type";
			this->comboBox_type->Size = System::Drawing::Size(158, 24);
			this->comboBox_type->TabIndex = 5;
			this->comboBox_type->Text = L"Planet";
			this->comboBox_type->SelectedIndexChanged += gcnew System::EventHandler(this, &AddNeb::comboBox1_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(200, 360);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 29);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Mass:";
			// 
			// textBox_mass
			// 
			this->box1->Location = System::Drawing::Point(411, 360);
			this->box1->Name = L"textBox_mass";
			this->box1->Size = System::Drawing::Size(178, 22);
			this->box1->TabIndex = 7;
			// 
			// mass
			// 
			this->mass->AutoSize = true;
			this->mass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold));
			this->mass->ForeColor = System::Drawing::Color::White;
			this->mass->Location = System::Drawing::Point(741, 360);
			this->mass->Name = L"mass";
			this->mass->Size = System::Drawing::Size(49, 29);
			this->mass->TabIndex = 8;
			this->mass->Text = L"KG";
			// 
			// comboBox_mass
			// 
			this->comboBox_mass->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"*10^22", L"*10^23", L"*10^24", L"*10^25",
					L"*10^26", L"*10^27"
			});
			this->comboBox_mass->Location = System::Drawing::Point(600, 360);
			this->comboBox_mass->Name = L"comboBox_mass";
			this->comboBox_mass->Size = System::Drawing::Size(121, 24);
			this->comboBox_mass->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(200, 440);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 29);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Radius:";
			// 
			// radius
			// 
			this->radius->AutoSize = true;
			this->radius->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold));
			this->radius->ForeColor = System::Drawing::Color::White;
			this->radius->Location = System::Drawing::Point(762, 440);
			this->radius->Name = L"radius";
			this->radius->Size = System::Drawing::Size(0, 29);
			this->radius->TabIndex = 11;
			// 
			// textBox_radius
			// 
			this->textBox_radius->Location = System::Drawing::Point(411, 440);
			this->textBox_radius->Name = L"textBox_radius";
			this->textBox_radius->Size = System::Drawing::Size(310, 22);
			this->textBox_radius->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(741, 440);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 29);
			this->label6->TabIndex = 14;
			this->label6->Text = L"КМ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(200, 520);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(150, 29);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Planet type:";
			// 
			// planetType_box
			// 
			this->planetType_box->FormattingEnabled = true;
			this->planetType_box->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Rocky", L"Gas giant" });
			this->planetType_box->Location = System::Drawing::Point(411, 520);
			this->planetType_box->Name = L"planetType_box";
			this->planetType_box->Size = System::Drawing::Size(158, 24);
			this->planetType_box->TabIndex = 16;
			// 
			// blesk
			// 
			this->blesk->Location = System::Drawing::Point(411, 550);
			this->blesk->Name = L"blesk";
			this->blesk->Size = System::Drawing::Size(310, 22);
			this->blesk->TabIndex = 17;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(200, 600);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(147, 58);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Surface \ntempreture:";
			// 
			// textBox_temp
			// 
			this->textBox_temp->Location = System::Drawing::Point(411, 630);
			this->textBox_temp->Name = L"textBox_temp";
			this->textBox_temp->Size = System::Drawing::Size(310, 22);
			this->textBox_temp->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(741, 629);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(30, 29);
			this->label9->TabIndex = 19;
			this->label9->Text = L"К";
			// 
			// button_add
			// 
			this->button_add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_add->Location = System::Drawing::Point(1143, 578);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(150, 80);
			this->button_add->TabIndex = 20;
			this->button_add->Text = L"Add";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &AddNeb::button_add_Click);
			// 
			// button_toMain
			// 
			this->button_toMain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_toMain->Location = System::Drawing::Point(1143, 200);
			this->button_toMain->Name = L"button_toMain";
			this->button_toMain->Size = System::Drawing::Size(150, 80);
			this->button_toMain->TabIndex = 21;
			this->button_toMain->Text = L"Back";
			this->button_toMain->UseVisualStyleBackColor = true;
			this->button_toMain->Click += gcnew System::EventHandler(this, &AddNeb::button_toMain_Click);
			// 
			// AddNeb
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->ClientSize = System::Drawing::Size(1493, 775);
			this->Controls->Add(this->button_toMain);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox_temp);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->planetType_box);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox_radius);
			this->Controls->Add(this->radius);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox_mass);
			this->Controls->Add(this->mass);
			this->Controls->Add(this->box1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox_type);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox_name);
			this->Controls->Add(this->label_name);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_addNeb_close);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AddNeb";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddNeb";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_addNeb_close_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		Application::Exit();
	}

	private: void initialize_blesk(int x, int y) {
		this->blesk->Location = System::Drawing::Point(x, y);
		this->blesk->Name = L"blesk";
		this->blesk->Size = System::Drawing::Size(235, 22);
		this->blesk->TabIndex = 17;
		this->Controls->Add(this->blesk);
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		System::String^ selected = (System::String^)comboBox_type->SelectedItem;
		if (selected == "Planet") {
			this->mass->Text = "КG";
			this->Controls->Add(comboBox_mass);
			this->box1->Size = System::Drawing::Size(134, 22);
			this->label6->Text = "KM";
			this->Controls->Remove(this->blesk);
			this->Controls->Add(this->planetType_box);
			this->label7->Text = "Planet type:";
		}
		else if (selected == "Star") {
			this->mass->Text = "Stellar mass";
			this->Controls->Remove(comboBox_mass);
			this->box1->Size = System::Drawing::Size(235, 22);
			this->label6->Text = "Solar radius";
			this->Controls->Remove(this->planetType_box);
			this->initialize_blesk(308, 448);
			this->label7->Text = "Absolute \nmagnitude:";
		}
		else {
			selected = "Planet";
		}
	}
	private: System::Void button_toMain_Click(System::Object^ sender, System::EventArgs^ e) {
		Owner->Show();
		this->clode_window();
	}
	private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e) {
		const char* db_path = "Stars.db";

		std::string NebType = msclr::interop::marshal_as<std::string>(this->comboBox_type->Text);
		if (NebType == "Planet") {

			std::string name;
			if (!this->textBox_name->Text)
			{
				MessageBox::Show(this, "Enter celestial's name!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else
			{
				name = msclr::interop::marshal_as<std::string>(this->textBox_name->Text);
			}

			std::string mass_stage = msclr::interop::marshal_as<std::string>(this->comboBox_mass->Text);

			std::string mass;
			if (
				(System::Convert::ToDouble(this->box1->Text) < 1 && mass_stage == "*10^22")
				|| (System::Convert::ToDouble(this->box1->Text) < 0.1 && mass_stage == "*10^23")
				|| (System::Convert::ToDouble(this->box1->Text) < 0.01 && mass_stage == "*10^24")
				|| (System::Convert::ToDouble(this->box1->Text) < 0.001 && mass_stage == "*10^25")
				|| (System::Convert::ToDouble(this->box1->Text) < 0.0001 && mass_stage == "*10^26")
				|| (System::Convert::ToDouble(this->box1->Text) < 0.00001 && mass_stage == "*10^27")
				)
			{
				MessageBox::Show(this, "Your planet is too light.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			} 
			else if (
				((System::Convert::ToDouble(this->box1->Text) > 5000 && mass_stage == "*10^22") && this->planetType_box->Text == "Rocky") 
				|| ((System::Convert::ToDouble(this->box1->Text) > 500 && mass_stage == "*10^23") && this->planetType_box->Text == "Rocky")
				|| ((System::Convert::ToDouble(this->box1->Text) > 50 && mass_stage == "*10^24") && this->planetType_box->Text == "Rocky")
				|| ((System::Convert::ToDouble(this->box1->Text) > 5 && mass_stage == "*10^25") && this->planetType_box->Text == "Rocky")
				|| ((System::Convert::ToDouble(this->box1->Text) > 0.5 && mass_stage == "*10^26") && this->planetType_box->Text == "Rocky")
				|| ((System::Convert::ToDouble(this->box1->Text) > 0.05 && mass_stage == "*10^27") && this->planetType_box->Text == "Rocky")
				)
			{
				System::Windows::Forms::DialogResult MBoxresult = MessageBox::Show(this, "Your planet is heavier then the heaviest rocky planet known. Are you sure?",
					"Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
				if (MBoxresult == System::Windows::Forms::DialogResult::Yes)
				{
					mass = msclr::interop::marshal_as<std::string>(this->box1->Text);
				}
				else if (MBoxresult == System::Windows::Forms::DialogResult::No || MBoxresult == System::Windows::Forms::DialogResult::Ignore)
				{
					return;
				}
			}
			else if (
				((System::Convert::ToDouble(this->box1->Text) > 5970 && mass_stage == "*10^22") && this->planetType_box->Text == "Rocky")
				|| ((System::Convert::ToDouble(this->box1->Text) > 597 && mass_stage == "*10^23") && this->planetType_box->Text == "Rocky")
				|| ((System::Convert::ToDouble(this->box1->Text) > 59.7 && mass_stage == "*10^24") && this->planetType_box->Text == "Rocky")
				|| ((System::Convert::ToDouble(this->box1->Text) > 5.97 && mass_stage == "*10^25") && this->planetType_box->Text == "Rocky")
				|| ((System::Convert::ToDouble(this->box1->Text) > 0.597 && mass_stage == "*10^26") && this->planetType_box->Text == "Rocky")
				|| ((System::Convert::ToDouble(this->box1->Text) > 0.0597 && mass_stage == "*10^27") && this->planetType_box->Text == "Rocky")
				)
			{
				MessageBox::Show(this, "Your planet is too heavy to be rocky.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (
				((System::Convert::ToDouble(this->box1->Text) < 5970 && mass_stage == "*10^22") && this->planetType_box->Text == "Gas giant")
				|| ((System::Convert::ToDouble(this->box1->Text) < 597 && mass_stage == "*10^23") && this->planetType_box->Text == "Gas giant")
				|| ((System::Convert::ToDouble(this->box1->Text) < 59.7 && mass_stage == "*10^24") && this->planetType_box->Text == "Gas giant")
				|| ((System::Convert::ToDouble(this->box1->Text) < 5.97 && mass_stage == "*10^25") && this->planetType_box->Text == "Gas giant")
				|| ((System::Convert::ToDouble(this->box1->Text) < 0.597 && mass_stage == "*10^26") && this->planetType_box->Text == "Gas giant")
				|| ((System::Convert::ToDouble(this->box1->Text) < 0.0597 && mass_stage == "*10^27") && this->planetType_box->Text == "Gas giant")
				)
			{
				MessageBox::Show(this, "Your planet is too light to be gas giant.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (
				((System::Convert::ToDouble(this->box1->Text) > 9500000 && mass_stage == "*10^22"))
				|| ((System::Convert::ToDouble(this->box1->Text) > 950000 && mass_stage == "*10^23"))
				|| ((System::Convert::ToDouble(this->box1->Text) > 95000 && mass_stage == "*10^24"))
				|| ((System::Convert::ToDouble(this->box1->Text) > 9500 && mass_stage == "*10^25"))
				|| ((System::Convert::ToDouble(this->box1->Text) > 950 && mass_stage == "*10^26"))
				|| ((System::Convert::ToDouble(this->box1->Text) > 95 && mass_stage == "*10^27"))
				)
			{
				MessageBox::Show(this, "This body is too heavy to be planet.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else
			{
				mass = msclr::interop::marshal_as<std::string>(this->box1->Text);
			}


			std::string radius;
			if (System::Convert::ToDouble(this->textBox_radius->Text) < 1800)
			{
				MessageBox::Show(this, "Planet is too small!!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (System::Convert::ToDouble(this->textBox_radius->Text) < (3900 / 2)) {
				System::Windows::Forms::DialogResult MBoxresult = MessageBox::Show(this, "Radius of your planet is smaller then radius of the smallest known planet. Are you sure about this?",
					"Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Information);
				if (MBoxresult == System::Windows::Forms::DialogResult::Yes) {
					radius = msclr::interop::marshal_as<std::string>(this->textBox_radius->Text);
				}
				else if (MBoxresult == System::Windows::Forms::DialogResult::No || MBoxresult == System::Windows::Forms::DialogResult::Ignore)
				{
					return;
				}
			}
			else if (System::Convert::ToDouble(this->textBox_radius->Text) > 9500 && this->planetType_box->Text == "Rocky")
			{
				MessageBox::Show(this, "Radius of your planet is too large to be rocky planet", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (System::Convert::ToDouble(this->textBox_radius->Text) < 9500 && this->planetType_box->Text == "Gas giant")
			{
				 System::Windows::Forms::DialogResult MBoxresult = MessageBox::Show(this, "Radius of your planet is smaller then the smallest gas giant known. Are you sure?",
					"Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
				 if (MBoxresult == System::Windows::Forms::DialogResult::Yes)
				 {
					 radius = msclr::interop::marshal_as<std::string>(this->textBox_radius->Text);
				 } 
				 else if(MBoxresult == System::Windows::Forms::DialogResult::No)
				 {
					 return;
				 }
			}

			else if (System::Convert::ToDouble(this->textBox_radius->Text) > 100000)
			{
				MessageBox::Show(this, "Radius of your planet is too large to be planet", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else if (System::Convert::ToDouble(this->textBox_radius->Text) > 86000 && this->planetType_box->Text == "Gas giant")
			{
				System::Windows::Forms::DialogResult MBoxresult = MessageBox::Show(this, "Radius of your planet is bigger then the biggest gas giant known. Are you sure?",
					"Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
				if (MBoxresult == System::Windows::Forms::DialogResult::Yes)
				{
					radius = msclr::interop::marshal_as<std::string>(this->textBox_radius->Text);
				}
				else if (MBoxresult == System::Windows::Forms::DialogResult::No)
				{
					return;
				}
			}
			else
			{
				radius = msclr::interop::marshal_as<std::string>(this->textBox_radius->Text);
			}

			std::string planet_Type;
			if (this->planetType_box->Text != "Rocky" || this->planetType_box->Text != "Gas giant")
			{
				MessageBox::Show(this, "Enter valid planet type.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			} 
			else
			{
				planet_Type = msclr::interop::marshal_as<std::string>(this->planetType_box->Text);
			}
			

			std::string surf_temp;
			if (System::Convert::ToInt32(this->textBox_temp->Text) <= 0) {
				MessageBox::Show(this, "Tempreture can't be below 0 Kelvins", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else {
				surf_temp = msclr::interop::marshal_as<std::string>(this->textBox_temp->Text);
			}

			this->textBox_name->Text = "";
			this->comboBox_type->Text = "";
			this->box1->Text = "";
			this->textBox_radius->Text = "";
			this->planetType_box->Text = "";
			this->textBox_temp->Text = "";
			this->comboBox_mass->Text = "";

			insert_Data_Planet(db_path, name, mass, mass_stage, radius, planet_Type, surf_temp);
		}
		else if (NebType == "Star") {

			std::string name;
			if (!this->textBox_name->Text)
			{
				MessageBox::Show(this, "Enter celestial's name!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else
			{
				name = msclr::interop::marshal_as<std::string>(this->textBox_name->Text);
			}

			std::string mass = msclr::interop::marshal_as<std::string>(this->box1->Text);

			std::string radius = msclr::interop::marshal_as<std::string>(this->textBox_radius->Text);

			std::string blesk;
			if (System::Convert::ToInt16(this->blesk->Text) > 15 || System::Convert::ToInt16(this->blesk->Text) < -12)
			{
				MessageBox::Show(this, "Absolute magnitude of the star must be in the (-12, 15) interval.", "Enter error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			} 
			else
			{
				blesk = msclr::interop::marshal_as<std::string>(this->blesk->Text);
			}

			std::string surf_temp;
			if (System::Convert::ToInt32(this->textBox_temp->Text) <= 298) {
				MessageBox::Show(this, "Tempreture of the star can't be below 298 Kelvins", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else {
				surf_temp = msclr::interop::marshal_as<std::string>(this->textBox_temp->Text);
			}

			this->textBox_name->Text = "";
			this->blesk->Text = "";
			this->textBox_temp->Text = "";
			this->textBox_radius->Text = "";
			this->box1->Text = "";

			insert_Data_Star(db_path, name, mass, radius, blesk, surf_temp);
		}

	}

};
}
