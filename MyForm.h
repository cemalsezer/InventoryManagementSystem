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
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->dataGridViewInventory->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridViewInventory_CellClick);

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
	private: System::Windows::Forms::TextBox^ txtItemID;
	private: System::Windows::Forms::Button^ btnUpdateItem;
	private: System::Windows::Forms::Button^ btnDeleteItem;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::ComboBox^ cmbFilterCategory;
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
			this->txtItemID = (gcnew System::Windows::Forms::TextBox());
			this->btnUpdateItem = (gcnew System::Windows::Forms::Button());
			this->btnDeleteItem = (gcnew System::Windows::Forms::Button());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->cmbFilterCategory = (gcnew System::Windows::Forms::ComboBox());
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
			this->btnAddItem->Location = System::Drawing::Point(52, 541);
			this->btnAddItem->Name = L"btnAddItem";
			this->btnAddItem->Size = System::Drawing::Size(109, 33);
			this->btnAddItem->TabIndex = 6;
			this->btnAddItem->Text = L"Product Add";
			this->btnAddItem->UseVisualStyleBackColor = true;
			this->btnAddItem->Click += gcnew System::EventHandler(this, &MyForm::btnAddItem_Click);
			// 
			// txtItemID
			// 
			this->txtItemID->Location = System::Drawing::Point(287, 367);
			this->txtItemID->Name = L"txtItemID";
			this->txtItemID->Size = System::Drawing::Size(122, 22);
			this->txtItemID->TabIndex = 7;
			// 
			// btnUpdateItem
			// 
			this->btnUpdateItem->Location = System::Drawing::Point(287, 468);
			this->btnUpdateItem->Name = L"btnUpdateItem";
			this->btnUpdateItem->Size = System::Drawing::Size(124, 31);
			this->btnUpdateItem->TabIndex = 8;
			this->btnUpdateItem->Text = L"Update";
			this->btnUpdateItem->UseVisualStyleBackColor = true;
			this->btnUpdateItem->Click += gcnew System::EventHandler(this, &MyForm::btnUpdateItem_Click);
			// 
			// btnDeleteItem
			// 
			this->btnDeleteItem->Location = System::Drawing::Point(287, 518);
			this->btnDeleteItem->Name = L"btnDeleteItem";
			this->btnDeleteItem->Size = System::Drawing::Size(124, 30);
			this->btnDeleteItem->TabIndex = 9;
			this->btnDeleteItem->Text = L"Delete";
			this->btnDeleteItem->UseVisualStyleBackColor = true;
			this->btnDeleteItem->Click += gcnew System::EventHandler(this, &MyForm::btnDeleteItem_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(590, 376);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(100, 22);
			this->txtSearch->TabIndex = 10;
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(603, 434);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(75, 23);
			this->btnSearch->TabIndex = 11;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &MyForm::btnSearch_Click);
			// 
			// cmbFilterCategory
			// 
			this->cmbFilterCategory->FormattingEnabled = true;
			this->cmbFilterCategory->Location = System::Drawing::Point(590, 405);
			this->cmbFilterCategory->Name = L"cmbFilterCategory";
			this->cmbFilterCategory->Size = System::Drawing::Size(121, 24);
			this->cmbFilterCategory->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1055, 643);
			this->Controls->Add(this->cmbFilterCategory);
			this->Controls->Add(this->btnSearch);
			this->Controls->Add(this->txtSearch);
			this->Controls->Add(this->btnDeleteItem);
			this->Controls->Add(this->btnUpdateItem);
			this->Controls->Add(this->txtItemID);
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
		LoadFilterCategories();
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
		private: System::Void btnUpdateItem_Click(System::Object^ sender, System::EventArgs^ e) {

			int itemID = Convert::ToInt32(txtItemID->Text);
			String^ itemName = txtItemName->Text;
			int categoryId = Convert::ToInt32(cmbCategory->SelectedValue);
			int quantity = Convert::ToInt32(numQuantity->Value);
			double unitPrice = Convert::ToDouble(txtUnitPrice->Text);

			if (String::IsNullOrEmpty(itemName) || categoryId <= 0 || quantity <= 0 || unitPrice <= 0) {
				MessageBox::Show("Lütfen tüm alanları eksiksiz ve doğru giriniz!", "Uyarı", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			DatabaseManager^ dbManager = gcnew DatabaseManager();
			bool success = dbManager->UpdateItem(itemID, itemName, categoryId, quantity, unitPrice);

			if (success) {
				MessageBox::Show("Ürün başarıyla güncellendi!", "Bilgi", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadInventoryData();  // **Güncelleme sonrası DataGridView'i yenile**
			}
			else {
				MessageBox::Show("Ürün güncellenirken hata oluştu.", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: System::Void dataGridViewInventory_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0) {  // Eğer geçerli bir satır tıklandıysa
				DataGridViewRow^ row = dataGridViewInventory->Rows[e->RowIndex];

				txtItemID->Text = row->Cells["ItemID"]->Value->ToString();  // **Gizli ID**
				txtItemName->Text = row->Cells["ItemName"]->Value->ToString();
				cmbCategory->Text = row->Cells["CategoryName"]->Value->ToString();
				numQuantity->Value = Convert::ToInt32(row->Cells["Quantity"]->Value);
				txtUnitPrice->Text = row->Cells["UnitPrice"]->Value->ToString();
			}
		}

		private: System::Void btnDeleteItem_Click(System::Object^ sender, System::EventArgs^ e) {
			if (String::IsNullOrEmpty(txtItemID->Text)) {
				MessageBox::Show("Lütfen silmek için bir ürün seçin!", "Uyarı", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int itemID = Convert::ToInt32(txtItemID->Text);

			// Kullanıcıdan silme işlemi için onay alalım
			System::Windows::Forms::DialogResult result = MessageBox::Show(
				"Bu ürünü silmek istediğinizden emin misiniz?", "Ürün Silme",
				MessageBoxButtons::YesNo, MessageBoxIcon::Warning
			);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				DatabaseManager^ dbManager = gcnew DatabaseManager();
				bool success = dbManager->DeleteItem(itemID);

				if (success) {
					MessageBox::Show("Ürün başarıyla silindi!", "Bilgi", MessageBoxButtons::OK, MessageBoxIcon::Information);
					LoadInventoryData();  // **Silme sonrası DataGridView'i yenile**
				}
				else {
					MessageBox::Show("Ürün silinirken hata oluştu.", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
		private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ searchQuery = txtSearch->Text;
			int categoryId = (cmbFilterCategory->SelectedIndex > 0) ? Convert::ToInt32(cmbFilterCategory->SelectedValue) : 0;

			DatabaseManager^ dbManager = gcnew DatabaseManager();
			DataTable^ dt = dbManager->SearchItems(searchQuery, categoryId);

			dataGridViewInventory->DataSource = dt;
		}

		private: System::Void LoadFilterCategories() {
			DatabaseManager^ dbManager = gcnew DatabaseManager();
			DataTable^ dt = dbManager->GetCategories();

			DataRow^ newRow = dt->NewRow();
			newRow["CategoryID"] = 0;
			newRow["CategoryName"] = "Tümü";
			dt->Rows->InsertAt(newRow, 0);

			cmbFilterCategory->DataSource = dt;
			cmbFilterCategory->DisplayMember = "CategoryName";
			cmbFilterCategory->ValueMember = "CategoryID";
		}
};
}
