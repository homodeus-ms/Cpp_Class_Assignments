#pragma once

#include <cassert>
#include <limits>
#include <queue>

using namespace std;

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		
		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

	private:
		queue<T> mQueue;
		
		T mSum;
		double mSquareSum;
		unsigned int mCount;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0)
		, mSquareSum(0)
		, mCount(0)
	{
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		++mCount;
		mSum += number;
		mSquareSum += pow(number, 2);
		mQueue.push(number);
	}

	template <typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template <typename T>
	T SmartQueue<T>::Dequeue()
	{
		--mCount;
		T poped = mQueue.front();
		mSum -= poped;
		mSquareSum -= pow(poped, 2);
		mQueue.pop();

		return poped;
	}

	template <typename T>
	T SmartQueue<T>::GetMax()
	{
		if (mCount == 0)
		{
			return numeric_limits<T>::lowest();
		}

		T max = mQueue.front();

		for (int i = 0; i < mCount; ++i)
		{
			T temp = mQueue.front();
			mQueue.push(temp);
			mQueue.pop();

			if (max < temp)
			{
				max = temp;
			}
		}

		return max;
	}

	template <typename T>
	T SmartQueue<T>::GetMin()
	{
		if (mCount == 0)
		{
			return numeric_limits<T>::max();
		}

		T min = mQueue.front();

		for (int i = 0; i < mCount; ++i)
		{
			T temp = mQueue.front();
			mQueue.push(temp);
			mQueue.pop();

			if (min > temp)
			{
				min = temp;
			}
		}

		return min;
	}

	template <typename T>
	double SmartQueue<T>::GetAverage()
	{
		double denominator = static_cast<double>(mCount);

		return mSum / denominator;
	}

	template <typename T>
	T SmartQueue<T>::GetSum()
	{
		return mSum;
	}

	template <typename T>
	double SmartQueue<T>::GetVariance()
	{
		double average = GetAverage();
		return (mSquareSum / mCount) - average * average;
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template <typename T>
	unsigned int SmartQueue<T>::GetCount()
	{
		return mCount;
	}
}