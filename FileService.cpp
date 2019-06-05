#include "FileService.h"



FileService& FileService::getFileService()
{
	static FileService theSingleInstance;
	return theSingleInstance;
}

FileService::FileService()
{
}

string FileService::saveFile(string fileName, list<NodeModel*>* nodes, list<LineModel*>* lines)
{
	
		ofstream myfile;
		myfile.open(fileName, ios::binary);
		if (!myfile.is_open()) {
			return string("��������� ������� ����");
		}
		for (list<NodeModel*> ::iterator it = nodes->begin(); it != nodes->end(); it++) {

			myfile << *(*it);
		}
		for (list<LineModel*> ::iterator it = lines->begin(); it != lines->end(); it++) {
			myfile << *(*it);
		}		
		myfile.close();
		return string("������ ������� ���������");
}

bool FileService::loadFile(string fileName, list<NodeModel*>* nodes, list<LineModel*>* lines)
{
	ifstream myfile;
	myfile.open(fileName, ios::binary);
	int test = 0;
	nodes->clear();
	lines->clear();
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			string type;
			myfile >> type;
			if (type == "node") 
			{
				NodeModel* node = nullptr;
				myfile >> node;
				nodes->push_back(node);
				continue;
			}
			if (type == "line")
			{
				LineModel* line;
				myfile >> line;
				lines->push_back(line);
				continue;
			}
			test++;
			if (test > 5) {
				myfile.close();
				return false;
			}
		}
		myfile.close();
		return true;
	}
	else 
	{
		return false;
	}
}
