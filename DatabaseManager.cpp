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
            MessageBox::Show("SQL Bağlantı Hatası: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ ex) {  // Genel bağlantı hatalarını yakalar
            MessageBox::Show("Bağlantı hatası: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
            MessageBox::Show("Veri çekme hatası: " + ex->Message, "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        return dt;
    }
}
