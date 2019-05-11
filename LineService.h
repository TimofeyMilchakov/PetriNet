#pragma once
#include "LineDao.h"
#include "NodeDao.h"

using namespace std;

class LineService
{
private:
	LineService();
	int maxId = 0;
public:
	static LineService& getLineService();
	list<LineModel*> getLineById(int id, list<LineModel*>* lines);
	LineModel* getLineByIds(int id1, int id2, list<LineModel*>* lines);
	LineModel* createNewLine(int from, int to, list<NodeModel*>* nodes, list<LineModel*>* lines);
	void deleteLinesByNodeId(int id, list<LineModel*>* lines);
	bool contains(LineModel* line, list<LineModel*>* lines);
	void refresh(list<LineModel*>* lines);
};
