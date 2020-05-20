#include "TernaryHeap.h"
#include <iostream>
#include <vector>

using namespace std;

TernaryHeap::TernaryHeap(Relation r) {
	/*
	heap constructor
	*/
	cap = 1;
	len = 0;
	elems = new TElem[cap];
	rel = r;
}

void TernaryHeap::add(TElem e) {
	/*
	adds an element to the list according to the existing relation
	*/
}

int TernaryHeap::size() const {
	/*
	returns the number of elements in the list
	*/
	return len;
}

void TernaryHeap::resize() {
	/*
	doubles the capacity of the heap
	*/
	TElem* temp = new TElem[2 * cap];
	for (int i = 0; i < len; i++) {
		temp[i] = elems[i];
	}
	delete[] elems;
	elems = temp;
	cap = cap * 2;
}