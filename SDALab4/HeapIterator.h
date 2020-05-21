#pragma once
#include "TernaryHeap.h"

class HeapIterator {
	friend class TernaryHeap;

private:
	const TernaryHeap& heap;
	HeapIterator(const TernaryHeap& heap);
	int index;

public:
	//sets the iterator at the top of the heap
	void top();
	
	//sets iterator to next index in the heap
	void next();

	//tests if the iterator is at a valid position
	bool valid() const;
	
	//returns current element in the heap
	TElem getCurrent() const;
};