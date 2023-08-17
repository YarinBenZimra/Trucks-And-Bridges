#pragma once


#include "Heap.h"

class MaxHeap: public Heap
{
public:

	void FixHeap(int node);  
	
	/// regular FixHeap of heap, 
	///in addition we add swap between the pointers of the data member in road 
	///that contains pointer to the minimum bridge of road in the maxHeap

	Pair DeleteMax();

	void Insert(Pair item); 
	
	/// regular insert of heap, 
	///in addition we add swap between the pointers of the data member in road 
	///that contains pointer to the minimum bridge of road int the maxHeap

};
