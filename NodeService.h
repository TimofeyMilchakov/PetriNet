#pragma once
#include <string>
#include "NodeModel.cpp"
#include "NodeDao.h"
#include "LineDao.h"

using namespace System;
using namespace std;

class NodeService
{
private:
	NodeDao& nodeDao= NodeDao::getNodeDao();
	LineDao& lineDao= LineDao::getLineDao();
	NodeService();
	NodeService(const NodeService&);
	NodeService& operator=(NodeService&);
public:
	static NodeService& getNodeService();
	NodeModel createNewNode(int x, int y,int type);
	list<NodeModel> getAll();
	void deleteNode(int id);
};