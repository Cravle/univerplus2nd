#include "MyFormMenu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void mian(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Database::MyForm form;
	Application::Run(%form);
}