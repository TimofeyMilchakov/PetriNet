#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;
class PetriNet
{
	
	unordered_map<short int, unordered_map<short int, short int>> net; //PxT матрица со значениями -1,0,1
	unordered_map<short int, short int> M; //матрица маркеров
public:
	short int sizeP, sizeT;
	PetriNet();
	virtual ~PetriNet();
	//bool correctNet();
	short int findT(short int p1, short int p2);
	bool transPossibility(short int p1, short int p2);
	void jump(short int t);
	void algorithm(short int pBegin, short int pEnd);
	void addD(short int p, short int t, short int d);
	void addM(short int p, short int val);
	void addP(short int p);
	void addT(short int t);
	short int atD(short int p, short int t);
	short int atM(short int p);
};

