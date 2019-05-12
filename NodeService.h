#pragma once
#include <string>
#include "NodeModel.h"
#include "LineService.h"


using namespace System;
using namespace std;

class NodeService
{
private:
	NodeService();
	NodeService(const NodeService&);
	bool check(int x, int y, NodeModel* node);
	bool validateNode(NodeModel* node);
	int maxId = 0;
	LineService& lineService = LineService::getLineService();
public:
	static NodeService& getNodeService();
	NodeModel* createNewNode(int x, int y,int type, list<NodeModel*>* nodes);
	void deleteNode(int id, list<NodeModel*>* nodes, list<LineModel*>* lines);
	void refresh(list<NodeModel*>* nodes);
	void changeSizeNode(int id, list<NodeModel*>* nodes, bool add);
	NodeModel* getNodeById(int id, list<NodeModel*>* nodes);
	bool validateData(list<NodeModel*>* nodes, list<LineModel*>* lines);
};