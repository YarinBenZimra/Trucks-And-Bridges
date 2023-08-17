#include "Heap.h"
#include "exceptions.h"
#include <iostream>
#include "Road.h"

Heap::Heap(int _phySize)
{
	data = new Pair[_phySize];
	heapSize = 0;
	phySize = initSize;
}

Heap::~Heap()
{
	delete[] data;
	data = nullptr;
}

int Heap::GetHeapSize() const { return heapSize; }

int Heap::GetPhySize() const { return phySize; }

Pair* Heap::GetData() { return data; }

void Heap::SetHeapSize(const int& _heapSize) { heapSize = _heapSize; }

void Heap::SetPhySize(const int& _phySize) { phySize = _phySize; }

void Heap::SetData(Pair* _data) { data = _data; }

int Heap::Parent(int node)
{
  return (node - 1) / 2;
}

int Heap::Left(int node)
{
	return (2 * node + 1);
}

int Heap::Right(int node)
{
	return (2 * node + 2);
}

void Heap::Swap(Pair* p1, Pair* p2)
{
	Pair* pTempMaxHeapNode = p1->road->GetMaxHeapNode();
	p1->road->SetMaxHeapNode(p2->road->GetMaxHeapNode());
	p2->road->SetMaxHeapNode(pTempMaxHeapNode);

	Pair temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
			
float Heap::Root() const { return data[0].height; }

void Heap::Print() const
{
	for (int i = 0; i < heapSize; i++)
		std::cout << data[i].height << std::endl;
}

Pair* Heap::Realloc(Pair* arr, int newSize)
{
	Pair* newArr = new Pair [newSize];

	copyArr(newArr, arr, newSize);

	delete[] arr;

	return newArr;
}

void  Heap::copyArr(Pair* newArr, Pair* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
}


