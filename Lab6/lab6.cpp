#include <cassert>
#include "Lab6.h"

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
		int size = v.size();

		if (size == 0)
		{
			return 0;
		}
		
		Data data;
		data.Pointers = new const int* [size];
		data.Counts = new int[size];

		for (int i = 0; i < size; ++i)
		{
			data.Pointers[i] = nullptr;
			data.Counts[i] = 1;
		}
		
		data.Pointers[0] = &v[0];

		int pointersCount = 1;

		bool bSame;

		for (int i = 1; i < size; ++i)
		{
			bSame = false;

			for (int j = 0; j < pointersCount; ++j)
			{
				if (*data.Pointers[j] == v[i])
				{
					data.Counts[j]++;
					bSame = true;
					break;
				}
			}

			if (bSame == false)
			{
				data.Pointers[pointersCount++] = &v[i];
			}
		}

		int maxIndex = 0;

		for (int i = 1; i < pointersCount; ++i)
		{
			if (data.Counts[maxIndex] < data.Counts[i])
			{
				maxIndex = i;
			}
		}

		int result = *data.Pointers[maxIndex];

		delete[] data.Counts;
		delete[] data.Pointers;

		return result;
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

	int GetNextPrimeNum(int n)
	{
		assert(n >= 1);

		--n;

		while (true)
		{
			bool bPrimeNum = true;
			n += 2;
			int end = n / 2;

			for (int i = 2; i < end; ++i)
			{
				if (n % i == 0)
				{
					bPrimeNum = false;
					break;
				}
			}

			if (bPrimeNum == true)
			{
				return n;
			}
		}
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