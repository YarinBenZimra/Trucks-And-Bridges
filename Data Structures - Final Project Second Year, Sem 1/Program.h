#pragma once

#include "MaxHeap.h"

const int Too_High = 0;



class Program
{
	friend class Road;

public:

	Program();  /// C'tor Program
	
	~Program(); /// D'tor program

	/// Set Functions ///

	void SetNumOfRoads(int roads);

	void SetNumOfOperations(int _operations);
	
	void Init(); /// Initializes class program

	void AddBridge(float h, int r);

	void WhichRoad(float height); 

	void Menu(); /// Manages interface with the user

	void isCorrectChar(char c); /// Input integrity check function for char

	void CheckHeight(float h); /// Input integrity check function for height
	
	void CheckNumOfRoads(int r); /// Input integrity check function for num of roads 
	


private:

	Road* arr;  /// array of roads, contains list of all the bridges of some road
									// pointer to it's position in the maxHeap
									// number of the road
	MaxHeap m_MaxHeap; /// maxHeap of the all minimum bridges of each road
	int NumOfOperations; /// number of operations 
	int NumOfRoads; /// number of roads

};



