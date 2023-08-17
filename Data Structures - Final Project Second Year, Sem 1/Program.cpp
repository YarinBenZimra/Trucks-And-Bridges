#include "Program.h"
#include "Road.h"
#include <iostream>
#include "exceptions.h"
#include "List.h"
#include "ListNode.h"
#include <string>

using namespace std;

Program::Program() { ; }

Program::~Program()
{
	delete[] arr;
}

void Program::SetNumOfRoads(int _roads)
{
	if (_roads < 0)
	{
		cin.ignore();
		throw exceptions("invalid input");
	}
	
	NumOfRoads = _roads;
}

void Program::SetNumOfOperations(int _operations)
{
	if (_operations < 1)
	{
		cin.ignore();
		throw exceptions("invalid input");
	}
	NumOfOperations = _operations;
}

void Program::Init()
{
	arr = new Road[NumOfRoads];
	m_MaxHeap.SetData(m_MaxHeap.Realloc(m_MaxHeap.GetData(), NumOfRoads));
	m_MaxHeap.SetPhySize(NumOfRoads);
	m_MaxHeap.SetHeapSize(NumOfRoads);


	for (int i = 0; i < NumOfRoads; i++)
	{
		arr[i].SetNumOfRoad(i + 1);
		m_MaxHeap.GetData()[i].height = arr[i].GetMinHeightBridge();
		m_MaxHeap.GetData()[i].road = arr + i;
		arr[i].SetMaxHeapNode(m_MaxHeap.GetData() + i);
	}
}
void Program::AddBridge(float h, int r)
{
	float currHeight = arr[r - 1].GetMinHeightBridge();

	arr[r - 1].GetList().CreateNewListNode(h);

	if (h < currHeight) // if the new bridge is the minimum we insert it to the maximum heap
	{
		arr[r - 1].SetMinHeightBridge(h);
		arr[r - 1].GetMaxHeapNode()->height = h;
		m_MaxHeap.FixHeap(((arr[r - 1]).GetMaxHeapNode()) - m_MaxHeap.GetData());
		//We calculate the position in the maximum heap of the node that was replaced in order to perform a fix heap from the following position.
	}

}
void Program::WhichRoad(float height)
{
	if(NumOfRoads==0)
	{
		std::cout << Too_High << endl;
	}
	else
	{
		Pair p = (m_MaxHeap.GetData())[0];

		if (height < p.height)
			std::cout << p.road->GetNumOfRoad() << endl;
		else
			std::cout << Too_High << endl;
	}
}

void Program::Menu()
{
	bool first = true;
	char c;
	float h;
	int r;
	string input;
	Pair* p;
	


	try
	{
		int roads, operations;
		cin >> roads;
		SetNumOfRoads(roads);

		cin >> operations;
		SetNumOfOperations(operations);

		cin.ignore();

		while (operations > 0)
		{
			getline(cin, input);
			c = input[0];
			
			if (first == true && c != 'a')
				throw exceptions("invalid input");

			if (first == false && c == 'a')
				throw exceptions("invalid input");
			
			first = false;
			isCorrectChar(c);
			input.erase(0, 1);

			switch (c)
			{

			case 'a' :
			{
				Init();
				break;
			}

			case 'b' :
			{
				
				sscanf(input.c_str(), "%f %d", &h, &r);
				CheckHeight(h);
				CheckNumOfRoads(r);
				
				AddBridge(h, r);
				
				break;
			}

			case 'c' :
			{
				sscanf(input.c_str(), "%f", &h);
				CheckHeight(h);
				WhichRoad(h);
				break;

			}


			case 'd' :
			{
				sscanf(input.c_str(), "%d", &r);
				CheckNumOfRoads(r);
				(arr[r - 1].GetList()).Print();
				break;

			}
			default:
				throw exceptions("invalid input");
				break;
			}

			operations--;
		}

	}

	catch(exceptions& ex)
	{
		cout << ex.what() << endl << endl;
	}
	
}

void Program::isCorrectChar(char c)
{
	if (c != 'a' && c != 'b' && c != 'c' && c != 'd')
		throw exceptions("invalid input");
}

void Program::CheckHeight(float h)
{
	if(h < 1)
		throw exceptions("invalid input");
}

void Program::CheckNumOfRoads(int r)
{
	if(r < 1 || r > NumOfRoads) 
		throw exceptions("invalid input");
		
}