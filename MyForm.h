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
	private: System::Windows::Forms::TextBox^ txtItemName;
	private: System::Windows::Forms::ComboBox^ cmbCategory;
	private: System::Windows::Forms::NumericUpDown^ numQuantity;
	private: System::Windows::Forms::TextBox^ txtUnitPrice;
	private: System::Windows::Forms::Button^ btnAddItem;
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
			this->txtItemName = (gcnew System::Windows::Forms::TextBox());
			this->cmbCategory = (gcnew System::Windows::Forms::ComboBox());
			this->numQuantity = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtUnitPrice = (gcnew System::Windows::Forms::TextBox());
			this->btnAddItem = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInventory))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuantity))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(999, 618);
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
			this->dataGridViewInventory->Size = System::Drawing::Size(1004, 291);
			this->dataGridViewInventory->TabIndex = 1;
			// 
			// txtItemName
			// 
			this->txtItemName->Location = System::Drawing::Point(34, 367);
			this->txtItemName->Name = L"txtItemName";
			this->txtItemName->Size = System::Drawing::Size(151, 22);
			this->txtItemName->TabIndex = 2;
			// 
			// cmbCategory
			// 
			this->cmbCategory->FormattingEnabled = true;
			this->cmbCategory->Location = System::Drawing::Point(34, 408);
			this->cmbCategory->Name = L"cmbCategory";
			this->cmbCategory->Size = System::Drawing::Size(151, 24);
			this->cmbCategory->TabIndex = 3;
			// 
			// numQuantity
			// 
			this->numQuantity->Location = System::Drawing::Point(34, 456);
			this->numQuantity->Name = L"numQuantity";
			this->numQuantity->Size = System::Drawing::Size(151, 22);
			this->numQuantity->TabIndex = 4;
			// 
			// txtUnitPrice
			// 
			this->txtUnitPrice->Location = System::Drawing::Point(34, 496);
			this->txtUnitPrice->Name = L"txtUnitPrice";
			this->txtUnitPrice->Size = System::Drawing::Size(151, 22);
			this->txtUnitPrice->TabIndex = 5;
			// 
			// btnAddItem
			// 
			this->btnAddItem->Location = System::Drawing::Point(61, 540);
			this->btnAddItem->Name = L"btnAddItem";
			this->btnAddItem->Size = System::Drawing::Size(87, 33);
			this->btnAddItem->TabIndex = 6;
			this->btnAddItem->Text = L"button1";
			this->btnAddItem->UseVisualStyleBackColor = true;
			this->btnAddItem->Click += gcnew System::EventHandler(this, &MyForm::btnAddItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1055, 643);
			this->Controls->Add(this->btnAddItem);
			this->Controls->Add(this->txtUnitPrice);
			this->Controls->Add(this->numQuantity);
			this->Controls->Add(this->cmbCategory);
			this->Controls->Add(this->txtItemName);
			this->Controls->Add(this->dataGridViewInventory);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInventory))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuantity))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void LoadInventoryData() {
		DatabaseManager^ dbManager = gcnew DatabaseManager();
		DataTable^ dt = dbManager->GetInventoryData();
		dataGridViewInventory->DataSource = dt;
	}
	
	 private: System::Void LoadCategories() {
		DatabaseManager^ dbManager = gcnew DatabaseManager();
		DataTable^ dt = dbManager->GetCategories();

		cmbCategory->DataSource = dt;
		cmbCategory->DisplayMember = "CategoryName";
		cmbCategory->ValueMember = "CategoryID";
	}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadInventoryData();
		LoadCategories();
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

		
	private: System::Void btnAddItem_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ itemName = txtItemName->Text;
		int categoryId = Convert::ToInt32(cmbCategory->SelectedValue);
		int quantity = Convert::ToInt32(numQuantity->Value);
		double unitPrice = Convert::ToDouble(txtUnitPrice->Text);

		if (String::IsNullOrEmpty(itemName) || categoryId <= 0 || quantity <= 0 || unitPrice <= 0) {
			MessageBox::Show("Lütfen tüm alanları eksiksiz ve doğru giriniz!", "Uyarı", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		DatabaseManager^ dbManager = gcnew DatabaseManager();
		bool success = dbManager->AddNewItem(itemName, categoryId, quantity, unitPrice);

		if (success) {
			MessageBox::Show("Ürün başarıyla eklendi!", "Bilgi", MessageBoxButtons::OK, MessageBoxIcon::Information);
			LoadInventoryData();  // **Ekleme sonrası DataGridView'i güncelle**
		}
		else {
			MessageBox::Show("Ürün eklenirken hata oluştu.", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
