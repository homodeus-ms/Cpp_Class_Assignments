#pragma once
#include <iostream>
#include "FixedVector.h"

namespace lab8
{
	template <size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		bool Add(bool b);
		bool Remove(bool b);
		bool Get(unsigned int index) const;
		bool operator[](unsigned int index) const;
		int GetIndex(bool b) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		unsigned int mBools;
		unsigned int mSize;
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
		, mBools(0)
	{
	}
	
	template <size_t N>
	bool FixedVector<bool, N>::Add(bool b)
	{
		if (mSize >= N)
		{
			return false;
		}
		
		mBools = mBools ^ (b << mSize);

		++mSize;

		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(bool b)
	{
		int index = GetIndex(b);

		if (index == -1)
		{
			return false;
		}

		int mask = 1 << index;

		mBools ^= mask;
		mBools >>= 1;
		--mSize;

		return true;
	}
	
	template <size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index) const
	{
		int mask = 1 << index;
		mask &= mBools;

		return mask == 0 ? false : true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int index) const
	{
		return this->Get(index);
	}
	
	template <size_t N>
	int FixedVector<bool, N>::GetIndex(bool b) const
	{
		int mask;
		if (b == false)
		{
			mask = ~mBools & (mBools + 1);
			if (mask >= pow(2, mSize))
			{
				return -1;
			}
		}
		else
		{
			if (mBools == 0)
			{
				return -1;
			}
			mask = mBools & (-1 * mBools);
		}

		int count = -1;

		while (mask != 0)
		{
			mask >>= 1;
			++count;
		}

		return count;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}