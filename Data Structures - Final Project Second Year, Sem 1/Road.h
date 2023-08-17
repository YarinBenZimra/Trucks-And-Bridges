#pragma once
#pragma warning(disable : 4996) 

#include "List.h" 

const int NoBridges = 2000;
class Road
{
public:

	Road(int _numofroad = 0, float _minHeightBridge = NoBridges, Pair* maxheap = nullptr); /// C'tor road
	~Road();
	
	/// Get Functions ///

	List& GetList();
	int GetNumOfRoad() const;
	Pair* GetMaxHeapNode();
	float GetMinHeightBridge() const;

	/// Set Functions ///
	void SetNumOfRoad(int _NumRoad);
	void SetMaxHeapNode(Pair* p);
	void SetMinHeightBridge(float _minHeightBridge);
	
	
private:

	List m_list; // minimum heap of all the bridges a road has
	int m_NumRoad; // number of the road
	float m_minHeightBridge; // minimum height of bridge
	Pair* m_MaxHeapNode; // pointer to the minimum bridge in the maximum heap
	
};

