#pragma once
#include <list>
#include "ViewController.h"

namespace PetriNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		bool initialeze = false;


		System::ComponentModel::Container^ components;
		System::ComponentModel::Container^ nodes;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;

	private: ViewController^ viewController;
#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Требуемый метод для поддержки конструктора — не изменяйте 
			 /// содержимое этого метода с помощью редактора кода.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
				 this->button8 = (gcnew System::Windows::Forms::Button());
				 this->button7 = (gcnew System::Windows::Forms::Button());
				 this->button6 = (gcnew System::Windows::Forms::Button());
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
				 this->button9 = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
				 this->splitContainer1->Panel2->SuspendLayout();
				 this->splitContainer1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // splitContainer1
				 // 
				 this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->splitContainer1->Location = System::Drawing::Point(0, 0);
				 this->splitContainer1->Name = L"splitContainer1";
				 // 
				 // splitContainer1.Panel1
				 // 
				 this->splitContainer1->Panel1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::addNewNode);
				 // 
				 // splitContainer1.Panel2
				 // 
				 this->splitContainer1->Panel2->Controls->Add(this->button9);
				 this->splitContainer1->Panel2->Controls->Add(this->button8);
				 this->splitContainer1->Panel2->Controls->Add(this->button7);
				 this->splitContainer1->Panel2->Controls->Add(this->button6);
				 this->splitContainer1->Panel2->Controls->Add(this->button5);
				 this->splitContainer1->Panel2->Controls->Add(this->button4);
				 this->splitContainer1->Panel2->Controls->Add(this->button3);
				 this->splitContainer1->Panel2->Controls->Add(this->button2);
				 this->splitContainer1->Panel2->Controls->Add(this->button1);
				 this->splitContainer1->Size = System::Drawing::Size(1173, 683);
				 this->splitContainer1->SplitterDistance = 913;
				 this->splitContainer1->TabIndex = 0;
				 // 
				 // button8
				 // 
				 this->button8->Location = System::Drawing::Point(3, 465);
				 this->button8->Name = L"button8";
				 this->button8->Size = System::Drawing::Size(241, 55);
				 this->button8->TabIndex = 7;
				 this->button8->Text = L"Добавить метку";
				 this->button8->UseVisualStyleBackColor = true;
				 this->button8->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::addM);
				 // 
				 // button7
				 // 
				 this->button7->Location = System::Drawing::Point(3, 72);
				 this->button7->Name = L"button7";
				 this->button7->Size = System::Drawing::Size(241, 58);
				 this->button7->TabIndex = 6;
				 this->button7->Text = L"Сохранение в файл";
				 this->button7->UseVisualStyleBackColor = true;
				 this->button7->Click += gcnew System::EventHandler(this, &MainForm::saveToFile);
				 // 
				 // button6
				 // 
				 this->button6->Location = System::Drawing::Point(3, 399);
				 this->button6->Name = L"button6";
				 this->button6->Size = System::Drawing::Size(241, 60);
				 this->button6->TabIndex = 5;
				 this->button6->Text = L"Добавить Связь";
				 this->button6->UseVisualStyleBackColor = true;
				 this->button6->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::addLine);
				 // 
				 // button5
				 // 
				 this->button5->Location = System::Drawing::Point(3, 331);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(241, 62);
				 this->button5->TabIndex = 4;
				 this->button5->Text = L"Добавить Переход";
				 this->button5->UseVisualStyleBackColor = true;
				 this->button5->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::addTransfer);
				 // 
				 // button4
				 // 
				 this->button4->Location = System::Drawing::Point(3, 267);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(241, 58);
				 this->button4->TabIndex = 3;
				 this->button4->Text = L"Добавить Позицию";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::addPosition);
				 // 
				 // button3
				 // 
				 this->button3->Location = System::Drawing::Point(3, 202);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(241, 59);
				 this->button3->TabIndex = 2;
				 this->button3->Text = L"Удалить вершину";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &MainForm::deleteNode);
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(3, 136);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(241, 60);
				 this->button2->TabIndex = 1;
				 this->button2->Text = L"Очистить";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &MainForm::clear);
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(3, 12);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(241, 54);
				 this->button1->TabIndex = 0;
				 this->button1->Text = L"Загрузка из Файла";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MainForm::loadFromFile);
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
				 // button9
				 // 
				 this->button9->Location = System::Drawing::Point(3, 526);
				 this->button9->Name = L"button9";
				 this->button9->Size = System::Drawing::Size(241, 51);
				 this->button9->TabIndex = 8;
				 this->button9->Text = L"Удалить метку";
				 this->button9->UseVisualStyleBackColor = true;
				 this->button9->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::deleteM);
				 // 
				 // MainForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1173, 683);
				 this->Controls->Add(this->splitContainer1);
				 this->Name = L"MainForm";
				 this->Text = L"MainForm";
				 this->splitContainer1->Panel2->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
				 this->splitContainer1->ResumeLayout(false);
				 this->ResumeLayout(false);
				 this->viewController = gcnew ViewController(this->splitContainer1->Panel1);
			 }
#pragma endregion
			 //this->viewController = gcnew ViewController(this->splitContainer1->Panel1);
	public: System::Windows::Forms::SplitterPanel^ getPanel() {
		return this->splitContainer1->Panel1;
	}

	private: System::Void addNewNode(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		int x = e->X - 20;
		int y = e->Y - 20;
		viewController->addNewNode(x, y);
	}



	private: System::Void clickNode(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(((Button^)sender)->Text);
		viewController->nodeClick(id);

	}

	private: System::Void clear(System::Object^ sender, System::EventArgs^ e) {
		viewController->clean(true);
	}
	private: System::Void deleteNode(System::Object^ sender, System::EventArgs^ e) {
		viewController->addViewMode(ViewMode::DELETE_NODE);
	}
	private: System::Void addPosition(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		viewController->addViewMode(ViewMode::ADD_POSITION);
	}

	private: System::Void addTransfer(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		viewController->addViewMode(ViewMode::ADD_TRANSFER);

	}
	private: System::Void addLine(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		viewController->addViewMode(ViewMode::ADD_LINE);
	}


private: System::Void loadFromFile(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		return;
	// получаем выбранный файл
	String^ filename = (openFileDialog1)->FileName;	
	
	string result = viewController->loadFile(stringConverter(filename));
	
	System::Windows::Forms::MessageBox::Show(gcnew System::String(result.c_str()));

}

	private: string stringConverter(System::String^ sS) {
		std::string myString = "";
		for (int i = 0; i < sS->Length; i++) {
			myString += (char)sS[i];
		}
		return myString;
	}
private: System::Void saveToFile(System::Object^ sender, System::EventArgs^ e) {
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		return;
	// получаем выбранный файл
	String^ filename = (saveFileDialog1)->FileName;
	// сохраняем текст в файл
	string result = viewController->saveFile(stringConverter(filename));

	System::Windows::Forms::MessageBox::Show(gcnew System::String(result.c_str()));

}

private: System::Void addM(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->viewController->addViewMode(ViewMode::ADD_M);
}
private: System::Void deleteM(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->viewController->addViewMode(ViewMode::DELETE_M);
}
};
}



