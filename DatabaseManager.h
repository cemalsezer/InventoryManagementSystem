#pragma once
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

namespace InventoryManagementSystem {
    public ref class DatabaseManager {
    private:
        String^ connectionString;
        SqlConnection^ sqlConnection;  // **Eksikse ekle!**
        bool isConnected;

    public:
        DatabaseManager();
        bool OpenConnection();
        void CloseConnection();
        bool GetConnectionStatus();
        DataTable^ GetInventoryData();  // **Eksikse ekle!**
        DataTable^ GetCategories();
        bool AddNewItem(String^ itemName, int categoryId, int quantity, double unitPrice);  
        bool UpdateItem(int itemID, String^ itemName, int categoryId, int quantity, double unitPrice);

    };


}
