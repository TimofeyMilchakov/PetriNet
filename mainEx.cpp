#include "PetriNet.h"
#include <iostream>
using namespace std;

int main()
{
	Allocator<short>* alloc = new Allocator<short>();
	PetriNet<short int>* pNet = alloc->getNet();
	pNet->addP(0); pNet->addP(1); pNet->addP(2); pNet->addP(3);
	pNet->addT(0); pNet->addT(1);
	pNet->addD(0, 0, -1); 
	pNet->addD(1, 0, 1);
	pNet->addD(2, 0, 1);
	pNet->addD(3, 0, 0);
	pNet->addD(0, 1, 1);
	pNet->addD(1, 1, -1);
	pNet->addD(2, 1, -1);
	pNet->addD(3, 1, 1);
	pNet->addM(0, 1); pNet->addM(2, 2); pNet->addM(3, 1);
	for (int p = 0; p < pNet->sizeP; p++)
	{
		for (int t = 0; t < pNet->sizeT; t++)
		{
			cout << p << t << pNet->atD(p,t) << pNet->atM(p) <<'\n';
		}
	}
	pNet->algorithm(3, 0);
	for (int p = 0; p < pNet->sizeP; p++)
	{
		for (int t = 0; t < pNet->sizeT; t++)
		{
			cout << p << t << pNet->atD(p, t) << pNet->atM(p) << '\n';
		}
	}
	system("pause");
	alloc->returnNet(pNet);
	return 0;
}