#include "ViewController.h"

void ViewController::drawLine(LineModel* line, System::Drawing::Color col)
{
	list<NodeModel*>::iterator it;
	NodeModel* start = nodeService.getNodeById(line->firstNode, nodes);
	NodeModel* end = nodeService.getNodeById(line->secondNode, nodes);
	if (start == nullptr || end == nullptr) {
		return;
	}
	System::Drawing::Graphics^ g = this->panel->CreateGraphics();
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(col, 2);
	int delX = start->x < end->x ? 0 : 40;
	int delY = start->y < end->y ? 0 : 40;
	drawLineTriangle(g, pen, start->x+20, start->y + 20, end->x+delX, end->y+delY);
}

void ViewController::drawLineTriangle(System::Drawing::Graphics^ g, System::Drawing::Pen^ pen, float x1, float y1, float x2, float y2)
{
	pen->EndCap = System::Drawing::Drawing2D::LineCap::Triangle;
	pen->StartCap = System::Drawing::Drawing2D::LineCap::Triangle;
	
	float x, y;
	float f1x2, f1y2;
	float lons, ugol;

	const float ostr = 0.25;        // острота стрелки

	g->DrawLine(pen, x1, y1, x2, y2);

	x = x2 - x1;
	y = y2 - y1;

	lons = sqrt(x * x + y * y) / 7;     // длина лепестков % от длины стрелки
	ugol = atan2(y, x);             // угол наклона линии

	//lons = 12;

	f1x2 = x2 - lons * cos(ugol - ostr);
	f1y2 = y2 - lons * sin(ugol - ostr);

	g->DrawLine(pen, x2, y2, f1x2, f1y2);

	f1x2 = x2 - lons * cos(ugol + ostr);
	f1y2 = y2 - lons * sin(ugol + ostr);

	g->DrawLine(pen, x2, y2, f1x2, f1y2);
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
		if (node->type == 1) {
			pNet->addP(node->id);
		}
		else {
			pNet->addT(node->id);
		}
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
			fullUpdate();
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
					NodeModel* f = nodeService.getNodeById(line->firstNode, nodes);
					if (f->type == 1) {
						pNet->addD(line->firstNode, line->secondNode, -1);
					}
					else {
						pNet->addD(line->secondNode, line->firstNode, 1);
					}
					drawLine(line,System::Drawing::Color::Black);
					lines->push_back(line);
				}
				this->selectId = -1;
				this->mode = ViewMode::NONE;
			}
			break;
		case ADD_M:
			nodeService.changeSizeNode(id, nodes,true);
			pNet->addM(id, nodeService.getNodeById(id, nodes)->size);
			clean(false);
			draw(nullptr);
			break;
		case DELETE_M:
			nodeService.changeSizeNode(id, nodes, false);
			pNet->addM(id, nodeService.getNodeById(id, nodes)->size);
			clean(false);
			draw(nullptr);
			break;

		case ALG:
			if (this->selectId == -1)
			{
				this->selectId = id;
			}
			else
			{
				vector<short> line = pNet->algorithm(this->selectId, id);
				list<LineModel*>* redLines = lineService.convert(this->selectId,line,id, lines);
				mUpdate();
				clean(false);
				draw(redLines);
				this->selectId = -1;
				this->mode = ViewMode::NONE;
			}
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
		fullUpdate();
	}

}

void ViewController::mUpdate() {
	for (NodeModel* node : *nodes) {
		if (node->type == 1) {
			node->size = pNet->atM(node->id);
		}
	}
}

void ViewController::fullUpdate() {
	pNet = alloc->getNet();
	for (NodeModel* node : *nodes) {
		if (node->type == 1) {
			pNet->addP(node->id);
			pNet->addM(node->id, node->size);
		}
		else {
			pNet->addT(node->id);
		}
	}
	for (LineModel* line : *lines) {
		NodeModel* f = nodeService.getNodeById(line->firstNode, nodes);
		if (f->type == 1) {
			pNet->addD(line->firstNode, line->secondNode, 1);
		}
		else {
			pNet->addD(line->secondNode, line->firstNode, -1);
		}
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
		if (nodeService.validateData(nodes, lines)) {
			fullUpdate();
			clean(false);
			draw(nullptr);
			lineService.refresh(lines);
			nodeService.refresh(nodes);
			return string("Данные успешно загруженны");
		}
		else {
			clean(true);
			draw(nullptr);
			lineService.refresh(lines);
			nodeService.refresh(nodes);
			return string("Ошибка в загруженных данных");
		}
	}
	else 
	{
		clean(true);
		return string("Ошибка при загрузке данных");
	}
}
