#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

template<typename V>
class PetriNet
{
	
	unordered_map<V, unordered_map<V, V>> net; //PxT ������� �� ���������� -1,0,1
	unordered_map<V, V> M; //������� ��������
	size_t sizeP, sizeT; 
	

public:
	class Iterator: std::iterator<std::input_iterator_tag, V>
	{
	public:
		Iterator(V pos, size_t count); //�������, ����������
		Iterator(const Iterator& it);
		Iterator& operator ++ ();
		typename Iterator& operator *() const;
		V getPos();
		bool operator!=(Iterator const& other) const;

	private:
		size_t _count;
		V _pos;
	};
	Iterator beginP() { return Iterator(0, sizeP); }
	Iterator endP() { return Iterator(sizeP, sizeP); }
	Iterator beginT() { return Iterator(0, sizeT); }
	Iterator endT() { return Iterator(sizeT, sizeT); }

	PetriNet();
	virtual ~PetriNet();
	//bool correctNet();
	V findT(V p1, V p2);
	bool transPossibility(V p1, V p2);
	void jump(V t);
	void algorithm(V pBegin, V pEnd);
	void addD(V p, V t, V d);
	void addM(V p, V val);
	void addP(V p);
	void addT(V t);
	V atD(V p, V t);
	V atM(V p);
};


template<typename V>
PetriNet<V>::Iterator::Iterator(V pos, size_t count)
{
	_pos = pos;
	_count = count;
}
template<typename V>
PetriNet<V>::Iterator::Iterator(const Iterator& it)
{
	_pos = it->getPos();
}
template<typename V>
typename PetriNet<V>::Iterator& PetriNet<V>::Iterator::operator ++()
{
	if (_pos >= _count )
	{
		//THROW_MG_NULL_POINTER_EXCEPTION("Null pointer exception, increment > size!");
		return *this;
	}
	++_pos;
	return *this;
}

template<typename V>
typename PetriNet<V>::Iterator& PetriNet<V>::Iterator::operator *() const
{
	if (_pos == _count)
	{
		//THROW_MG_NULL_POINTER_EXCEPTION("Null pointer exception, Try access to last NULL element!");
		return NULL;
	}
	return *_pos;
}
template<typename V>
bool PetriNet<V>::Iterator::operator!=(Iterator const& other) const
{
	return _pos != other._pos;
}
template<typename V>
V PetriNet<V>::Iterator::getPos()
{
	return _pos;
}



template<typename V>
class Allocator
{
public:
	Allocator() {}
	virtual ~Allocator();

	PetriNet<V>* getNet(); //��������

	void returnNet(PetriNet<V>* net); //������

	void returnAll();

private:
	std::list<PetriNet<V>*> _pool;
};


template<typename V>
Allocator<V>::~Allocator()
{
	returnAll();
}

template<typename V>
PetriNet<V>* Allocator<V>::getNet()
{
	PetriNet<V>* newNet = new PetriNet<V>();
	_pool.push_back(newNet);
	return newNet;
}

template<typename V>
void Allocator<V>::returnNet(PetriNet<V>* net)
{
	auto pos = std::find(_pool.begin(), _pool.end(), net);

	if (pos == _pool.end())
	{
		//THROW_ALLOCATOR_EXCEPTION("can't find returned value in pool!"); - ��������
		return;
	}

	_pool.erase(pos);
	delete net;
}


template<typename V>
void Allocator<V>::returnAll()
{
	for(auto i :_pool) {delete i; };
	_pool.clear();
}


template<typename V>
PetriNet<V>::PetriNet()
{
	//init
	net[0][0] = 0; M[0] = 0;
	sizeP = 1; sizeT = 1;
}
template<typename V>
PetriNet<V>::~PetriNet()
{
}

//bool PetriNet::correctNet() {
//	for (V p=0;p<sizeP-1;p++)
//		for (V t=0; t<sizeT;t++)
//		if(net[p][t] !=0)
//}
template<typename V>
bool PetriNet<V>::transPossibility(V p1, V p2) //����������� ��������
{
	V T = findT(p1, p2);
	if (T > -1 && M[p1] > 0) {
		return true;
	}
	return false;
}
template<typename V>
V PetriNet<V>::findT(V p1, V p2) //���� �������
{
	for (auto t : net[p1])
		if (net[p2].at(t.first) > 0)
			return t.first;
	return -1;

}
template<typename V>
void PetriNet<V>::jump(V T) //���������� �������
{
	bool marker = false;
	for (Iterator itP = beginP(); itP != endP(); ++itP)
	{  //��������� �������
		V p=itP.getPos();
		if (net[p][T] < 0 && M[p]>0)
		{
			M[p]--; marker = true;
		}
	}
	if (marker)
		for (Iterator itP = beginP(); itP != endP(); ++itP)
		{  
			V p = itP.getPos();
			if (net[p][T] > 0)
			{
				M[p]++;
			}
		}
}

template<typename V>
void PetriNet<V>::algorithm(V pBegin, V pEnd) //���� �� p1 � p2
{
	vector<V>  T, P;
	V p1 = pBegin, p2;
	bool b = false;
	for (Iterator itP = beginP(); itP != endP(); ++itP)
	{
		V p = itP.getPos();
		p2 = p;
		b = transPossibility(p1, p2);
		if (p2 == pEnd && b)
		{
			T.push_back(findT(p1, p2)); //�� ������ t
			for (int i = 0; i < T.size(); i++)
			{
				jump(T[i]);
			}
			break; //�� ��� ������ jump
		}
		if (b)
		{
			T.push_back(findT(p1, p2));
			P.push_back(p1); //������
			p1 = p2;
			p = -1;
		}
		else
		{
			p = p1;
			T.pop_back(); P.pop_back();
			p1 = P[P.size() - 1];
		}
	}
	//�������� ����� ���, ������� �� ��������
}
template<typename V>
void PetriNet<V>::addP(V p)
{
	const int P = p;
	if (M.count(P) == 0)
	{
		M[p] = 0;
		for (Iterator itT = beginT(); itT != endT(); ++itT)
		{
			V t = itT.getPos();
			net[p][t] = 0;
			sizeP++;
		}
	}
}
template<typename V>
void PetriNet<V>::addT(V t)
{
	const int T = t;
	if (net[0].count(T) == 0)
		for (Iterator itP = beginP(); itP != endP(); ++itP)
		{
			V p = itP.getPos();
			net[p][t] = 0;
			sizeT++;
		}
}

template<typename V>
void PetriNet<V>::addD(V p, V t, V d)
{
	const int P = p;
	const int T = t;
	if (M.count(P) > 0)
		if (net[0].count(T) > 0)
			net[p][t] = d;
}
template<typename V>
void PetriNet<V>::addM(V p, V val)
{
	const int P = p;
	if (M.count(P) > 0) M[p] = val;
}
template<typename V>
V PetriNet<V>::atD(V p, V t)
{
	return net[p][t];
}
template<typename V>
V PetriNet<V>::atM(V p)
{
	return M[p];
}