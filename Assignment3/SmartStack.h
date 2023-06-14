#pragma once

#include <cmath>
#include <limits>
#include <stack>

using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		void Push(T number);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetVariance2();
		double GetStandardDeviation();
		unsigned int GetCount();

	private:
		stack<T> mStack;
		stack<T> mMaxs;
		stack<T> mMins;
		T mMax;
		T mMin;
		T mSum;
		double mSquareSum;
		unsigned int mCount;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mMax(numeric_limits<T>::lowest())
		, mMin(numeric_limits<T>::max())
		, mSum(0)
		, mSquareSum(0)
		, mCount(0)
	{
		mMaxs.push(mMax);
		mMins.push(mMin);
	}

	template<typename T>
	void SmartStack<T>::Push(T number)
	{
		++mCount;
		mSum += number;
		mSquareSum += pow(number, 2);
		mStack.push(number);
		mMax = mMax >= number ? mMax : number;
		mMin = mMin >= number ? number : mMin;

		mMaxs.push(mMax);
		mMins.push(mMin);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		--mCount;
		T poped = mStack.top();
		mStack.pop();
		mSum -= poped;
		mSquareSum -= pow(poped, 2);
		mMaxs.pop();
		mMins.pop();

		return poped;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		T peeked = mStack.top();
		
		return peeked;
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		return mMaxs.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		return mMins.top();
	}
	
	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		return mSum / static_cast<double>(mCount);
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		double average = GetAverage();
		return (mSquareSum / mCount) - average * average;
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount()
	{
		return mCount;
	}

	
	template <typename T>
	double SmartStack<T>::GetVariance2()
	{
		double average = GetAverage();
		double sum = 0;
		stack<T> keep;
		while (mStack.size() != 0)
		{
			double top = mStack.top();
			keep.push(mStack.top());
			sum += (top - average) * (top - average);
			mStack.pop();
		}

		swap(keep, mStack);

		return sum / static_cast<double>(mCount);
	}
	
}