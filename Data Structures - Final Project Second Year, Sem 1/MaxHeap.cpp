#include "MaxHeap.h"
#include "exceptions.h"
#include "Road.h"

void MaxHeap::FixHeap(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	int hs = GetHeapSize();
	int ps = GetPhySize();
	Pair* data = GetData();

	if ((left < hs) && (data[left].height > data[node].height))
		max = left;

	else max = node;

	if ((right < hs) && (data[right].height > data[max].height))
		max = right;


	if (max != node)
	{
		Swap((data + node), (data + max));
		FixHeap(max);
	}
}

Pair MaxHeap::DeleteMax()
{

	int hs = GetHeapSize();
	Pair* data = GetData();

	if (hs < 1)
		throw exceptions("invalid input");

	Pair max = data[0];
	SetHeapSize(--hs);
	data[0] = data[hs];
	FixHeap(0);

	return max;

}

void MaxHeap::Insert(Pair item)
{
	int hs = GetHeapSize();
	int ps = GetPhySize();
	Pair* data = GetData();

	
	if (hs == ps)
	{
		ps *= 2;
		SetPhySize(ps);
		SetData(Realloc(data, ps));
		data = GetData();
	}

	int i = hs;
	SetHeapSize(++hs);

	while ((i > 0) && (data[Parent(i)].height < item.height))
	{
		data[i] = data[Parent(i)];
		data[i].road->SetMaxHeapNode(data + i);
		i = Parent(i);
		
	}

	data[i] = item;
	data[i].road->SetMaxHeapNode(data + i);



}


