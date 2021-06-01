#include <iostream>
#include <random>
#include <cstring>

#define NODE_COUNT 6

#define UINT_MAX (unsigned int)(~0) >> 1

unsigned int EdgeCost[NODE_COUNT][NODE_COUNT]
{
	0, 2, 5, 1, UINT_MAX, UINT_MAX,
	2, 0, 3, 2, UINT_MAX, UINT_MAX,
	5, 3, 0, 3, 1, 5,
	1, 2, 3, 0, 1, UINT_MAX,
	UINT_MAX, UINT_MAX, 1, 1, 0, 2,
	UINT_MAX, UINT_MAX, 5, UINT_MAX, 2, 0
};



void Dijkstra(const unsigned int* const edgeCost, const size_t nodeCount, const size_t startIndex, unsigned int* resultDistance)
{
	bool* isVisted = new bool[nodeCount];
	std::memset(resultDistance, 0xFF, sizeof(unsigned int) * nodeCount);
	std::memset(isVisted, 0x00, sizeof(bool) * nodeCount);
	
	resultDistance[startIndex] = 0;
	int nextNode = startIndex;

	while (nextNode != -1)
	{
		isVisted[nextNode] = true;

		int minCost = UINT_MAX;
		size_t minIndex = -1;
		for (size_t i = 0; i < nodeCount; i++)
		{
			if (i == nextNode)
			{
				continue;
			}

			if (resultDistance[nextNode] + edgeCost[nextNode * nodeCount + i] < resultDistance[i])
			{
				resultDistance[i] = resultDistance[nextNode] + edgeCost[nextNode * nodeCount + i];
			}
			if (isVisted[i] == false && edgeCost[nextNode * nodeCount + i] < minCost)
			{
				minIndex = i;
			}
		}
		nextNode = minIndex;
	}
	delete[] isVisted;
}

int main()
{

	unsigned int resultDistance[NODE_COUNT];
	Dijkstra(*EdgeCost, NODE_COUNT, 0, resultDistance);

	std::cout << "Expected Result : 0 2 3 1 2 4" << '\n';

	std::cout << "Computed Result : ";
	for (size_t i = 0; i < NODE_COUNT; i++)
	{
		std::cout << resultDistance[i] << ' ';
	}

}