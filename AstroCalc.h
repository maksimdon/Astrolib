#pragma once
#include <cmath>

namespace Astrolib {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AstroCalc : public System::Windows::Forms::Form
	{
	public:
		AstroCalc(void)
		{
			InitializeComponent();
		}

	protected:
		~AstroCalc()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_calculate;
	private: System::Windows::Forms::ComboBox^ formulas;

	private: System::Windows::Forms::TextBox^ box1;
	private: System::Windows::Forms::TextBox^ box2;


	private: System::Windows::Forms::Label^ label_mass;
	private: System::Windows::Forms::Label^ label_radius;
	private: System::Windows::Forms::TextBox^ textBox_result;
	private: System::Windows::Forms::Label^ label_result;

	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Label^ label_mass2;
	private: System::Windows::Forms::TextBox^ box3;

	private: double G = 6.67 * pow(10, -11);

	private: void InitializeComponent(void)
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AstroCalc::typeid));
		this->button_exit = (gcnew System::Windows::Forms::Button());
		this->button_calculate = (gcnew System::Windows::Forms::Button());
		this->formulas = (gcnew System::Windows::Forms::ComboBox());
		this->box1 = (gcnew System::Windows::Forms::TextBox());
		this->box2 = (gcnew System::Windows::Forms::TextBox());
		this->label_mass = (gcnew System::Windows::Forms::Label());
		this->label_radius = (gcnew System::Windows::Forms::Label());
		this->textBox_result = (gcnew System::Windows::Forms::TextBox());
		this->label_result = (gcnew System::Windows::Forms::Label());
		this->label_mass2 = (gcnew System::Windows::Forms::Label());
		this->box3 = (gcnew System::Windows::Forms::TextBox());
		this->SuspendLayout();
		// 
		// button_exit
		// 
		this->button_exit->Location = System::Drawing::Point(20, 20);
		this->button_exit->Name = L"button_exit";
		this->button_exit->Size = System::Drawing::Size(75, 30);
		this->button_exit->TabIndex = 0;
		this->button_exit->Text = L"Exit";
		this->button_exit->Click += gcnew System::EventHandler(this, &AstroCalc::button_exit_Click);
		// 
		// button_calculate
		// 
		this->button_calculate->Location = System::Drawing::Point(170, 290);
		this->button_calculate->Name = L"button_calculate";
		this->button_calculate->Size = System::Drawing::Size(100, 30);
		this->button_calculate->TabIndex = 1;
		this->button_calculate->Text = L"Calculate";
		this->button_calculate->Click += gcnew System::EventHandler(this, &AstroCalc::button_calculate_Click);
		// 
		// formulas
		// 
		this->formulas->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
			L"First Cosmic Velocity", L"Second Cosmic Velocity",
				L"Third Cosmic Velocity", L"Gravity acceleration"
		});
		this->formulas->Location = System::Drawing::Point(150, 20);
		this->formulas->Name = L"formulas";
		this->formulas->Size = System::Drawing::Size(200, 24);
		this->formulas->TabIndex = 2;
		// 
		// box1
		// 
		this->box1->Location = System::Drawing::Point(150, 100);
		this->box1->Name = L"box1";
		this->box1->Size = System::Drawing::Size(200, 22);
		this->box1->TabIndex = 3;
		this->box1->Text = L"Enter mass (kg x 10^24)";
		// 
		// box2
		// 
		this->box2->Location = System::Drawing::Point(150, 60);
		this->box2->Name = L"box2";
		this->box2->Size = System::Drawing::Size(200, 22);
		this->box2->TabIndex = 4;
		this->box2->Text = L"Enter radius (km)";
		// 
		// label_mass
		// 
		this->label_mass->Location = System::Drawing::Point(20, 100);
		this->label_mass->Name = L"label_mass";
		this->label_mass->Size = System::Drawing::Size(120, 30);
		this->label_mass->TabIndex = 5;
		this->label_mass->Text = L"Mass:";
		// 
		// label_radius
		// 
		this->label_radius->Location = System::Drawing::Point(20, 60);
		this->label_radius->Name = L"label_radius";
		this->label_radius->Size = System::Drawing::Size(120, 30);
		this->label_radius->TabIndex = 6;
		this->label_radius->Text = L"Radius:";
		// 
		// textBox_result
		// 
		this->textBox_result->Location = System::Drawing::Point(150, 240);
		this->textBox_result->Name = L"textBox_result";
		this->textBox_result->ReadOnly = true;
		this->textBox_result->Size = System::Drawing::Size(200, 22);
		this->textBox_result->TabIndex = 7;
		// 
		// label_result
		// 
		this->label_result->Location = System::Drawing::Point(20, 240);
		this->label_result->Name = L"label_result";
		this->label_result->Size = System::Drawing::Size(120, 30);
		this->label_result->TabIndex = 8;
		this->label_result->Text = L"Result:";
		// 
		// label_mass2
		// 
		this->label_mass2->Location = System::Drawing::Point(20, 140);
		this->label_mass2->Name = L"label_mass2";
		this->label_mass2->Size = System::Drawing::Size(120, 30);
		this->label_mass2->TabIndex = 9;
		this->label_mass2->Text = L"Mass(2):";
		// 
		// box3
		// 
		this->box3->Location = System::Drawing::Point(150, 140);
		this->box3->Name = L"box3";
		this->box3->Size = System::Drawing::Size(200, 22);
		this->box3->TabIndex = 10;
		this->box3->Text = L"Enter mass (kg x 10^24)";
		// 
		// AstroCalc
		// 
		this->ClientSize = System::Drawing::Size(422, 343);
		this->Controls->Add(this->box3);
		this->Controls->Add(this->label_mass2);
		this->Controls->Add(this->button_exit);
		this->Controls->Add(this->button_calculate);
		this->Controls->Add(this->formulas);
		this->Controls->Add(this->box1);
		this->Controls->Add(this->box2);
		this->Controls->Add(this->label_mass);
		this->Controls->Add(this->label_radius);
		this->Controls->Add(this->textBox_result);
		this->Controls->Add(this->label_result);
		this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		this->Name = L"AstroCalc";
		this->Text = L"Astronomical Calculator";
		this->ResumeLayout(false);
		this->PerformLayout();

	}

	private: void button_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: void button_calculate_Click(System::Object^ sender, System::EventArgs^ e) {
		double mass = Convert::ToDouble(this->box1->Text) * 1e24; 
		double radius = Convert::ToDouble(this->box2->Text) * 1000;
		double mass2 = 0.0;
		double result = 0.0;

		if (this->formulas->SelectedItem->ToString() == "First Cosmic Velocity") {
			result = sqrt(9.81 * radius);
		}
		else if (this->formulas->SelectedItem->ToString() == "Second Cosmic Velocity") {
			result = sqrt((2 * 9.81 * radius)); 
		}
		else if (this->formulas->SelectedItem->ToString() == "Third Cosmic Velocity") {
			result = sqrt((3 * 9.81 * radius)); 
		}
		else if (this->formulas->SelectedItem->ToString() == "Gravity acceleration") {
			result = (G * (mass - mass2)) / pow(radius, 2);
		}

		this->textBox_result->Text = Math::Round(result, 4).ToString() + " m/s";
	}
};
}
