#pragma once
#include <vector>
#include <utility>

using namespace std;

class HeapIterator;

typedef int TElem;
typedef bool(*Relation) (TElem e1, TElem e2);
#define NULL_TElem -111111;

class TernaryHeap {
	private:
		int cap; //capacity
		int len; //amount of elements
		TElem* elems; //element array
		Relation rel; //relation
		friend class HeapIterator; //iterator class
		
	public:
		//constructor
		TernaryHeap(Relation r);

		//adds an element by relation
		void add(TElem e);

		//returns the size of the list
		int size() const;

		//doubles the capacity of the heap
		void resize();

		//returns an iterator object for the heap
		HeapIterator iterator();

		//destructor
		~TernaryHeap();
};