#include <cassert>
#include "Lab6.h"

using namespace std;

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			sum += *iter;
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		int length = v.size();

		if (length == 0)
		{
			return 0x7FFFFFFF;
		}

		int min = v[0];

		for (int i = 1; i < length; ++i)
		{
			if (min > v[i])
			{
				min = v[i];
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int length = v.size();

		if (length == 0)
		{
			return 0x80000000;
		}

		int max = v[0];

		for (int i = 1; i < length; ++i)
		{
			if (max < v[i])
			{
				max = v[i];
			}
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		int sum = Sum(v);
		float size = static_cast<float>(v.size());

		return size == 0 ? 0 : sum / size;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}
		
		vector<int> copied(v);

		SortDescending(copied);

		int maxCount = 1;
		int currCount = 1;
		vector<int>::const_iterator maxIt;
		vector<int>::const_iterator currIt;

		for (currIt = copied.begin(); currIt != copied.end() - 1; ++currIt)
		{
			vector<int>::const_iterator nextIt = currIt + 1;

			if (*nextIt == *currIt)
			{
				currCount++;
			}
			else if (currCount > maxCount)
			{
				maxCount = currCount;
				currCount = 1;
				maxIt = currIt;
			}
			else
			{
				currCount = 1;
			}
		}

		maxIt = currCount > maxCount ? currIt : maxIt;

		return *maxIt;
	}
	
	void SortDescending(std::vector<int>& v)
	{
		int size = v.size();

		if (size == 0)
		{
			return;
		}

		SortRecursive(v, 0, size - 1);
	}

	void SortRecursive(std::vector<int>& v, int left, int right)
	{
		if (left >= right)
		{
			return;
		}

		int pivot = GetPivot(v, left, right);

		SortRecursive(v, left, pivot - 1);
		SortRecursive(v, pivot + 1, right); // { 5, 6, 7, 12, 9, 1, -5, -8, 3 }, size = 9;
	}

	int GetPivot(std::vector<int>& v, int left, int right)
	{
		int pivot = v[right];

		for (int i = left; i < right; ++i)
		{
			if (v[i] > pivot)
			{
				Swap(v, i, left); 
				left++;
			}
		}

		Swap(v, right, left);

		return left;
	}
}