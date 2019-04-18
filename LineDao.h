#pragma once
#include "ManagerConnector.h"
#include "LineModel.cpp"
#include <list>
using namespace std;


class LineDao
{
public:
	static LineDao& getLineDao();
	list<LineModel> findAll();
	void createLine(LineModel line);
	void removeAllLinesByNodeId(int nodeId);
private:
	ManagerConnector& db = ManagerConnector::getManagerConnector();
	LineDao();
	LineDao(const LineDao&);
	LineDao& operator=(LineDao&);
};