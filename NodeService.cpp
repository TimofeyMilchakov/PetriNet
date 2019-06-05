#include "NodeService.h"


NodeService::NodeService() {
}

bool NodeService::check(int x, int y, NodeModel* node)
{
	return abs(node->x-x)<25&& abs(node->y - y) < 25;
}

bool NodeService::validateNode(NodeModel* node)
{
	return node!=nullptr && node->id >= 0 && node->x > 0 && node->y > 0 && (node->type == 1 || node->type == 2) && node->size >= 0;
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


void NodeService::changeSizeNode(int id, list<NodeModel*>* nodes, bool add)
{
	NodeModel* node = getNodeById(id, nodes);
	
		if (node && node->type == 1) {
			if (add) {
				node->size++;
			}
			else {
				node->size = node->size > 0 ? node->size - 1 : 0;
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

bool NodeService::validateData(list<NodeModel*>* nodes, list<LineModel*>* lines)
{
	for (NodeModel* node : *nodes) 
	{
		if (!validateNode(node)) {
			return false;
		}
	}
	for (LineModel* line : *lines) {
		NodeModel* f = getNodeById(line->firstNode, nodes);
		NodeModel* s = getNodeById(line->secondNode, nodes);
		if (!f || !s || f->type == s->type) {
			return false;
		}
	}
	return true;
}


