#include "ViewController.h"

void ViewController::drawLine(LineModel* line, System::Drawing::Color col)
{
	list<NodeModel*>::iterator it;
	NodeModel* start;
	NodeModel* end;
	for (it = nodes->begin(); it != nodes->end(); it++) {
		if ((*it)->id == line->firstNode) {
			start = *it;
		}
		if ((*it)->id == line->secondNode) {
			end = *it;
		}
	}
	if (start == nullptr || end == nullptr) {
		return;
	}
	System::Drawing::Graphics^ g = this->panel->CreateGraphics();
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(col, 2);
	pen->EndCap = System::Drawing::Drawing2D::LineCap::Triangle;
	pen->StartCap = System::Drawing::Drawing2D::LineCap::Triangle;
	g->DrawLine(pen, start->x, start->y, end->x, end->y);
}

void ViewController::drawNode(NodeModel* node)
{
	System::Windows::Forms::Button^ b = (gcnew System::Windows::Forms::Button());
	b->Location = System::Drawing::Point(node->x, node->y);
	System::String^ name = System::Convert::ToString(node->id);
	System::String^ type = System::Convert::ToString(node->type);

	b->Name = type;
	b->Size = System::Drawing::Size(40, 40);
	b->Click += gcnew System::EventHandler(this, &ViewController::clickNode);
	b->TabIndex = 0;
	b->Text = name;
	b->UseVisualStyleBackColor = true;
	if (node->type == 2) {
		b->BackColor = System::Drawing::Color::Yellow;
	}
	else 
	{
		System::Windows::Forms::TextBox^ text = (gcnew System::Windows::Forms::TextBox());
		System::String^ size = System::Convert::ToString(node->size);
		text->Text = size;
		text->Location = System::Drawing::Point(node->x+14, node->y-18);
		text->Size = System::Drawing::Size(12, 8);
		text->ReadOnly = true;
		this->panel->Controls->Add(text);
	}
	this->panel->Controls->Add(b);
}

void ViewController::addNewNode(int x, int y)
{
	NodeModel* node = nullptr;
	switch (mode)
	{
	case ViewMode::ADD_POSITION:
		node = nodeService.createNewNode(x, y, 1, nodes);
		break;

	case ViewMode::ADD_TRANSFER:
		node = nodeService.createNewNode(x, y, 2, nodes);
		break;
	}
	mode = ViewMode::NONE;
	if (node != nullptr) {
		drawNode(node);
		this->nodes->push_back(node);
	}
}

void ViewController::nodeClick(int id)
{
	
		switch (mode)
		{
		case DELETE_NODE:
			nodeService.deleteNode(id, nodes, lines);
			this->mode=ViewMode::NONE;
			clean(false);
			draw(nullptr);
			break;
		case ADD_LINE:
			if (this->selectId == -1) 
			{
				this->selectId = id;
			}
			else 
			{
				LineModel* line = lineService.createNewLine(this->selectId,id,nodes,lines);
				if (line != nullptr) {
					drawLine(line,System::Drawing::Color::Black);
					lines->push_back(line);
				}
				this->selectId = -1;
				this->mode = ViewMode::NONE;
			}
			break;
		case ADD_M:
			nodeService.incrNode(id, nodes);
			clean(false);
			draw(nullptr);
			break;
		}
	
}

void ViewController::clean(bool all)
{
	this->panel->Controls->Clear();
	System::Drawing::Graphics^ g = this->panel->CreateGraphics();
	g->Clear(System::Drawing::Color::White);
	if (all) {
		nodes->clear();
		lines->clear();
	}

}

void ViewController::draw(list<LineModel*>* redLines)
{
	list<NodeModel*>::iterator it;
	for (it = nodes->begin(); it != nodes->end(); it++) {
		drawNode(*it);
	}
	
	list<LineModel*>::iterator itl;
	if (redLines != nullptr) {
		for (itl = lines->begin(); itl != lines->end(); itl++) {
			if (lineService.contains(*itl,redLines)) 
			{
				drawLine(*itl, System::Drawing::Color::Red);
			}
			else 
			{
				drawLine(*itl, System::Drawing::Color::Black);
			}
		}
	}
	else {
		for (itl = lines->begin(); itl != lines->end(); itl++) {
			drawLine(*itl, System::Drawing::Color::Black);
		}
	}
}

void ViewController::addViewMode(ViewMode mode)
{
	this->selectId = -1;
	this->mode = mode;
}

string ViewController::saveFile(string path)
{
	return fileService.saveFile(path,nodes,lines);
}

string ViewController::loadFile(string path)
{
	if (fileService.loadFile(path, nodes, lines)) 
	{
		clean(false);
		draw(nullptr);
		lineService.refresh(lines);
		nodeService.refresh(nodes);
		return string("Данные успешно загруженны");
	}
	else 
	{
		clean(true);
		return string("Ошибка при загрузке данных");
	}
}
