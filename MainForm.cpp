#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(char *arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	PetriNet::MainForm form; //WinFormsTest - ��� ������ �������
	Application::Run(% form);
}