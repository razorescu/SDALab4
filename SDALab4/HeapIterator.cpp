#include "TernaryHeap.h"
#include "HeapIterator.h"
#include <iostream>

HeapIterator::HeapIterator(const TernaryHeap& heap) : heap(heap) {
	/*
	heap iterator ctor
	sets index to -1 if the heap is empty
	sets it to the top otherwise

	Complexity: O(1)
	*/
	if (heap.size() == 0) {
		index = -1;
	}
	else
		index = 0;
}

bool HeapIterator::valid() const {
	/*
	index validator
	returns true if at a valid position
	returns false otherwise

	Complexity: O(1)
	*/
	if (index < 0 || index >= heap.size())
		return false;
	return true;
}

void HeapIterator::top() {
	/*
	sets the iterator index to the top of the heap

	Complexity: O(1)
	*/
	index = 0;
}

TElem HeapIterator::getCurrent() const {
	/*
	returns the element the index is at in the heap

	Complexity: O(1)
	*/
	return heap.elems[index];
}

void HeapIterator::next() {
	/*
	sets index to the next element in the heap

	Complexity: O(1)
	*/
	if (valid()) {
		index++;
	}
}