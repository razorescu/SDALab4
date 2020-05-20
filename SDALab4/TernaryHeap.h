#pragma once
#include <vector>
#include <utility>

using namespace std;

typedef int TElem;
typedef bool(*Relation) (TElem e1, TElem e2);
#define NULL_TElem -111111;

class TernaryHeap {
	private:
		int cap;
		int len;
		
		Relation rel;

		
	public:
		//constructor
		TernaryHeap(Relation r);

		//adds an element by relation
		void add(TElem e);

		//returns the size of the list
		int size() const;

		//doubles the capacity of the heap
		void resize();

		//destructor
		~TernaryHeap();

		TElem* elems;
};