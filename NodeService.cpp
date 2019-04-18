#include "NodeService.h"


NodeService::NodeService() {
}

NodeService& NodeService::getNodeService()
{
	static NodeService theSingleInstance;
	return theSingleInstance;
}

NodeModel NodeService::createNewNode(int x, int y) {
	if (nodeDao.checkLocation(x, y)) {
		NodeModel node;
		node.x = (x);
		node.y = (y);
		return nodeDao.createNew(node);
	}
	NodeModel empty;
	empty.id = -1;
	return empty;
}

list<NodeModel> NodeService::getAll() {
	return nodeDao.findAll();
}

void NodeService::deleteNode(int id) {
	nodeDao.removeNode(id);
	lineDao.removeAllLinesByNodeId(id);
}

