#pragma once
#include <iostream>
#include <cstdint>
#include "FixedVector.h"

//#define TYPE_CAPACITY (32)
#define idx (mSize / TYPE_CAPACITY)
#define boolIndex (mSize % TYPE_CAPACITY)

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
		enum 
		{ 
			MAX = N,
			TYPE_CAPACITY = 32
		};
		size_t mSize;
		unsigned int mBools[(MAX - 1) / TYPE_CAPACITY + 1];
		const size_t mArrLength;
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
		, mArrLength(MAX / TYPE_CAPACITY + 1)
	{
		for (size_t i = 0; i < mArrLength; ++i)
		{
			mBools[i] = 0;
		}
	}
	
	template <size_t N>
	bool FixedVector<bool, N>::Add(bool b)
	{
		if (mSize >= MAX)
		{
			return false;
		}
		
		mBools[idx] |= (b << (mSize % TYPE_CAPACITY));
		
		++mSize;

		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(bool b)
	{
		if (mSize == 0)
		{
			return false;
		}

		int targetIndex = GetIndex(b);

		if (targetIndex == -1)
		{
			return false;
		}

		int mask = 1 << targetIndex;
		int currIndex = targetIndex / TYPE_CAPACITY;
		int lastIndex = (mSize - 1) / TYPE_CAPACITY;

		unsigned int lowBits = mBools[currIndex] % mask;
		unsigned int highBits = mBools[currIndex] & (~mask);
		//highBits ^= lowBits;
		highBits >>= 1;
		mBools[currIndex] = highBits | lowBits;

		if (currIndex < lastIndex)
		{
			int8_t carry = mBools[currIndex + 1] & 0x1;
			if (carry == 0x1)
			{
				mBools[currIndex] |= 0x80000000;
			}

			for (int i = currIndex + 1; i < lastIndex; ++i)
			{
				carry = mBools[i + 1] & 0x1;
				mBools[i] >>= 1;

				if (carry == 0x1)
				{
					mBools[i] |= 0x80000000;
				}
			}
			mBools[lastIndex] >>= 1;
		}

		--mSize;

		return true;
	}
	
	template <size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index) const
	{
		if (index >= mSize)
		{
			return false;
		}

		unsigned int targetIndex = index % TYPE_CAPACITY;
		int mask = 1 << targetIndex;
		mask &= mBools[index / TYPE_CAPACITY];

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
		if (mSize == 0)
		{
			return -1;
		}
		if ((mBools[0] & 0x1) == b)
		{
			return 0;
		}

		unsigned int mask;
		size_t lastIndex = mSize / TYPE_CAPACITY;

		size_t i;
		
		if (b == false)
		{
			for (i = 0; i <= lastIndex; ++i)
			{
				if (mBools[i] == UINT_MAX)
				{
					continue;
				}
				
				mask = ~mBools[i] & (mBools[i] + 1);

				if (i == lastIndex && mask >= pow(2, mSize % TYPE_CAPACITY))
				{
					break;
				}
				
				goto getIndex;
			}

			return -1;
		}
		else
		{
			for (i = 0; i <= lastIndex; ++i)
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

		if (mask == 0x80000000)
		{
			return 31 + (i * TYPE_CAPACITY);
		}

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
		return MAX;
	}
}