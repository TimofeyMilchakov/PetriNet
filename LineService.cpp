#include "LineService.h"

LineService& LineService::getLineService()
{
	static LineService theSingleInstance;
	return theSingleInstance;
}

list<LineDto> LineService::getAll() {
	list<LineDto> res;
	list<LineModel> mod = lineDao.findAll();
	list<LineModel>::iterator it;
	for (it = mod.begin(); it != mod.end(); it++) {
		NodeModel f = nodeDao.findById((*it).firstNode);
		NodeModel s = nodeDao.findById((*it).secondNode);
		LineDto l = LineDto(f.x, f.y, s.x, s.y);
		res.push_back(l);
	}
	return res;
}

LineDto LineService::createNewLine(LineModel line) {
	lineDao.createLine(line);
	NodeModel f = nodeDao.findById(line.firstNode);
	NodeModel s = nodeDao.findById(line.secondNode);
	return LineDto(f.x, f.y, s.x, s.y);
}

LineService::LineService() {}