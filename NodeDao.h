#pragma once
#include <mysql.h>
#include "NodeModel.cpp"
#include "ManagerConnector.h"
#include <list>
using namespace std;

class NodeDao {
private:
	ManagerConnector& db = ManagerConnector::getManagerConnector();
	NodeDao();
	NodeDao(const NodeDao&);
	NodeDao& operator=(NodeDao&);
public:
	static NodeDao& getNodeDao();
	list<NodeModel> findAll();
	NodeModel createNew(NodeModel node);
	NodeModel findById(int id);
	void removeNode(int id);
	bool checkLocation(int x, int y);
	int findNodeId(int x, int y);
};
