#pragma once
#include <string>
#include <sqlite3.h>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <vector>
#include <vcclr.h>

namespace Astrolib {

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct Planet {
		std::string name;
		double mass;
		std::string mass_stage;
		double radius;
		std::string planet_type;
		double surf_temp;

	};

	ref class PlanetWrapper {
	private:
		Planet* data;
	public:
		PlanetWrapper() {
			data = new Planet();
		}
		~PlanetWrapper() {
			delete data;
		}

		void SetName(System::String^ name) {
			data->name = msclr::interop::marshal_as<std::string>(name);
		}
		System::String^ GetName() {
			return gcnew System::String(data->name.c_str());
		}

		void SetMass(double mass) {
			data->mass = mass;
		}
		double GetMass() {
			return data->mass;
		}

		void SetMassStage(System::String^ mass_stage) {
			data->mass_stage = msclr::interop::marshal_as<std::string>(mass_stage);
		}
		System::String^ GetMassStage() {
			return gcnew System::String(data->mass_stage.c_str());
		}

		void SetRadius(double radius) {
			data->radius = radius;
		}
		double GetRadius() {
			return data->radius;
		}

		void SetPlanetType(System::String^ planet_type) {
			data->planet_type = msclr::interop::marshal_as<std::string>(planet_type);
		}
		System::String^ GetPlanetType() {
			return gcnew System::String(data->planet_type.c_str());
		}

		void SetSurfaceTemperature(double surface_temperature) {
			data->surf_temp = surface_temperature;
		}
		double GetSurfaceTemperature() {
			return data->surf_temp;
		}

		static std::vector<gcroot<PlanetWrapper^>> GetPlanets(const char* db_path) {
			sqlite3* DB;
			sqlite3_stmt* stmt;
			std::vector<gcroot<PlanetWrapper^>> planets;
			int rc = sqlite3_open(db_path, &DB);
			if (rc != SQLITE_OK) {
				MessageBox::Show(gcnew System::String(sqlite3_errmsg(DB)), "Error opening database");
				return planets;
			}
			std::string sql = "SELECT name, mass, mass_stage, radius, planet_type, surface_temperature FROM Planets;";
			rc = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, nullptr);
			if (rc != SQLITE_OK) {
				MessageBox::Show(gcnew System::String(sqlite3_errmsg(DB)), "Error preparing statement");
				sqlite3_close(DB);
				return planets;
			}
			while (sqlite3_step(stmt) == SQLITE_ROW) {
				PlanetWrapper^ planet = gcnew PlanetWrapper();
				planet->SetName(gcnew System::String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
				planet->SetMass(sqlite3_column_double(stmt, 1));
				planet->SetMassStage(gcnew System::String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))));
				planet->SetRadius(sqlite3_column_double(stmt, 3));
				planet->SetPlanetType(gcnew System::String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4))));
				planet->SetSurfaceTemperature(sqlite3_column_double(stmt, 5));
				planets.push_back(planet);
			}
			sqlite3_finalize(stmt);
			sqlite3_close(DB);
			return planets;
		}
	};

	struct Star {
		std::string name;
		double mass;
		double radius;
		double magnitude;
		double temperature;
	};
	ref class StarWrapper {
	private:
		Star* data;

	public:
		StarWrapper() {
			data = new Star();
		}

		~StarWrapper() {
			delete data;
		}

		void SetName(System::String^ name) {
			data->name = msclr::interop::marshal_as<std::string>(name);
		}

		System::String^ GetName() {
			return gcnew System::String(data->name.c_str());
		}

		void SetMass(double mass) {
			data->mass = mass;
		}

		double GetMass() {
			return data->mass;
		}

		void SetRadius(double radius) {
			data->radius = radius;
		}

		double GetRadius() {
			return data->radius;
		}

		void SetMagnitude(double magnitude) {
			data->magnitude = magnitude;
		}

		double GetMagnitude() {
			return data->magnitude;
		}

		void SetTemperature(double temperature) {
			data->temperature = temperature;
		}

		double GetTemperature() {
			return data->temperature;
		}

		static std::vector<gcroot<StarWrapper^>> GetStars(const char* db_path) {
			sqlite3* DB;
			sqlite3_stmt* stmt;
			std::vector<gcroot<StarWrapper^>> stars;

			int rc = sqlite3_open(db_path, &DB);
			if (rc != SQLITE_OK) {
				MessageBox::Show(gcnew System::String(sqlite3_errmsg(DB)), "Error opening database");
				return stars;
			}

			std::string sql = "SELECT name, mass, radius, absolute_magnitude, surface_temperature FROM Stars;";
			rc = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, nullptr);

			if (rc != SQLITE_OK) {
				MessageBox::Show(gcnew System::String(sqlite3_errmsg(DB)), "Error preparing statement");
				sqlite3_close(DB);
				return stars;
			}

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				StarWrapper^ star = gcnew StarWrapper();
				star->SetName(gcnew System::String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
				star->SetMass(sqlite3_column_double(stmt, 1));
				star->SetRadius(sqlite3_column_double(stmt, 2));
				star->SetMagnitude(sqlite3_column_double(stmt, 3));
				star->SetTemperature(sqlite3_column_double(stmt, 4));
				stars.push_back(star);
			}

			sqlite3_finalize(stmt);
			sqlite3_close(DB);
			return stars;
		}
	};


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class List : public System::Windows::Forms::Form
	{
	public:
		List(void)
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
		~List()
		{
			if (components)
			{
				delete components;
			}
		}
	private: void AdjustDataGridViewSize(DataGridView^ dataGridView) {
		int minHeight = 100;
		int maxHeight = 330;
		int rowHeight = dataGridView->RowTemplate->Height; 
		int rowCount = dataGridView->Rows->Count;

		int newHeight = (rowCount * rowHeight) + dataGridView->ColumnHeadersHeight;

		if (newHeight < minHeight) {
			newHeight = minHeight;
		}
		else if (newHeight > maxHeight) {
			newHeight = maxHeight;
		}

		dataGridView->Height = newHeight;
	}


	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button_toMain;
	private: System::Windows::Forms::Button^ button_addP;
	private: System::Windows::Forms::Button^ button_addS;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button_toMain = (gcnew System::Windows::Forms::Button());
			this->button_addP = (gcnew System::Windows::Forms::Button());
			this->button_addS = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button_exit
			// 
			this->button_exit->BackColor = System::Drawing::Color::Red;
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_exit->ForeColor = System::Drawing::Color::White;
			this->button_exit->Location = System::Drawing::Point(1423, 15);
			this->button_exit->Margin = System::Windows::Forms::Padding(4);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(55, 50);
			this->button_exit->TabIndex = 1;
			this->button_exit->Text = L"X";
			this->button_exit->UseVisualStyleBackColor = false;
			this->button_exit->Click += gcnew System::EventHandler(this, &List::button_exit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(518, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(543, 42);
			this->label1->TabIndex = 2;
			this->label1->Text = L"LIST OF CELESTIAL BODIES";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(75, 150);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 50;
			this->dataGridView1->RowTemplate->Height = 30;
			this->dataGridView1->Size = System::Drawing::Size(600, 220);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			// 
			// button_toMain
			// 
			this->button_toMain->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold));
			this->button_toMain->Location = System::Drawing::Point(1100, 153);
			this->button_toMain->Name = L"button_toMain";
			this->button_toMain->Size = System::Drawing::Size(150, 80);
			this->button_toMain->TabIndex = 22;
			this->button_toMain->Text = L"Back";
			this->button_toMain->UseVisualStyleBackColor = true;
			this->button_toMain->Click += gcnew System::EventHandler(this, &List::button_toMain_Click);
			// 
			// button_addP
			// 
			this->button_addP->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold));
			this->button_addP->Location = System::Drawing::Point(1100, 344);
			this->button_addP->Name = L"button_addP";
			this->button_addP->Size = System::Drawing::Size(150, 80);
			this->button_addP->TabIndex = 23;
			this->button_addP->Text = L"Planets";
			this->button_addP->UseVisualStyleBackColor = true;
			this->button_addP->Click += gcnew System::EventHandler(this, &List::button_addP_Click);
			// 
			// button_addS
			// 
			this->button_addS->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold));
			this->button_addS->Location = System::Drawing::Point(1100, 535);
			this->button_addS->Name = L"button_addS";
			this->button_addS->Size = System::Drawing::Size(150, 80);
			this->button_addS->TabIndex = 24;
			this->button_addS->Text = L"Stars";
			this->button_addS->UseVisualStyleBackColor = true;
			this->button_addS->Click += gcnew System::EventHandler(this, &List::button_addS_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(75, 150);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 50;
			this->dataGridView2->RowTemplate->Height = 30;
			this->dataGridView2->Size = System::Drawing::Size(600, 220);
			this->dataGridView2->TabIndex = 25;
			this->dataGridView2->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			// 
			// List
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
				static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->ClientSize = System::Drawing::Size(1493, 775);
			this->Controls->Add(this->button_addS);
			this->Controls->Add(this->button_addP);
			this->Controls->Add(this->button_toMain);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_exit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"List";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"List";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		Application::Exit();
	}
	private: System::Void button_toMain_Click(System::Object^ sender, System::EventArgs^ e) {
		Owner->Show();
		this->Close();
	}
