#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;
namespace alg {
	template<typename V>
	class PetriNet
	{

		unordered_map<V, unordered_map<V, short>> net; //PxT матрица со значениями -1,0,1
		unordered_map<V, short> M; //матрица маркеров
		size_t sizeP, sizeT;


	public:
		class Iterator : std::iterator<std::input_iterator_tag, V>
		{
		public:
			Iterator(V pos, size_t count, unordered_map<V, short> map); //позиция, количество
			Iterator(const Iterator& it);
			Iterator& operator ++ ();
			typename Iterator& operator *() const;
			V getPos();
			bool operator!=(Iterator const& other) const;

		private:
			size_t _count;
			V _pos;
			vector<V> _keys;
		};
		Iterator beginP() { return Iterator(0, sizeP, M); }
		Iterator endP() { return Iterator(sizeP, sizeP, M); }
		Iterator beginT() { return Iterator(0, sizeT, net[0]); }
		Iterator endT() { return Iterator(sizeT, sizeT, net[0]); }

		PetriNet();
		virtual ~PetriNet();
		//bool correctNet();
		V findT(V p1, V p2);
		bool transPossibility(V p1, V p2);
		void jump(V t);
		vector<V> algorithm(V pBegin, V pEnd);
		void addD(V p, V t, V d);
		void addM(V p, V val);
		void addP(V p);
		void addT(V t);
		V atD(V p, V t);
		V atM(V p);
		void deleteP(V p);
		void deleteT(V p);
	};


	template<typename V>
	PetriNet<V>::Iterator::Iterator(V pos, size_t count, unordered_map<V, short> map)
	{
		_pos = pos;
		_count = count;
		_keys.reserve(map.size());
		for (auto kv : map) {
			_keys.push_back(kv.first);
		}
	}
	template<typename V>
	PetriNet<V>::Iterator::Iterator(const Iterator& it)
	{
		_pos = it->getPos();
	}
	template<typename V>
	typename PetriNet<V>::Iterator& PetriNet<V>::Iterator::operator ++()
	{
		if (_pos >= _count)
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

		PetriNet<V>* getNet(); //получить

		void returnNet(PetriNet<V>* net); //вынуть

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
			//THROW_ALLOCATOR_EXCEPTION("can't find returned value in pool!"); - добавить
			return;
		}

		_pool.erase(pos);
		delete net;
	}


	template<typename V>
	void Allocator<V>::returnAll()
	{
		for (auto i : _pool) { delete i; };
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
	bool PetriNet<V>::transPossibility(V p1, V p2) //возможность перехода
	{
		bool b;
		V T = findT(p1, p2);
		if (T > -1 ) {
			b= true;
		}
		else
			b = false;
		return b;
	}
	template<typename V>
	V PetriNet<V>::findT(V p1, V p2) //ищем переход
	{
		for (auto t : net[p1]) {
			if (net[p2].at(t.first) > 0)
				return t.first;
		}
		return -1;

	}
	template<typename V>
	void PetriNet<V>::jump(V T) //используем переход
	{
		bool marker = false; V p;
		for (Iterator itP = beginP(); itP != endP(); ++itP)
		{  //доступные позиции
			p = itP.getPos();
			if (net.find(p) == net.end()) continue;
			if (net[p][T] < 0 && M[p]>0)
			{
				M[p]--; marker = true;
			}
		}
		if (marker)
			for (Iterator itP = beginP(); itP != endP(); ++itP)
			{
				p = itP.getPos();
				if (net.find(p) == net.end()) continue;
				if (net[p][T] > 0)
				{
					M[p]++;
				}
			}
	}

	template<typename V>
	vector<V> PetriNet<V>::algorithm(V pBegin, V pEnd) //путь из p1 в p2
	{
		vector<V>  T, P;
		V p1 = pBegin, p2, p;
		bool b = false;
		for (Iterator itP = beginP(); itP != endP(); ++itP)
		{
			p = itP.getPos();
			if (net.find(p) == net.end()) continue;
			p2 = p;
			b = transPossibility(p1, p2);
			if (p2 == pEnd && b)
			{
				T.push_back(findT(p1, p2)); //по какому t
				P.push_back(p1);
				for (int i = 0; i < T.size(); i++)
				{
					jump(T[i]);
				}
				P.insert(P.end(), T.begin(), T.end()); //сначала P, потом T
				return P; 
			}
			if (b)
			{
				T.push_back(findT(p1, p2));
				P.push_back(p1); //откуда
				p1 = p2;
				p = -1;
				b = false;
			}
			else 
			{
				if (p1 != p) {
					p = p1;
					if (T.empty() && P.empty()) {
						continue;
					}
					else {
						T.pop_back(); P.pop_back();
						p1 = P[P.size() - 1];
					}
				}
			}
		}
		return {};  //пустой вектор
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
			}
		if (t > 0) sizeT++;
	}

	template<typename V>
	void PetriNet<V>::deleteP(V p)
	{
		const int P = p;
		net.erase(p);
		M.erase(p);
	}
	template<typename V>
	void PetriNet<V>::deleteT(V t)
	{
		const int T = t;
		for (Iterator itP = beginP(); itP != endP(); ++itP)
		{
			net[itP.getPos()].erase(t);
		}
	}


	template<typename V>
	void PetriNet<V>::addD(V p, V t, V d)
	{
		if ((net.find(p) != net.end()) && (net[p].find(t) != net[p].end())) {
			const int P = p;
			const int T = t;
			if (M.count(P) > 0)
				if (net[0].count(T) > 0)
					net[p][t] = d;
		}
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
		if ((net.find(p) != net.end()) && (net[p].find(t) != net[p].end()))
			return net[p][t];
		else return 0;
	}
	template<typename V>
	V PetriNet<V>::atM(V p)
	{
		if (M.find(p) != M.end())
			return M[p];
	}
}