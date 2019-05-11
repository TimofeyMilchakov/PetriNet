#pragma once
#include <ostream>
#include <istream>

using namespace std;


class NodeModel {
public:
	NodeModel(int id, int x, int y, int type) :id(id), x(x), y(y), type(type) {};
	NodeModel(int id, int x, int y, int type, int size) :id(id), x(x), y(y), type(type),size(size) {};
	int id;
	int type;
	int x;
	int y;
	int size = 0;


	friend ostream& operator<<(ostream& os, const NodeModel& obj)
	{
		// write obj to stream
		os << "node"<<endl;
		os << obj.id<<endl;
		os << obj.type << endl;
		os << obj.x << endl;
		os << obj.y << endl;
		os << obj.size << endl;
		return os;
	}
	friend istream& operator>>(istream& is, NodeModel*& obj)
	{
		int id;
		int type;
		int x;
		int y;
		int size;
		is>>id;
		is>>type;
		is>>x;
		is>>y;
		is>>size;
		obj = new NodeModel(id, x, y, type,size);
		return is;
	}

	bool equals(NodeModel* n) {
		return n->id == this->id;
	}
};
