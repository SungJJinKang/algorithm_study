#include <random>
#include <iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* partition(int* left, int* right)
{
	int* pivot = left;
	left++;

	do
	{
		while (*left < *pivot && left <= right)
		{
			left++;
		}

		while (*right > *pivot && left <= right)
		{
			right--;
		}

		if (left < right)
		{
			swap(left, right);
		}
	

	} while (left < right);

	swap(pivot, right);
	return right;
}

/// <summary>
/// Big(o)
/// 
/// Worst : O(n^2)
/// Average : O(n * log(n))
/// Best : O(n * log(n))
/// 
/// Space Complexity :
///  
/// Worst : O(n * log(n))
/// 
/// reference : https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html
/// </summary>
/// <param name="begin"></param>
/// <param name="end"></param>
void quickSort(int* begin, int* end)
{
	int* left = begin;
	int* right = end - 1;

	int* pivot = partition(left, right);

	if (pivot > left)
	{
		quickSort(left, pivot);
	}
	if (pivot < right)
	{
		quickSort(pivot + 1, right + 1);
	}
}

/// <summary>
/// Big(o)
/// 
/// Time Complexity : 
/// 
/// Worst : O(n^2)
/// Average : O(n^2)
/// Best : O(n)
/// 
/// Space Complexity :
///  
/// Worst : O(n)
/// 
/// refernce : https://gmlwjd9405.github.io/2018/05/06/algorithm-bubble-sort.html
/// </summary>
/// <param name="begin"></param>
/// <param name="end"></param>
void bubbleSort(int* begin, int* end)
{
	int* current = begin;
	int* back = end - 1;
	while (current < back)
	{
		while (current < back)
		{
			if (*current > *(current + 1))
			{
				swap(current, current + 1);
			}
			current++;
		}
		current = begin;
		back--;
	}
	
}

int main()
{
	int* a = new int[100];
	
	for (size_t i = 0; i < 100; i++)
	{
		a[i] = rand();
	}

	bubbleSort(a, a + 100);

	for (size_t i = 0; i < 100; i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
}