private: System::Void button_addP_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Controls->Remove(dataGridView2);
	this->Controls->Add(dataGridView1);
	const char* db_path = "Stars.db";
	std::vector<gcroot<PlanetWrapper^>> planets = PlanetWrapper::GetPlanets(db_path);

	this->dataGridView1->Rows->Clear();
	this->dataGridView1->Columns->Clear();

	this->dataGridView1->Columns->Add("Name", "Name");
	this->dataGridView1->Columns->Add("Mass", "Mass, KG");
	this->dataGridView1->Columns->Add("MassStage", "Mass Stage");
	this->dataGridView1->Columns->Add("Radius", "Radius, KM");
	this->dataGridView1->Columns->Add("PlanetType", "Planet Type");
	this->dataGridView1->Columns->Add("SurfaceTemp", "Surface Temperature, K");

	for (auto& planet : planets) {
		this->dataGridView1->Rows->Add(
			planet->GetName(),
			planet->GetMass(),
			planet->GetMassStage(),
			planet->GetRadius(),
			planet->GetPlanetType(),
			planet->GetSurfaceTemperature()
		);
	}
	AdjustDataGridViewSize(this->dataGridView1);
}

private: System::Void button_addS_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Controls->Remove(dataGridView1);
	this->Controls->Add(dataGridView2);
	const char* db_path = "Stars.db";
	std::vector<gcroot<StarWrapper^>> stars = StarWrapper::GetStars(db_path);

	this->dataGridView2->Rows->Clear();
	this->dataGridView2->Columns->Clear();

	this->dataGridView2->Columns->Add("Name", "Name");
	this->dataGridView2->Columns->Add("Mass", "Mass, Ms");
	this->dataGridView2->Columns->Add("Radius", "Radius, Rs");
	this->dataGridView2->Columns->Add("Magnitude", "Magnitude");
	this->dataGridView2->Columns->Add("Temperature", "Temperature, K");

	for (auto& star : stars) {
		this->dataGridView2->Rows->Add(
			star->GetName(),
			star->GetMass(),
			star->GetRadius(),
			star->GetMagnitude(),
			star->GetTemperature()
		);
	}
	AdjustDataGridViewSize(this->dataGridView2);
}
};
}
