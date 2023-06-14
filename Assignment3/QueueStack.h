#pragma once

#include <cassert>
#include <queue>
#include <stack>

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
		queue<SmartStack<T>> mKeepQ;

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

		SmartQueue<T> max;

		while (mQueue.size() != 0)
		{
			mKeepQ.push(mQueue.front());
			max.Enqueue(mQueue.front().GetMax());
			mQueue.pop();
		}

		T result = max.GetMax();

		swap(mKeepQ, mQueue);

		return result;
	}

	template <typename T>
	T QueueStack<T>::GetMin()
	{
		if (mQueue.size() == 0)
		{
			return numeric_limits<T>::max();
		}

		SmartQueue<T> min;

		while (mQueue.size() != 0)
		{
			mKeepQ.push(mQueue.front());
			min.Enqueue(mQueue.front().GetMin());
			mQueue.pop();
		}

		T result = min.GetMin();

		swap(mKeepQ, mQueue);

		return result;
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