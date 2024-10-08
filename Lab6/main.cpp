#include <cassert>
#include <iostream>
#include "lab6.h"

using namespace lab6;
using namespace std;

void print(std::vector<int>& v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
}

int main()
{
#if 0
	vector<int> v = { 1, 2, 3 };

	int* p = &v[0];
	p++;
	cout << *p << endl;
	

#endif

#if 1
	std::vector<int> v = { 5, -9, 0, 10, 18, 7, -123, 99, 3, -9, 7, 7, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MAX };
	
	int sum = lab6::Sum(v); // 15
	int min = lab6::Min(v); // -123
	int max = lab6::Max(v); // 99
	float average = lab6::Average(v); // 1.25
	int occur = lab6::NumberWithMaxOccurrence(v); // 7

	std::cout << sum << " " << min << " " << max << " " << average << " " << occur << std::endl << std::endl;
	
	print(v);

	lab6::SortDescending(v);

	print(v);
	
#endif

	std::cout << "No Assert" << std::endl;

	return 0;
}