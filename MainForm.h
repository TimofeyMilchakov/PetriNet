#pragma once
#include <list>
#include "NodeService.h"
#include "LineService.h"

namespace PetriNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ������������ ���������� ������������.
		/// </summary>
		bool initialeze = false;

		int nodeSelected = -1;
		int typeNodeSelected = -1;
		bool lineAdd = false;

		int type = 0;

		System::ComponentModel::Container^ components;
		System::ComponentModel::Container^ nodes;
	private: System::Windows::Forms::Button^ button1;
			 LineService& lineService = LineService::getLineService();
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button6;
			 NodeService& nodeService = NodeService::getNodeService();
#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// ��������� ����� ��� ��������� ������������ � �� ��������� 
			 /// ���������� ����� ������ � ������� ��������� ����.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
				 this->button6 = (gcnew System::Windows::Forms::Button());
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button1 = (gcnew System::Windows::Forms::Button());
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
				 // button6
				 // 
				 this->button6->Location = System::Drawing::Point(3, 335);
				 this->button6->Name = L"button6";
				 this->button6->Size = System::Drawing::Size(241, 60);
				 this->button6->TabIndex = 5;
				 this->button6->Text = L"�������� �����";
				 this->button6->UseVisualStyleBackColor = true;
				 this->button6->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::addLine);
				 // 
				 // button5
				 // 
				 this->button5->Location = System::Drawing::Point(3, 267);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(241, 62);
				 this->button5->TabIndex = 4;
				 this->button5->Text = L"�������� �������";
				 this->button5->UseVisualStyleBackColor = true;
				 this->button5->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::addTransfer);
				 // 
				 // button4
				 // 
				 this->button4->Location = System::Drawing::Point(3, 203);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(241, 58);
				 this->button4->TabIndex = 3;
				 this->button4->Text = L"�������� �������";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::addPosition);
				 // 
				 // button3
				 // 
				 this->button3->Location = System::Drawing::Point(3, 138);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(241, 59);
				 this->button3->TabIndex = 2;
				 this->button3->Text = L"������� �������";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &MainForm::deleteNode);
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(3, 72);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(241, 60);
				 this->button2->TabIndex = 1;
				 this->button2->Text = L"��������";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &MainForm::clear);
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(3, 12);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(241, 54);
				 this->button1->TabIndex = 0;
				 this->button1->Text = L"�������� �� ��";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MainForm::init);
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

			 }
#pragma endregion

	private: void initializeNodes(void) {

		list<NodeModel> nodes = nodeService.getAll();
		list <NodeModel> ::iterator it;
		for (it = nodes.begin(); it != nodes.end(); it++) {
			System::Windows::Forms::Button^ b = createNodeFromModel(*it);
			this->splitContainer1->Panel1->Controls->Add(b);
		}

	}

	private: void initializeLines(void) {
		list<LineDto> lines = lineService.getAll();
		list <LineDto> ::iterator it;
		for (it = lines.begin(); it != lines.end(); it++) {
			drawLine(*it, Color::Black);
		}
	}

	private: System::Void addNewNode(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (type != 0) {
			int x = e->X - 20;
			int y = e->Y - 20;
			NodeModel node = nodeService.createNewNode(x, y, type);
			if (node.id != -1) {
				System::Windows::Forms::Button^ b = createNodeFromModel(node);
				this->splitContainer1->Panel1->Controls->Add(b);
				type = 0;
			}
		}
	}

	private:System::Void drawLine(LineDto line, Color col) {
		Graphics^ g = this->splitContainer1->Panel1->CreateGraphics();
		Pen^ pen = gcnew Pen(col,2);
		pen->EndCap = System::Drawing::Drawing2D::LineCap::RoundAnchor;
		pen->StartCap = System::Drawing::Drawing2D::LineCap::RoundAnchor;
		g->DrawLine(pen, line.firstX, line.firstY, line.secondX, line.secondY);
	}

	private: System::Windows::Forms::Button^ createNodeFromModel(NodeModel node) {
		System::Windows::Forms::Button^ b = (gcnew System::Windows::Forms::Button());
		b->Location = System::Drawing::Point(node.x, node.y);
		System::String^ name = System::Convert::ToString(node.id);
		System::String^ type = System::Convert::ToString(node.type);
		
		b->Name = type;
		b->Size = System::Drawing::Size(40, 40);
		b->Click += gcnew System::EventHandler(this, &MainForm::clickNode);
		b->TabIndex = 0;
		b->Text = name;
		b->UseVisualStyleBackColor = true;
		if (node.type == 2) {
			b->BackColor = Color::Yellow;
		}
		return b;
	}


	private: System::Void init(System::Object^ sender, System::EventArgs^ e) {
		clear(nullptr, nullptr);
		initializeLines();
		initializeNodes();
	}

	private: System::Void clickNode(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(((Button^)sender)->Text);
		int typeNode = Convert::ToInt32(((Button^)sender)->Name);
		
		if (nodeSelected != -1) {
			if (nodeSelected == id|| !lineAdd || typeNode== typeNodeSelected) {
				return;
			}
			LineModel l = LineModel(nodeSelected, id);
			LineDto line = lineService.createNewLine(l);
			drawLine(line, Color::Black);
			nodeSelected = -1;
			typeNodeSelected = -1;
			lineAdd = false;
		}
		else {
			nodeSelected = id;
			typeNodeSelected = typeNode;
		}
	}

	private: System::Void clear(System::Object^ sender, System::EventArgs^ e) {
		this->splitContainer1->Panel1->Controls->Clear();
		Graphics^ g = this->splitContainer1->Panel1->CreateGraphics();
		g->Clear(Color::White);
	}
	private: System::Void deleteNode(System::Object^ sender, System::EventArgs^ e) {
		if (nodeSelected != -1) {
			nodeService.deleteNode(nodeSelected);
			init(nullptr, nullptr);
			nodeSelected = -1;
		}
	}
	private: System::Void addPosition(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		type = 1;
	}

	private: System::Void addTransfer(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		type = 2;
	}
	private: System::Void addLine(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		lineAdd = !lineAdd;
		int nodeSelected = -1;
		int typeNodeSelected = -1;
	}
};
}



