#pragma once

#include <vector>
#include <map>

inline void Swap(std::vector<int>& v, int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
/*
struct Data
{
	const int** Pointers = nullptr;
	int* Counts = nullptr;
};
*/
namespace lab6
{
	int Sum(const std::vector<int>& v);
	int Min(const std::vector<int>& v);
	int Max(const std::vector<int>& v);
	float Average(const std::vector<int>& v);
	int NumberWithMaxOccurrence(const std::vector<int>& v);
	void SortDescending(std::vector<int>& v);

	int GetNextPrimeNum(int n);
	
	void SortRecursive(std::vector<int>& v, int left, int right);
	int GetPivot(std::vector<int>& v, int left, int right);
}
