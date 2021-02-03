#include "MyFormMenu.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Course2::MyForm form;
	Application::Run(% form);
}
