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
	for (PetriNet<short>::Iterator itP = pNet->beginP(); itP != pNet->endP(); ++itP)
	{
		for (PetriNet<short>::Iterator itT = pNet->beginT(); itT != pNet->endT(); ++itT)
		{
			cout << itP.getPos() << itT.getPos() << pNet->atD(itP.getPos(), itT.getPos()) << pNet->atM(itP.getPos()) <<'\n';
		}
	}
	pNet->algorithm(3, 0);
	for (PetriNet<short>::Iterator itP = pNet->beginP(); itP != pNet->endP(); ++itP)
	{
		for (PetriNet<short>::Iterator itT = pNet->beginT(); itT != pNet->endT(); ++itT)
		{
			cout << itP.getPos() << itT.getPos() << pNet->atD(itP.getPos(), itT.getPos()) << pNet->atM(itP.getPos()) << '\n';
		}
	}
	system("pause");
	alloc->returnNet(pNet);
	return 0;
}