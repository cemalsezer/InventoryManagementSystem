#pragma once
#include "DatabaseManager.h" 

namespace InventoryManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridViewInventory;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewInventory = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInventory))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(645, 449);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// dataGridViewInventory
			// 
			this->dataGridViewInventory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewInventory->Location = System::Drawing::Point(25, 24);
			this->dataGridViewInventory->Name = L"dataGridViewInventory";
			this->dataGridViewInventory->RowHeadersWidth = 51;
			this->dataGridViewInventory->RowTemplate->Height = 24;
			this->dataGridViewInventory->Size = System::Drawing::Size(685, 300);
			this->dataGridViewInventory->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(722, 490);
			this->Controls->Add(this->dataGridViewInventory);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInventory))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void LoadInventoryData() {
		DatabaseManager^ dbManager = gcnew DatabaseManager();
		DataTable^ dt = dbManager->GetInventoryData();
		dataGridViewInventory->DataSource = dt;
	}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadInventoryData();
		DatabaseManager^ dbManager = gcnew DatabaseManager();

		if (dbManager->OpenConnection()) {
			label1->Text = "Baglanti basarili!";
			label1->ForeColor = System::Drawing::Color::Green;
		}
		else {
			label1->Text = "Baglanti basarisiz!";
			label1->ForeColor = System::Drawing::Color::Red;
		}
	}

		
	};
}
