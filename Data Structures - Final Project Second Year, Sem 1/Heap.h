#pragma once 

class Road;
const int initSize = 1;

typedef struct
{
	Road* road; // key
	float height; // priority

} Pair;



class Heap
{
private:

	Pair* data;   // Points to data array.
	int heapSize; // Current log size of heap.
	int phySize; //  Current phisical size of heap.


public:


	Heap(int _phySize = initSize);  // C'tor Heap
	
	~Heap();   // D'tor Heap
	

	/// Get Functons ///

	int GetHeapSize() const;
	
	int GetPhySize() const;
	
	Pair* GetData();
	

	/// Set Functons ///

	void SetHeapSize(const int& _heapSize);
	
	void SetPhySize(const int& _phySize);
	
	void SetData(Pair* _data);
    

	int Left(int node); /// returns left child
	
	int Right(int node); ///returns right child
    
	int Parent(int node); /// returns parent
	
	void Swap(Pair* p1, Pair* p2); /// swap between pairs

	float Root() const; /// returns root's hieght
	
	void Print() const; /// Print heap nodes
	
	void copyArr(Pair* newArr, Pair* arr, int size); 
	
	Pair* Realloc(Pair* arr, int newSize);

};
		