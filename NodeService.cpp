#include "NodeService.h"


NodeService::NodeService() {
}

bool NodeService::check(int x, int y, NodeModel* node)
{
	return abs(node->x-x)<25&& abs(node->y - y) < 25;
}

NodeService& NodeService::getNodeService()
{
	static NodeService theSingleInstance;
	return theSingleInstance;
}

NodeModel* NodeService::createNewNode(int x, int y, int type, list<NodeModel*>* nodes)
{
	list<NodeModel*>::iterator it;
	for (it = nodes->begin(); it != nodes->end(); it++) {
		if (check(x, y, *it)) {
			return nullptr;
		}
	}
	return new NodeModel(++maxId,x,y,type);
}

void NodeService::deleteNode(int id, list<NodeModel*>* nodes, list<LineModel*>* lines)
{
	list<NodeModel*>::iterator it;
	for (it = nodes->begin(); it != nodes->end(); it++) {
		if ((*it)->id==id) {
			nodes->remove(*it);
			lineService.deleteLinesByNodeId(id, lines);
			return;
		}
	}
}

void NodeService::refresh(list<NodeModel*>* nodes)
{
	int max = this->maxId;
	list<NodeModel*>::iterator it;
	for (it = nodes->begin(); it != nodes->end(); it++) {
		if (max < (*it)->id) {
			max = (*it)->id;
		}
	}
	this->maxId = max;
}


void NodeService::incrNode(int id,list<NodeModel*>* nodes)
{
	list<NodeModel*>::iterator it;
	for (it = nodes->begin(); it != nodes->end(); it++) {
		if ((*it)->id == id && (*it)->type == 1) {
			(*it)->size++;
		}
	}
}

NodeModel* NodeService::getNodeById(int id, list<NodeModel*>* nodes)
{
	list<NodeModel*>::iterator it;
	for (it = nodes->begin(); it != nodes->end(); it++) {
		if ((*it)->id == id) {
			return (*it);
		}
	}
	return nullptr;
}


