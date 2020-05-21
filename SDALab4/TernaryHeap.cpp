#include "TernaryHeap.h"
#include <iostream>
#include <vector>
#include "HeapIterator.h"

using namespace std;

TernaryHeap::TernaryHeap(Relation r) {
	/*
	heap constructor

	Complexity: O(1)
	*/
	cap = 1;
	len = 0;
	elems = new TElem[cap];
	rel = r;
}

void TernaryHeap::add(TElem e) {
	/*
	adds an element to the list according to the existing relation

	Complexity: O(log2n)
	*/
	if (len == cap - 1) { //heap needs to be enlarged
		resize();
	}
	int leaf = len;
	len += 1;
	while (leaf != 0 && (rel(elems[(leaf - 1) / 3], e))) {
		elems[leaf] = elems[(leaf - 1) / 3]; //switching the values of the elements in the heap
		leaf = (leaf - 1) / 3; //carrying on to the father
	}
	elems[leaf] = e;
}

int TernaryHeap::size() const {
	/*
	returns the number of elements in the list

	Complexity: O(1)
	*/
	return len;
}

void TernaryHeap::resize() {
	/*
	doubles the capacity of the heap

	Complexity: O(n)
	*/
	TElem* temp = new TElem[2 * cap];
	for (int i = 0; i < len; i++) { //copying the elements of the heap to a temporary array
		temp[i] = elems[i];
	}
	delete[] elems;
	elems = temp;
	cap = cap * 2;
}

HeapIterator TernaryHeap::iterator() {
	/*
	creates an iterator object for the heap

	Complexity: O(1)
	*/
	return HeapIterator(*this);
}

TernaryHeap::~TernaryHeap() {
	/*
	destructor

	Complexity: O(1)
	*/
	delete[] elems;
}