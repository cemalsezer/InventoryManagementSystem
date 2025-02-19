#include "MyForm.h"
#include "DatabaseManager.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace InventoryManagementSystem;  // Namespace ekleyelim

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    InventoryManagementSystem::DatabaseManager^ dbManager = gcnew InventoryManagementSystem::DatabaseManager();
    dbManager->OpenConnection();  // Bağlantıyı test et

    InventoryManagementSystem::MyForm form;
    Application::Run(% form);

    dbManager->CloseConnection();  // Program kapanırken bağlantıyı kapat
    return 0;
}
