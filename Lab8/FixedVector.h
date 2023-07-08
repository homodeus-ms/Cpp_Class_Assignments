#pragma once
#include <iostream>

namespace lab8
{
	template <typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		virtual ~FixedVector() = default;
		bool Add(const T& value);
		bool Remove(const T& value);
		const T& Get(unsigned int index);
		T& operator[](unsigned int index);
		int GetIndex(T& value) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		enum { MAX = N };
		T mArray[MAX];
		size_t mSize;
	};

	template <typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& value)
	{
		if (mSize >= MAX)
		{
			return false;
		}
		mArray[mSize++] = value;
		
		return true;
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& value)
	{
		int index = GetIndex(value);

		if (index == -1)
		{
			return false;
		}

		for (size_t i = index; i < mSize - 1; ++i)
		{
			mArray[i] = mArray[i + 1];
		}
		
		--mSize;

		return true;
	}

	template <typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int index)
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	int FixedVector<T, N>::GetIndex(T& value) const
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] == value)
			{
				return i;
			}
		}

		return -1;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return MAX;
	}
}


