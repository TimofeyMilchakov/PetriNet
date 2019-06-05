#pragma once
#include "NodeModel.h"
#include "LineModel.h"
#include <unordered_map>
#include <list>

using namespace std;

class LineService
{
private:
	LineService();
	int maxId = -1;
public:
	static LineService& getLineService();
	list<LineModel*> getLineById(int id, list<LineModel*>* lines);
	LineModel* getLineByIds(int id1, int id2, list<LineModel*>* lines);
	LineModel* createNewLine(int from, int to, list<NodeModel*>* nodes, list<LineModel*>* lines);
	void deleteLinesByNodeId(int id, list<LineModel*>* lines);
	bool contains(LineModel* line, list<LineModel*>* lines);
	void refresh(list<LineModel*>* lines);
	list<LineModel*>* convert(int start,vector<short> line,int end, list<LineModel*>* lines);
};
