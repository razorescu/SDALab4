#include <vector>
#include "P12.h"
#include "TernaryHeap.h"
#include "HeapIterator.h"
#include <exception>
#include <algorithm>

using namespace std;

vector<TElem> firstK(vector<TElem> inputVector, Relation r, int k) {
	/*
	returns a vector of elements of type TElem that contains the first K elements according to the Relation R

	Complexity: O(n + k*n) 
	*/

	if (k <= 0) { //invalid case, throwing exception
		exception e;
		throw e;
	}
	if (k >= inputVector.size()) { //all elements returned if k greater or equal to input vector size
		return inputVector;
	}

	vector<TElem> greatest; //creating the vector we'll use for the return

	TernaryHeap heap(r); //calling heap ctor

	for (int i = 0; i < inputVector.size(); i++) {//adding inputVector elems to heap
		heap.add(inputVector[i]);
	}

	/*
	in mod normal le-as fi facut cum era intentionat, adica intr-o singura bucata in functie de R
	dar am avut probleme cu valorile pe care trebuiau sa le ia lastmax/lastmin si localmax/localmin
	asa ca am decis s-o fac mai "brutal"
	*/
	if (r(2, 1)) { //max elements
		HeapIterator heapit = heap.iterator();
		heapit.top();
		TElem lastmax = 30000; //variable used to ensure we get different maximum values
		TElem localmax = -32000; //variable used to save local maximum value
		TElem current; //current value in the heap
		int count = 0; //counter
		while (count < k) {
			while (heapit.valid()) {
				current = heapit.getCurrent();
				if (localmax < current && current < lastmax)
					localmax = current;
				heapit.next();
			}
		lastmax = localmax; //saving the maximum value we will be adding
		greatest.push_back(localmax); //adding maximum value to the vector
		localmax = -32000; //resetting local maximum value
		count++;
		heapit.top();
		}
	}
	else { //min elements
		HeapIterator heapit = heap.iterator();
		heapit.top();
		TElem lastmin = -30000; //variable used to ensure we get different minimum values
		TElem localmin = 32000; //variable used to save local minimum value
		TElem current; //current value in the heap
		int count = 0; //counter
		while (count < k) {
			while (heapit.valid()) {
				current = heapit.getCurrent();
				if (current < localmin && current > lastmin)
					localmin = current;
				heapit.next();
			}
		lastmin = localmin; //saving the minimum value we will be adding
		greatest.push_back(localmin); //adding minimum value to the vector
		localmin = 32000; //resetting local maximum value
		count++;
		heapit.top();
		}
	}

	return greatest;

}