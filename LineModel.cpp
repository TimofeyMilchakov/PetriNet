#pragma once

class LineModel
{
public:
	LineModel():id(-1),firstNode(-1),secondNode(-1) {};
	LineModel(int firstNode, int secondNode):id(0),firstNode(firstNode),secondNode(secondNode) {};
	int id;
	int firstNode;
	int secondNode;
};