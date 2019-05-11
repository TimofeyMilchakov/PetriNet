#pragma once
#include "NodeModel.h"
#include <ostream>
#include <istream>

using namespace std;

class LineModel
{
public:
	LineModel(int id, int firstNode, int secondNode):id(0),firstNode(firstNode),secondNode(secondNode) {};
	int id;
	int firstNode;
	int secondNode;

	friend ostream& operator<<(ostream& os, const LineModel& obj)
	{
		// write obj to stream
		os << "line"<<endl;
		os << obj.id<<endl;
		os << obj.firstNode << endl;
		os << obj.secondNode << endl;
		return os;
	}
	friend istream& operator>>(istream& is, LineModel*& obj)
	{
		// read obj from stream
		int id;
		int firstNode;
		int secondNode;
		is>> id;
		is >> firstNode;
		is >> secondNode;
		obj = new LineModel(id, firstNode, secondNode);
		return is;
	}
	bool equals(LineModel* l) {
		return l->id == this->id && l->firstNode == this->firstNode && l->secondNode == this->secondNode;
	}
};