#include "LineService.h"

LineService& LineService::getLineService()
{
	static LineService theSingleInstance;
	return theSingleInstance;
}

list<LineModel*> LineService::getLineById(int id, list<LineModel*>* lines)
{
	list<LineModel*> newList;
	list<LineModel*>::iterator it;
	for (it = lines->begin(); it != lines->end(); it++) {
		if ((*it)->firstNode == id || (*it)->secondNode == id) {
			newList.push_back(*it);
		}
	}
	return newList;
}

LineModel* LineService::getLineByIds(int id1, int id2, list<LineModel*>* lines)
{
	list<LineModel*>::iterator it;
	for (it = lines->begin(); it != lines->end(); it++) {
		if (((*it)->firstNode == id1 && (*it)->secondNode == id2)||((*it)->firstNode == id2 && (*it)->secondNode == id1)) {
			return *it;
		}
	}
	return nullptr;
}

LineModel* LineService::createNewLine(int from, int to, list<NodeModel*>* nodes, list<LineModel*>* lines)
{
	NodeModel* f = nullptr;
	NodeModel* s = nullptr;
	list<NodeModel*>::iterator it;
	for (it = nodes->begin(); it != nodes->end(); it++) {
		if ((*it)->id == from) {
			f = (*it);
		}
		if ((*it)->id == to) {
			s = (*it);
		}
	}
	if (!f || !s || f->type==s->type) {
		return nullptr;
	}
	list<LineModel*>::iterator itl;
	for (itl = lines->begin(); itl != lines->end(); itl++) {
		if ((*itl)->firstNode == from && (*itl)->secondNode == to)
		{
			return nullptr;
		}
		if ((*itl)->firstNode == to&& (*itl)->secondNode == from)
		{
			return nullptr;
		}
	}
	return new LineModel(++maxId, from, to);
}


void LineService::deleteLinesByNodeId(int id, list<LineModel*>* lines)
{
	list<LineModel*>::iterator it;
	for (it = lines->begin(); it != lines->end(); it++) {
		if ((*it)->firstNode==id|| (*it)->secondNode== id)
		{
			lines->remove(*it);
			deleteLinesByNodeId(id, lines);
			break;
		}
	}
}

bool LineService::contains(LineModel* line, list<LineModel*>* lines)
{
	list<LineModel*>::iterator it;
	for (it = lines->begin(); it != lines->end(); it++) {
		if ((*it)->equals(line)) 
		{
			return true;
		}
	}
	return false;
}

void LineService::refresh(list<LineModel*>* lines)
{
	int max = this->maxId;
	list<LineModel*>::iterator it;
	for (it = lines->begin(); it != lines->end(); it++) {
		if (max < (*it)->id) {
			max = (*it)->id;
		}
	}
	this->maxId = max;
}

list<LineModel*>* LineService::convert(int start, vector<short> line, int end, list<LineModel*>* lines)
{
	list<LineModel*>* res = new list<LineModel*>();
	int oldStart = start;
	for (short id : line) {
		for (LineModel* l : *lines) {
			if (start == l->firstNode&&id== l->secondNode) {
				res->push_back(l);
				start = id;
				break;
			}
		}
		if (start == oldStart) {
			return nullptr;
		}
		else {
			oldStart = start;
		}
	}
	for (LineModel* l : *lines) {
		if (start == l->firstNode && end == l->secondNode) {
			res->push_back(l);
			break;
		}
	}
	return res->empty() ? nullptr : res;
}


LineService::LineService() {}