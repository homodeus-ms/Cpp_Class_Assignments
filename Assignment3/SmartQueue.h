#pragma once

#include <cassert>
#include <limits>
#include <queue>

#include "Node.h"

using namespace std;

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		~SmartQueue();
		SmartQueue(const SmartQueue& other);
		SmartQueue& operator=(const SmartQueue& other);
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
		Node<T>* mHead;
		Node<T>* mEnd;
		
		T mSum;
		double mSquareSum;
		unsigned int mCount;

		void initList(Node<T>* mHead, Node<T>* mEnd);
		void insertSorted(Node<T>* mHead, Node<T>* mEnd, T value);
		void destroy(Node<T>* mHead);
		void removeNode(Node<T>* mHead, Node<T>* mEnd, T value);
		T getMaxNodeValue(Node<T>* mEnd);
		T getMinNodeValue(Node<T>* mHead);
		void copyList(Node<T>* srcHead, Node<T>* srcEnd, Node<T>* destHead, Node<T>* destEnd);
	};

	template <typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0)
		, mSquareSum(0)
		, mCount(0)
	{
		mHead = new Node<T>();
		mEnd = new Node<T>();

		initList(mHead, mEnd);
	}

	template <typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& other)
		: mSum(other.mSum)
		, mCount(other.mCount)
		, mSquareSum(other.mSquareSum)
		, mQueue(other.mQueue)
	{
		mHead = new Node<T>();
		mEnd = new Node<T>();
		copyList(other.mHead, other.mEnd, mHead, mEnd);
	}

	template <typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		destroy(mHead);

		mSum = other.mSum;
		mCount = other.mCount;
		mSquareSum = other.mSquareSum;
		mQueue = other.mQueue;

		mHead = new Node<T>();
		mEnd = new Node<T>();

		copyList(other.mHead, other.mEnd, mHead, mEnd);

		return *this;
	}

	template <typename T>
	SmartQueue<T>::~SmartQueue()
	{
		destroy(mHead);
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		++mCount;
		mSum += number;
		mSquareSum += pow(number, 2);
		mQueue.push(number);
		
		insertSorted(mHead, mEnd, number);
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
		removeNode(mHead, mEnd, poped);

		return poped;
	}

	template <typename T>
	T SmartQueue<T>::GetMax()
	{
		return mCount == 0 ? numeric_limits<T>::lowest() : getMaxNodeValue(mEnd);
	}

	template <typename T>
	T SmartQueue<T>::GetMin()
	{
		return mCount == 0 ? numeric_limits<T>::max() : getMinNodeValue(mHead);
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

	// private ÇÔ¼öµé. Linked List

	template <typename T>
	void SmartQueue<T>::initList(Node<T>* mHead, Node<T>* mEnd)
	{
		mHead->Prev = nullptr;
		mHead->Value = numeric_limits<T>::lowest();
		mHead->Next = mEnd;

		mEnd->Prev = mHead;
		mEnd->Value = numeric_limits<T>::max();
		mEnd->Next = nullptr;
	}

	template <typename T>
	void SmartQueue<T>::insertSorted(Node<T>* mHead, Node<T>* mEnd, T value)
	{
		Node<T>* newNode = new Node<T>();
		newNode->Value = value;
		Node<T>* p = mHead->Next;

		while (p != mEnd)
		{
			if (p->Value >= value)
			{
				break;
			}
			p = p->Next;
		}

		newNode->Prev = p->Prev;
		newNode->Next = p;
		p->Prev->Next = newNode;
		p->Prev = newNode;
	}

	template <typename T>
	void SmartQueue<T>::destroy(Node<T>* mHead)
	{
		Node<T>* p = mHead->Next;
		while (p != nullptr)
		{
			delete p->Prev;
			p = p->Next;
		}
	}

	template <typename T>
	void SmartQueue<T>::removeNode(Node<T>* mHead, Node<T>* mEnd, T value)
	{
		Node<T>* p = mHead->Next;

		while (p != mEnd)
		{
			if (p->Value == value)
			{
				p->Prev->Next = p->Next;
				p->Next->Prev = p->Prev;
				delete p;
				break;
			}
			p = p->Next;
		}
	}

	template <typename T>
	T SmartQueue<T>::getMaxNodeValue(Node<T>* mEnd)
	{
		return mEnd->Prev->Value;
	}

	template <typename T>
	T SmartQueue<T>::getMinNodeValue(Node<T>* mHead)
	{
		return mHead->Next->Value;
	}

	template <typename T>
	void SmartQueue<T>::copyList(Node<T>* srcHead, Node<T>* srcEnd, Node<T>* destHead, Node<T>* destEnd)
	{
		initList(destHead, destEnd);

		T value;
		Node<T>* p = srcHead->Next;

		Node<T>* destH = destHead;
		Node<T>* destE = destEnd;

		while (p != srcEnd)
		{
			value = p->Value;

			Node<T>* newNode = new Node<T>();
			newNode->Value = value;

			destH->Next = newNode;
			newNode->Prev = destH;
			newNode->Next = destE;
			destE->Prev = newNode;

			p = p->Next;

			destH = destH->Next;
		}
	}
}