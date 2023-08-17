#include "Program.h"
#include "Road.h"


Road::Road(int _numofroad, float _minHeightBridge, Pair* _MaxHeapNode) : m_minHeightBridge(_minHeightBridge) { ; }

Road::~Road() { ; }

int Road::GetNumOfRoad() const { return m_NumRoad; }

List& Road::GetList() { return m_list; }

Pair* Road::GetMaxHeapNode() { return m_MaxHeapNode; }

void Road::SetMaxHeapNode(Pair* p) { m_MaxHeapNode = p; }

void Road::SetNumOfRoad(int _NumRoad) { m_NumRoad = _NumRoad; }

float Road::GetMinHeightBridge() const { return m_minHeightBridge; }

void Road::SetMinHeightBridge(float _minHeightBridge) { m_minHeightBridge = _minHeightBridge; }
