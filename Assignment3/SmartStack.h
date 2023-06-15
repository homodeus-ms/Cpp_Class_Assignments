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
		double GetStandardDeviation();
		unsigned int GetCount();

	private:
		stack<T> mStack;
		
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
	}

	template<typename T>
	void SmartStack<T>::Push(T number) // number, 이번회차까지 Max값, 이번회차까지 Min값 순서로 저장
	{
		++mCount;
		mSum += number;
		mSquareSum += pow(number, 2);
		mStack.push(number);
		mMax = mMax >= number ? mMax : number;
		mMin = mMin >= number ? number : mMin;

		mStack.push(mMax);
		mStack.push(mMin);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		--mCount;
		mStack.pop();
		mStack.pop();
		T poped = mStack.top();
		mStack.pop();
		mSum -= poped;
		mSquareSum -= pow(poped, 2);

		return poped;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		T temp1 = mStack.top();
		mStack.pop();
		T temp2 = mStack.top();
		mStack.pop();
		T peeked = mStack.top();
		mStack.push(temp2);
		mStack.push(temp1);
		
		return peeked;
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		if (mCount == 0)
		{
			return numeric_limits<T>::lowest();
		}

		T temp = mStack.top();
		mStack.pop();
		T result = mStack.top();
		mStack.push(temp);

		return result;
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		if (mCount == 0)
		{
			return numeric_limits<T>::max();
		}

		return mStack.top();
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
}