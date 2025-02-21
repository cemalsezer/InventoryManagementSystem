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

    bool DatabaseManager::UpdateItem(int itemID, String^ itemName, int categoryId, int quantity, double unitPrice) {
        try {
            OpenConnection();

            String^ query = "UPDATE Items SET ItemName=@itemName, CategoryID=@categoryId, Quantity=@quantity, UnitPrice=@unitPrice WHERE ItemID=@itemID";
            SqlCommand^ cmd = gcnew SqlCommand(query, sqlConnection);
            cmd->Parameters->AddWithValue("@itemName", itemName);
            cmd->Parameters->AddWithValue("@categoryId", categoryId);
            cmd->Parameters->AddWithValue("@quantity", quantity);
            cmd->Parameters->AddWithValue("@unitPrice", unitPrice);
            cmd->Parameters->AddWithValue("@itemID", itemID);

            int result = cmd->ExecuteNonQuery();
            CloseConnection();

            return result > 0;  // Eğer satır değiştiyse true döndür
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ürün güncelleme hatası: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return false;
        }
    }

    bool DatabaseManager::DeleteItem(int itemID) {
        try {
            OpenConnection();

            String^ query = "DELETE FROM Items WHERE ItemID=@itemID";
            SqlCommand^ cmd = gcnew SqlCommand(query, sqlConnection);
            cmd->Parameters->AddWithValue("@itemID", itemID);

            int result = cmd->ExecuteNonQuery();
            CloseConnection();

            return result > 0;  // Eğer satır silindiyse true döndür
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ürün silme hatası: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return false;
        }
    }

    DataTable^ DatabaseManager::SearchItems(String^ searchQuery, int categoryId) {
        DataTable^ dt = gcnew DataTable();
        try {
            OpenConnection();

            // **Arama sorgusunu oluştur**
            String^ query = "SELECT Items.ItemID, Items.ItemName, Categories.CategoryName, Items.Quantity, Items.UnitPrice "
                "FROM Items INNER JOIN Categories ON Items.CategoryID = Categories.CategoryID "
                "WHERE Items.ItemName LIKE @searchQuery";

            // **Eğer kategori filtresi varsa, sorguya ekle**
            if (categoryId > 0) {
                query += " AND Items.CategoryID = @categoryId";
            }

            SqlCommand^ cmd = gcnew SqlCommand(query, sqlConnection);
            cmd->Parameters->AddWithValue("@searchQuery", "%" + searchQuery + "%");

            if (categoryId > 0) {
                cmd->Parameters->AddWithValue("@categoryId", categoryId);
            }

            SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
            adapter->Fill(dt);

            CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Arama işlemi hatası: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        return dt;
    }

    DataTable^ DatabaseManager::GetLowStockItems(int stockThreshold) {
        DataTable^ dt = gcnew DataTable();
        try {
            OpenConnection();

            String^ query = "SELECT Items.ItemID, Items.ItemName, Categories.CategoryName, Items.Quantity, Items.UnitPrice "
                "FROM Items INNER JOIN Categories ON Items.CategoryID = Categories.CategoryID "
                "WHERE Items.Quantity < @stockThreshold";

            SqlCommand^ cmd = gcnew SqlCommand(query, sqlConnection);
            cmd->Parameters->AddWithValue("@stockThreshold", stockThreshold);

            SqlDataAdapter^ adapter = gcnew SqlDataAdapter(cmd);
            adapter->Fill(dt);

            CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Düşük stok raporu oluşturulurken hata oluştu: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        return dt;
    }


}
