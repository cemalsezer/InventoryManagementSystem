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
	private: System::Windows::Forms::NumericUpDown^ numLowStockThreshold;
	private: System::Windows::Forms::Button^ btnLowStockReport;
	private: System::Windows::Forms::DataGridView^ dataGridViewLowStock;

	private: System::Windows::Forms::Button^ btnExportCSV;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
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
			this->numLowStockThreshold = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnLowStockReport = (gcnew System::Windows::Forms::Button());
			this->dataGridViewLowStock = (gcnew System::Windows::Forms::DataGridView());
			this->btnExportCSV = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewInventory))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQuantity))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numLowStockThreshold))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLowStock))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(879, 830);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// dataGridViewInventory
			// 
			this->dataGridViewInventory->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewInventory->Location = System::Drawing::Point(50, 231);
			this->dataGridViewInventory->Name = L"dataGridViewInventory";
			this->dataGridViewInventory->RowHeadersWidth = 51;
			this->dataGridViewInventory->RowTemplate->Height = 24;
			this->dataGridViewInventory->Size = System::Drawing::Size(906, 320);
			this->dataGridViewInventory->TabIndex = 1;
			// 
			// txtItemName
			// 
			this->txtItemName->Location = System::Drawing::Point(50, 112);
			this->txtItemName->Name = L"txtItemName";
			this->txtItemName->Size = System::Drawing::Size(151, 22);
			this->txtItemName->TabIndex = 2;
			// 
			// cmbCategory
			// 
			this->cmbCategory->FormattingEnabled = true;
			this->cmbCategory->Location = System::Drawing::Point(261, 110);
			this->cmbCategory->Name = L"cmbCategory";
			this->cmbCategory->Size = System::Drawing::Size(151, 24);
			this->cmbCategory->TabIndex = 3;
			// 
			// numQuantity
			// 
			this->numQuantity->Location = System::Drawing::Point(484, 113);
			this->numQuantity->Name = L"numQuantity";
			this->numQuantity->Size = System::Drawing::Size(151, 22);
			this->numQuantity->TabIndex = 4;
			// 
			// txtUnitPrice
			// 
			this->txtUnitPrice->Location = System::Drawing::Point(726, 113);
			this->txtUnitPrice->Name = L"txtUnitPrice";
			this->txtUnitPrice->Size = System::Drawing::Size(151, 22);
			this->txtUnitPrice->TabIndex = 5;
			// 
			// btnAddItem
			// 
			this->btnAddItem->Location = System::Drawing::Point(52, 163);
			this->btnAddItem->Name = L"btnAddItem";
			this->btnAddItem->Size = System::Drawing::Size(109, 33);
			this->btnAddItem->TabIndex = 6;
			this->btnAddItem->Text = L"Product Add";
			this->btnAddItem->UseVisualStyleBackColor = true;
			this->btnAddItem->Click += gcnew System::EventHandler(this, &MyForm::btnAddItem_Click);
			// 
			// txtItemID
			// 
			this->txtItemID->Location = System::Drawing::Point(1090, 40);
			this->txtItemID->Name = L"txtItemID";
			this->txtItemID->Size = System::Drawing::Size(122, 22);
			this->txtItemID->TabIndex = 7;
			// 
			// btnUpdateItem
			// 
			this->btnUpdateItem->Location = System::Drawing::Point(261, 163);
			this->btnUpdateItem->Name = L"btnUpdateItem";
			this->btnUpdateItem->Size = System::Drawing::Size(124, 31);
			this->btnUpdateItem->TabIndex = 8;
			this->btnUpdateItem->Text = L"Update";
			this->btnUpdateItem->UseVisualStyleBackColor = true;
			this->btnUpdateItem->Click += gcnew System::EventHandler(this, &MyForm::btnUpdateItem_Click);
			// 
			// btnDeleteItem
			// 
			this->btnDeleteItem->Location = System::Drawing::Point(484, 163);
			this->btnDeleteItem->Name = L"btnDeleteItem";
			this->btnDeleteItem->Size = System::Drawing::Size(124, 30);
			this->btnDeleteItem->TabIndex = 9;
			this->btnDeleteItem->Text = L"Delete";
			this->btnDeleteItem->UseVisualStyleBackColor = true;
			this->btnDeleteItem->Click += gcnew System::EventHandler(this, &MyForm::btnDeleteItem_Click);
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(50, 28);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(143, 22);
			this->txtSearch->TabIndex = 10;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &MyForm::txtSearch_TextChanged);
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(484, 26);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(78, 26);
			this->btnSearch->TabIndex = 11;
			this->btnSearch->Text = L"Search";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &MyForm::btnSearch_Click);
			// 
			// cmbFilterCategory
			// 
			this->cmbFilterCategory->FormattingEnabled = true;
			this->cmbFilterCategory->Location = System::Drawing::Point(257, 28);
			this->cmbFilterCategory->Name = L"cmbFilterCategory";
			this->cmbFilterCategory->Size = System::Drawing::Size(155, 24);
			this->cmbFilterCategory->TabIndex = 12;
			// 
			// numLowStockThreshold
			// 
			this->numLowStockThreshold->Location = System::Drawing::Point(52, 588);
			this->numLowStockThreshold->Name = L"numLowStockThreshold";
			this->numLowStockThreshold->Size = System::Drawing::Size(120, 22);
			this->numLowStockThreshold->TabIndex = 13;
			// 
			// btnLowStockReport
			// 
			this->btnLowStockReport->Location = System::Drawing::Point(235, 588);
			this->btnLowStockReport->Name = L"btnLowStockReport";
			this->btnLowStockReport->Size = System::Drawing::Size(93, 23);
			this->btnLowStockReport->TabIndex = 14;
			this->btnLowStockReport->Text = L"Show Report";
			this->btnLowStockReport->UseVisualStyleBackColor = true;
			this->btnLowStockReport->Click += gcnew System::EventHandler(this, &MyForm::btnLowStockReport_Click);
			// 
			// dataGridViewLowStock
			// 
			this->dataGridViewLowStock->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewLowStock->Location = System::Drawing::Point(50, 644);
			this->dataGridViewLowStock->Name = L"dataGridViewLowStock";
			this->dataGridViewLowStock->RowHeadersWidth = 51;
			this->dataGridViewLowStock->RowTemplate->Height = 24;
			this->dataGridViewLowStock->Size = System::Drawing::Size(915, 163);
			this->dataGridViewLowStock->TabIndex = 15;
			// 
			// btnExportCSV
			// 
			this->btnExportCSV->Location = System::Drawing::Point(385, 587);
			this->btnExportCSV->Name = L"btnExportCSV";
			this->btnExportCSV->Size = System::Drawing::Size(92, 23);
			this->btnExportCSV->TabIndex = 16;
			this->btnExportCSV->Text = L"Export CSV";
			this->btnExportCSV->UseVisualStyleBackColor = true;
			this->btnExportCSV->Click += gcnew System::EventHandler(this, &MyForm::btnExportCSV_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(49, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 16);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Search Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(49, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 16);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Item Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(258, 91);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 16);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Category";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(481, 91);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 16);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Quantity";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(723, 91);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(64, 16);
			this->label6->TabIndex = 21;
			this->label6->Text = L"Unit Price";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(254, 9);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(108, 16);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Search Category";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1072, 855);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnExportCSV);
			this->Controls->Add(this->dataGridViewLowStock);
			this->Controls->Add(this->btnLowStockReport);
			this->Controls->Add(this->numLowStockThreshold);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numLowStockThreshold))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLowStock))->EndInit();
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
		txtItemID->Visible = false;
		LoadInventoryData();
		LoadCategories();
		LoadFilterCategories();
		DatabaseManager^ dbManager = gcnew DatabaseManager();

		if (dbManager->OpenConnection()) {
			label1->Text = "Connection successful!";
			label1->ForeColor = System::Drawing::Color::Green;
		}
		else {
			label1->Text = "Connection failed!";
			label1->ForeColor = System::Drawing::Color::Red;
		}
	}

		
	private: System::Void btnAddItem_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ itemName = txtItemName->Text;
		int categoryId = Convert::ToInt32(cmbCategory->SelectedValue);
		int quantity = Convert::ToInt32(numQuantity->Value);
		double unitPrice = Convert::ToDouble(txtUnitPrice->Text);

		if (String::IsNullOrEmpty(itemName) || categoryId <= 0 || quantity <= 0 || unitPrice <= 0) {
			MessageBox::Show("Lutfen tum alanları eksiksiz ve dogru giriniz!", "Uyarı", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		DatabaseManager^ dbManager = gcnew DatabaseManager();
		bool success = dbManager->AddNewItem(itemName, categoryId, quantity, unitPrice);

		if (success) {
			MessageBox::Show("Urun basariyla eklendi!", "Bilgi", MessageBoxButtons::OK, MessageBoxIcon::Information);
			LoadInventoryData();  // **Ekleme sonrası DataGridView'i güncelle**
		}
		else {
			MessageBox::Show("Urun eklenirken hata olustu.", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
		private: System::Void btnUpdateItem_Click(System::Object^ sender, System::EventArgs^ e) {

			int itemID = Convert::ToInt32(txtItemID->Text);
			String^ itemName = txtItemName->Text;
			int categoryId = Convert::ToInt32(cmbCategory->SelectedValue);
			int quantity = Convert::ToInt32(numQuantity->Value);
			double unitPrice = Convert::ToDouble(txtUnitPrice->Text);

			if (String::IsNullOrEmpty(itemName) || categoryId <= 0 || quantity <= 0 || unitPrice <= 0) {
				MessageBox::Show("Lutfen tum alanlari eksiksiz ve dogru giriniz!", "Uyari", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			DatabaseManager^ dbManager = gcnew DatabaseManager();
			bool success = dbManager->UpdateItem(itemID, itemName, categoryId, quantity, unitPrice);

			if (success) {
				MessageBox::Show("Urun basariyla guncellendi!", "Bilgi", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadInventoryData();  // **Güncelleme sonrası DataGridView'i yenile**
			}
			else {
				MessageBox::Show("Urun guncellenirken hata olustu.", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
				MessageBox::Show("Lutfen silmek icin bir urun secin!", "Uyarı", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int itemID = Convert::ToInt32(txtItemID->Text);

			// Kullanıcıdan silme işlemi için onay alalım
			System::Windows::Forms::DialogResult result = MessageBox::Show(
				"Bu urunu silmek istediginizden emin misiniz?", "Urun Silme",
				MessageBoxButtons::YesNo, MessageBoxIcon::Warning
			);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				DatabaseManager^ dbManager = gcnew DatabaseManager();
				bool success = dbManager->DeleteItem(itemID);

				if (success) {
					MessageBox::Show("Urun basariyla silindi!", "Bilgi", MessageBoxButtons::OK, MessageBoxIcon::Information);
					LoadInventoryData();  // **Silme sonrası DataGridView'i yenile**
				}
				else {
					MessageBox::Show("Urun silinirken hata olustu.", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
		private: System::Void btnLowStockReport_Click(System::Object^ sender, System::EventArgs^ e) {

			int stockThreshold = Convert::ToInt32(numLowStockThreshold->Value);

			DatabaseManager^ dbManager = gcnew DatabaseManager();
			DataTable^ dt = dbManager->GetLowStockItems(stockThreshold);

			dataGridViewLowStock->DataSource = dt;
		}
		private: System::Void btnExportCSV_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dataGridViewLowStock->Rows->Count == 0) {
				MessageBox::Show("Once bir rapor olusturun!", "Uyari", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "CSV files (*.csv)|*.csv";
			saveFileDialog->Title = "Raporu Kaydet";
			saveFileDialog->FileName = "LowStockReport.csv";

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::IO::StreamWriter^ file = gcnew System::IO::StreamWriter(saveFileDialog->FileName, false, System::Text::Encoding::UTF8);

			
				String^ separator = ","; 

				for (int i = 0; i < dataGridViewLowStock->Columns->Count; i++) {
					file->Write(dataGridViewLowStock->Columns[i]->HeaderText);
					if (i < dataGridViewLowStock->Columns->Count - 1) file->Write(separator);
				}
				file->WriteLine();

			
				for (int i = 0; i < dataGridViewLowStock->Rows->Count; i++) {
					for (int j = 0; j < dataGridViewLowStock->Columns->Count; j++) {
						Object^ cellValue = dataGridViewLowStock->Rows[i]->Cells[j]->Value;
						String^ value = (cellValue != nullptr) ? cellValue->ToString() : "";  

						
						if (value->Contains(",") || value->Contains(";")) {
							value = "\"" + value + "\"";
						}

						file->Write(value);
						if (j < dataGridViewLowStock->Columns->Count - 1) file->Write(separator);
					}
					file->WriteLine();
				}

				file->Close();
				MessageBox::Show("Rapor basarıyla kaydedildi!", "Bilgi", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
