#pragma once
#include "LineDao.h"
#include "LineDto.cpp"
#include "NodeDao.h"

using namespace std;

class LineService
{
private:
	LineDao& lineDao = LineDao::getLineDao();
	NodeDao& nodeDao = NodeDao::getNodeDao();
	LineService();
public:
	static LineService& getLineService();
	list<LineDto> getAll();
	list<LineModel> getLineById(int id);
	LineModel getLineByIds(int id1, int id2);
	LineDto createNewLine(LineModel line);
};
