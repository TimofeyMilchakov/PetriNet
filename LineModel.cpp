#pragma once

class LineModel
{
public:
	LineModel():id(0),firstNode(0),secondNode(0) {};
	LineModel(int firstNode, int secondNode):id(0),firstNode(firstNode),secondNode(secondNode) {};
	int id;
	int firstNode;
	int secondNode;
};