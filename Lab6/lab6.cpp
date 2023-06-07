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
			return 0x7FFF;
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
			return 0x8000;
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

		return sum / size;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		int size = v.size();

		if (size == 0)
		{
			return 0;
		}

		for (int i = 0; i < size; ++i)
		{
			assert(v[i] != INT_MIN);
		}

		Data data;
		data.length = size << 1;
		data.length = GetNextPrimeNum(data.length);

		data.nums = new int[data.length];
		data.counts = new int[data.length];

		for (int i = 0; i < data.length; ++i)
		{
			data.nums[i] = INT_MIN;
			data.counts[i] = 1;
		}

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			int hash = *iter % data.length;
			assert(AddValue(data, hash) == true);
		}

		int maxValueIndex = 0;

		for (int i = 1; i < data.length; ++i)
		{
			if (data.counts[maxValueIndex] < data.counts[i + 1])
			{
				maxValueIndex = i + 1;
			}
		}

		int result = data.nums[maxValueIndex];

		delete[] data.nums;
		delete[] data.counts;

		return result;
	}
	bool AddValue(Data& data, int hash)
	{
		if (hash < 0)
		{
			hash += data.length;
		}

		int start = hash;

		do
		{
			if (data.nums[hash] == hash)
			{
				data.counts[hash]++;
				return true;
			}
			else if (data.nums[hash] == INT_MIN)
			{
				data.nums[hash] = hash;
				return true;
			}

			hash = ++hash % data.length;

		} while (hash != start);

		return false;
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