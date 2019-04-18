#include "MainForm.h"

#pragma comment(lib, "C:\\Program Files\\MySQL\\MySQL Server 5.7\\lib\\libmysql.lib")

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(char *arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	PetriNet::MainForm form; //WinFormsTest - имя вашего проекта
	Application::Run(% form);
}