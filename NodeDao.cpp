#include "NodeDao.h"

NodeDao::NodeDao() {}

NodeDao& NodeDao::getNodeDao() {
	static NodeDao theSingleInstance;
	return theSingleInstance;
}

list<NodeModel> NodeDao::findAll() {
	string query = "SELECT * FROM nodes";
	MYSQL_RES* result = db.query(query);
	list<NodeModel> l;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		NodeModel node;
		node.id = atoi(row[0]);
		node.x = atoi(row[1]);
		node.y = atoi(row[2]);
		node.type = atoi(row[3]);
		l.push_back(node);
	}
	return l;
}

NodeModel NodeDao::createNew(NodeModel node) {
	string x = to_string(node.x);
	string y = to_string(node.y);
	string type = to_string(node.type);
	string query = "INSERT INTO nodes(x,y,type) VALUES(" + x + "," + y + ","+type+")";
	MYSQL_RES* result = db.query(query);
	int id = findNodeId(node.x, node.y);
	node.id = id;
	return node;
}

NodeModel NodeDao::findById(int id) {
	string ids = to_string(id);
	string query = "SELECT * FROM nodes WHERE nodes.id=" + ids;
	MYSQL_RES* result = db.query(query);
	MYSQL_ROW row = mysql_fetch_row(result);
	NodeModel node;
	node.id = atoi(row[0]);
	node.x = atoi(row[1]);
	node.y = atoi(row[2]);
	node.type = atoi(row[3]);
	return node;
}



bool NodeDao::checkLocation(int x, int y) {
	string xs = to_string(x);
	string ys = to_string(y);
	string query = "SELECT count(n.id) FROM nodes as n WHERE (abs(" + xs + "-n.x)<45) AND (abs(" + ys + "-n.y)<45)";
	MYSQL_RES* result = db.query(query);
	MYSQL_ROW row = mysql_fetch_row(result);
	int count = atoi(row[0]);
	return count == 0;
}

int NodeDao::findNodeId(int x, int y) {
	string xs = to_string(x);
	string ys = to_string(y);
	string query = "SELECT n.id FROM nodes as n WHERE n.x=" + xs + " AND n.y=" + ys;
	MYSQL_RES* result = db.query(query);
	MYSQL_ROW row = mysql_fetch_row(result);
	return atoi(row[0]);
}


void NodeDao::removeNode(int id) {
	string ids = to_string(id);
	string query = "DELETE FROM nodes WHERE nodes.id=" + ids;
	db.query(query);
}

