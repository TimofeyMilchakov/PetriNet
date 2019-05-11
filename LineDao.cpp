#include "LineDao.h"

LineDao::LineDao() {}

LineDao& LineDao::getLineDao() {
	static LineDao theSingleInstance;
	return theSingleInstance;
}


list<LineModel> LineDao::findAll() {
	string query = "SELECT * FROM l";
	MYSQL_RES* result = db.query(query);
	list<LineModel> l;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		LineModel line;
		line.id = atoi(row[0]);
		line.firstNode = atoi(row[1]);
		line.secondNode = atoi(row[2]);
		l.push_back(line);
	}
	return l;
}
LineModel LineDao::findLineByIds(int id1, int id2) {
	string firstNode = to_string(id1);
	string secondNode = to_string(id2);
	string query = "SELECT * FROM l where (l.firstNode="+ firstNode +" AND l.secondNode="+ secondNode +") or (l.firstNode="+ secondNode +" AND l.secondNode="+ firstNode +")";
	MYSQL_RES* result = db.query(query);
	list<LineModel> l;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		LineModel line;
		line.id = atoi(row[0]);
		line.firstNode = atoi(row[1]);
		line.secondNode = atoi(row[2]);
		return line;
	}
	return LineModel();

}

list<LineModel> LineDao::findLinesById(int id) {
	string ids = to_string(id);
	string query = "SELECT * FROM l where (l.firstNode=" + ids +" OR l.secondNode=" + ids + ")";
	MYSQL_RES* result = db.query(query);
	list<LineModel> l;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		LineModel line;
		line.id = atoi(row[0]);
		line.firstNode = atoi(row[1]);
		line.secondNode = atoi(row[2]);
		l.push_back(line);
	}
	return l;
}

void LineDao::createLine(LineModel line)
{
	string firstNode = to_string(line.firstNode);
	string secondNode = to_string(line.secondNode);
	string query = "INSERT INTO l(firstNode,secondNode) VALUES(" + firstNode + "," + secondNode + ")";
	db.query(query);
}

void LineDao::removeAllLinesByNodeId(int nodeId) {
	string nodeIds = to_string(nodeId);
	string query = "DELETE FROM l WHERE l.firstNode=" + nodeIds + " OR l.secondNode=" + nodeIds;
	db.query(query);
}
