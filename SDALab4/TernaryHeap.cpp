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
	if (len == cap - 1) { //heap needs to be enlarged
		resize();
	}
	int leaf = len;
	len += 1;
	while (leaf != 0 && rel(elems[(leaf - 1) / 3], e)) {
		elems[leaf] = elems[(leaf - 1) / 3]; //switching the values of the elements in the heap
		leaf = (leaf - 1) / 3; //carrying on to the father
	}
	elems[leaf] = e;
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

TernaryHeap::~TernaryHeap() {
	/*
	destructor
	*/
	delete[] elems;
}