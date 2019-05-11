#pragma once
#include "LineModel.h"
#include "NodeModel.h"
#include <list>
#include <fstream>
#include <ostream>
#include <istream>

using namespace std;

class FileService
{
public:
	
	FileService();
	static FileService& getFileService();

	string saveFile(string fileName, list<NodeModel*>* nodes, list<LineModel*>* lines);
	bool loadFile(string fileName, list<NodeModel*>* nodes, list<LineModel*>* lines);

};

