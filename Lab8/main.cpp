#include <cassert>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;
using namespace std;

/*
void Print(FixedVector<bool, 64>& f1)
{
	cout << boolalpha;
	cout << "Capacity: " << f1.GetCapacity() << endl;
	cout << "Size: " << f1.GetSize() << endl;
	cout << "Get3: " << f1.Get(3) << endl;
	cout << "First false index: " << f1.GetIndex(false) << endl;
	cout << "First true index: " << f1.GetIndex(true) << endl;



	cout << showbase << hex << f1.mBools[0] << endl;
	cout << hex << f1.mBools[1] << endl;
}
*/

int main()
{
	FixedVector<bool, 65> f1;

	for (size_t i = 0; i < 65; ++i)
	{
		f1.Add(false);
	}
	for (size_t i = 0; i < 65; ++i)
	{
		assert(f1.GetIndex(true) == -1);
		assert(f1.GetIndex(false) == 0);

		assert(f1.Remove(false));
	}
	


#if 1
	FixedVector<bool, 34> fv;
	assert(!fv.Remove(false));
	assert(!fv.Remove(true));
	assert(fv.GetIndex(false) == -1);
	assert(fv.GetIndex(true) == -1);

	assert(!fv[0]);

	for (size_t i = 0; i < 32; ++i)
	{
		fv.Add(false);
	}

	fv.Add(true);
	fv.Add(true);

	assert(!fv.Get(31));
	assert(fv.Get(31) == fv[31]);
	assert(fv.Get(32));
	assert(fv.Get(32) == fv[32]);
	assert(fv.Get(33));
	assert(fv.Get(33) == fv[33]);
	assert(fv.GetSize() == 34);

	fv.Remove(false);
	assert(fv.Get(31));
	assert(fv.Get(32));
	assert(fv.GetSize() == 33);


	FixedVector<bool, 64> fv2;

	for (size_t i = 0; i < 4; ++i)
	{
		assert(fv2.Add(true)); assert(fv2.Add(true));
		assert(fv2.Add(true)); assert(fv2.Add(true));
		assert(fv2.Add(true)); assert(fv2.Add(true));
		assert(fv2.Add(true)); assert(fv2.Add(true));

		assert(fv2.Add(false)); assert(fv2.Add(false));
		assert(fv2.Add(false)); assert(fv2.Add(false));
		assert(fv2.Add(false)); assert(fv2.Add(false));
		assert(fv2.Add(false)); assert(fv2.Add(false));
	}
	assert(!fv2.Add(true));

	for (size_t i = 0; i < 8; ++i)
	{
		assert(fv2.Remove(true));
	}

	for (size_t i = 0; i < 56; ++i)
	{
		if (i < 8)
		{
			assert(!fv2.Get(i));
		}
		else if (i < 16)
		{
			assert(fv2.Get(i));
		}
		else if (i < 24)
		{
			assert(!fv2.Get(i));
		}
		else if (i < 32)
		{
			assert(fv2.Get(i));
		}
		else if (i < 40)
		{
			assert(!fv2.Get(i));
		}
		else if (i < 48)
		{
			assert(fv2.Get(i));
		}
		else if (i < 56)
		{
			assert(!fv2.Get(i));
		}
	}
	// 11111111 00000000 11111111 00000000
	// xxxxxxxx 00000000 11111111 00000000

	for (size_t i = 0; i < 16; ++i)
	{
		assert(fv2.Remove(false));
	}
	for (size_t i = 0; i < 16; ++i)
	{
		assert(fv2.Remove(false));
	}

	assert(fv2.GetCapacity() == 64);
	assert(fv2.GetSize() == 24);
	assert(fv2.GetIndex(true) == 0);
	assert(fv2.GetIndex(false) == -1);

	for (size_t i = 0; i < 24; ++i)
	{
		assert(fv2.Remove(true));
	}
	assert(fv2.GetCapacity() == 64);
	assert(fv2.GetSize() == 0);
	assert(fv2.GetIndex(true) == -1);

	assert(!fv2.Remove(true));
	assert(!fv2.Remove(false));

	assert(fv2.GetIndex(true) == -1);
	assert(fv2.GetIndex(false) == -1);
#endif

#if 1
	int i1 = 23;
	int i2 = 25;
	int i3 = 10;
	int i4 = -4;
	int i5 = 70;

	FixedVector<int, 33> iv;

	assert(iv.GetCapacity() == 33);

	iv.Add(i1);
	iv.Add(i2);
	iv.Add(i3);
	iv.Add(i4);

	assert(iv.GetSize() == 4);
	assert(iv.GetIndex(i2) == 1);
	assert(iv.Get(1) == i2);
	assert(iv[1] == i2);

	bool bRemoved = iv.Remove(i5);
	assert(!bRemoved);
	assert(iv.GetSize() == 4);

	bRemoved = iv.Remove(i2);
	assert(bRemoved);
	assert(iv.GetSize() == 3);
	assert(iv.GetIndex(i2) == -1);

	FixedVector<bool, 10> v;

	assert(v.GetCapacity() == 10);

	v.Add(true);
	v.Add(true);
	v.Add(true);
	v.Add(true);
	v.Add(false);
	v.Add(false);
	v.Add(true);

	assert(v.GetSize() == 7);
	assert(v.Get(0));
	assert(v.Get(1));
	assert(v.Get(2));
	assert(v.Get(3));
	assert(!v.Get(4));
	assert(!v.Get(5));
	assert(v.Get(6));

	v.Remove(false);

	assert(v.GetSize() == 6);
	assert(!v.Get(4));
	assert(v.Get(5));

	v.Remove(false);

	assert(v.GetSize() == 5);

	for (size_t i = 0; i < v.GetSize(); i++)
	{
		assert(v[i]);
	}

	v.Remove(true);

	assert(v.GetSize() == 4);

	for (size_t i = 0; i < v.GetSize(); i++)
	{
		assert(v[i]);
	}

	FixedVector<bool, 65> v1;

	for (int i = 0; i < 65; i++)
	{
		v1.Add(false);
	}

	assert(v1.Add(true) == false);
	assert(v1.GetSize() == 65);
	assert(v1.GetIndex(true) == -1);
#endif

	cout << "NO Assert!!" << endl;

	return 0;
}