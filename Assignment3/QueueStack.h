#pragma once

#include <cassert>
#include <queue>
#include "SmartStack.h"
#include "SmartQueue.h"

namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();

	private:
		unsigned int mMaxStackSize;
		unsigned int mTotalElementCount;
		unsigned int mStackCount;
		T mSum;

		queue<SmartStack<T>> mQueue;
	};

	template <typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mTotalElementCount(0)
		, mStackCount(0)
		, mSum(0)
	{
	}

	template <typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		mSum += number;

		if (mQueue.size() == 0 || mQueue.back().GetCount() == mMaxStackSize)
		{
			SmartStack<T> newStack;
			newStack.Push(number);
			mQueue.push(newStack);
			++mTotalElementCount;
			++mStackCount;
			return;
		}

		mQueue.back().Push(number);
		++mTotalElementCount;
	}

	template <typename T>
	T QueueStack<T>::Peek()
	{
		return mQueue.front().Peek();
	}

	template <typename T>
	T QueueStack<T>::Dequeue()
	{
		T poped = mQueue.front().Pop();

		if (mQueue.front().GetCount() == 0)
		{
			mQueue.pop();
			--mStackCount;
		}

		mSum -= poped;
		--mTotalElementCount;

		return poped;
	}

	template <typename T>
	T QueueStack<T>::GetMax()
	{
		if (mQueue.size() == 0)
		{
			return numeric_limits<T>::lowest();
		}

		T max = mQueue.front().GetMax();

		for (int i = 0; i < mStackCount; ++i)
		{
			T temp = mQueue.front().GetMax();
			mQueue.push(mQueue.front());
			mQueue.pop();

			if (max < temp)
			{
				max = temp;
			}
		}

		return max;
	}

	template <typename T>
	T QueueStack<T>::GetMin()
	{
		if (mQueue.size() == 0)
		{
			return numeric_limits<T>::max();
		}

		T min = mQueue.front().GetMin();

		for (int i = 0; i < mStackCount; ++i)
		{
			T temp = mQueue.front().GetMin();
			mQueue.push(mQueue.front());
			mQueue.pop();

			if (min > temp)
			{
				min = temp;
			}
		}

		return min;
	}

	template <typename T>
	double QueueStack<T>::GetAverage()
	{
		return mSum / static_cast<double>(mTotalElementCount);
	}

	template <typename T>
	T QueueStack<T>::GetSum()
	{
		return mSum;
	}

	template <typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		return mTotalElementCount;
	}

	template <typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		return mStackCount;
	}
}