#pragma once
#include <iostream>
#include <cstdint>
#include "FixedVector.h"

#define TYPE_CAPACITY (32)
#define idx (mSize / TYPE_CAPACITY)
#define shiftCount (mSize % TYPE_CAPACITY)

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
		enum { MAX = N - 1 };
		size_t mSize;
		unsigned int mBools[MAX / TYPE_CAPACITY + 1];
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
		for (int i = 0; i < MAX / TYPE_CAPACITY + 1; ++i)
		{
			mBools[i] = 0;
		}
	}
	
	template <size_t N>
	bool FixedVector<bool, N>::Add(bool b)
	{
		if (mSize > MAX)
		{
			return false;
		}
		
		mBools[idx] ^= (b << shiftCount);
		
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

		mBools[index / TYPE_CAPACITY] ^= mask;
		mBools[index / TYPE_CAPACITY] >>= 1;
		--mSize;

		return true;
	}
	
	template <size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index) const
	{
		index %= TYPE_CAPACITY;
		int mask = 1 << index;
		mask &= mBools[idx];

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

		int i;
		
		if (b == false)
		{
			for (i = 0; i < MAX / TYPE_CAPACITY + 1; ++i)
			{
				mask = ~mBools[i] & (mBools[i] + 1);

				if (mask >= pow(2, mSize))
				{
					continue;
				}
				
				goto getIndex;
			}

			return -1;
		}
		else
		{
			for (i = 0; i < MAX / TYPE_CAPACITY + 1; ++i)
			{
				if (mBools[i] == 0)
				{
					continue;
				}

				mask = mBools[i] & (-1 * mBools[i]);
				goto getIndex;
			}
			
			return -1;
		}

getIndex:
		int count = -1;

		while (mask != 0)
		{
			mask >>= 1;
			++count;
		}

		return count + (i * TYPE_CAPACITY);
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return MAX + 1;
	}
}