#pragma once
#include "LineService.h"
#include "NodeService.h"
#include "FileService.h"
#include "NodeModel.h"
#include "LineModel.h"


enum ViewMode {
	DELETE_NODE, ADD_POSITION, ADD_TRANSFER, ADD_LINE,ADD_M,DELETE_M, NONE
};


public ref class ViewController
{
private:
	System::Windows::Forms::SplitterPanel^ panel;
	LineService& lineService = LineService::getLineService();
	NodeService& nodeService = NodeService::getNodeService();
	FileService& fileService = FileService::getFileService();
	//FileService& fileService = FileService::getFileService();

	list<NodeModel*>* nodes = new list<NodeModel*>;
	list<LineModel*>* lines = new list<LineModel*>;
	ViewMode mode = ViewMode::NONE;
	int selectId = -1;
	void drawLine(LineModel* line, System::Drawing::Color col);
	void drawLineTriangle(System::Drawing::Graphics^ g, System::Drawing::Pen^ pen, float x1, float y1, float x2, float y2);
	void drawNode(NodeModel* node);
	
	
	System::Void clickNode(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(((System::Windows::Forms::Button^)sender)->Text);
		nodeClick(id);
	}


public:
	ViewController(System::Windows::Forms::SplitterPanel^ panel):panel(panel){};
	void addNewNode(int x, int y);
	void nodeClick(int id);
	void clean(bool all);
	void draw(list<LineModel*>* redLines);
	void addViewMode(ViewMode mode);
	string saveFile(string path);
	string loadFile(string path);

};


