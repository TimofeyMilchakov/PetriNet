#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;
class PetriNet
{
	short int sizeP, sizeT;
	unordered_map<short int, unordered_map<short int, short int>> net; //PxT матрица со значениями -1,0,1
	vector<short int> M; //матрица маркеров
public:
	PetriNet();
	virtual ~PetriNet();
	//bool correctNet();
	short int findT(short int p1, short int p2);
	bool transPossibility(short int p1, short int p2);
	void jump(short int t);
	vector<short int>  algorithm(short int p1, short int p2); //достижимость
};

