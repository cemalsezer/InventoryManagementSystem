#include "DatabaseManager.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Data::SqlClient;

namespace InventoryManagementSystem {

    DatabaseManager::DatabaseManager() {
        // Fazladan "\" işareti kaldırıldı
        connectionString = "Data Source=CEMAL;Initial Catalog=InventoryDB;Integrated Security=True;";
        sqlConnection = gcnew SqlConnection(connectionString);
        isConnected = false;
    }

    bool DatabaseManager::OpenConnection() {
        try {
            sqlConnection->Open();
            isConnected = true;
            return true;
        }
        catch (SqlException^ ex) {  // SQL bağlantı hatalarını yakalar
            MessageBox::Show("SQL Baglanti Hatasi: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ ex) {  // Genel bağlantı hatalarını yakalar
            MessageBox::Show("Bağlanti hatasi: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        isConnected = false;
        return false;
    }

    void DatabaseManager::CloseConnection() {
        if (sqlConnection->State == ConnectionState::Open) {
            sqlConnection->Close();
            isConnected = false;
        }
    }

    bool DatabaseManager::GetConnectionStatus() {
        return isConnected;
    }

    // 🔹 **SQL Server'dan Verileri Çekme (DataGridView İçin)**
    DataTable^ DatabaseManager::GetInventoryData() {
        DataTable^ dt = gcnew DataTable();
        try {
            OpenConnection();

            // SQL sorgusu: Items ve Categories tablolarını birleştirerek veri çekiyoruz
            String^ query = "SELECT Items.ItemID, Items.ItemName, Categories.CategoryName, Items.Quantity, Items.UnitPrice "
                "FROM Items INNER JOIN Categories ON Items.CategoryID = Categories.CategoryID";

            SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, sqlConnection);
            adapter->Fill(dt);  // SQL'den gelen verileri DataTable içine doldur
            CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Veri cekme hatasi: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        return dt;
    }

    bool DatabaseManager::AddNewItem(String^ itemName, int categoryId, int quantity, double unitPrice) {
        try {
            OpenConnection();

            String^ query = "INSERT INTO Items (ItemName, CategoryID, Quantity, UnitPrice) VALUES (@itemName, @categoryId, @quantity, @unitPrice)";
            SqlCommand^ cmd = gcnew SqlCommand(query, sqlConnection);
            cmd->Parameters->AddWithValue("@itemName", itemName);
            cmd->Parameters->AddWithValue("@categoryId", categoryId);
            cmd->Parameters->AddWithValue("@quantity", quantity);
            cmd->Parameters->AddWithValue("@unitPrice", unitPrice);

            int result = cmd->ExecuteNonQuery();
            CloseConnection();

            return result > 0;  // Eğer satır eklendiyse true döndür
        }
        catch (Exception^ ex) {
            MessageBox::Show("Urun ekleme hatasi: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return false;
        }
    }

    DataTable^ DatabaseManager::GetCategories() {
        DataTable^ dt = gcnew DataTable();
        try {
            OpenConnection();
            String^ query = "SELECT CategoryID, CategoryName FROM Categories";
            SqlDataAdapter^ adapter = gcnew SqlDataAdapter(query, sqlConnection);
            adapter->Fill(dt);
            CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Kategori yukleme hatasi: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        return dt;
    }

}
