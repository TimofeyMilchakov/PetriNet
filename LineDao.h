#pragma once
#include "ManagerConnector.h"
#include "LineModel.h"
#include <list>
using namespace std;


class LineDao
{
public:
	static LineDao& getLineDao();
	list<LineModel> findAll();
	void createLine(LineModel line);
	LineModel findLineByIds(int id1, int id2);
	void removeAllLinesByNodeId(int nodeId);
	list<LineModel> findLinesById(int id);
private:
	ManagerConnector& db = ManagerConnector::getManagerConnector();
	LineDao();
	LineDao(const LineDao&);
	LineDao& operator=(LineDao&);
};