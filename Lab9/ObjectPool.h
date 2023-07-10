#pragma once

#include <iostream>
#include <memory>
#include <queue>

namespace lab9
{
	template <typename T>
	class ObjectPool final
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool() = default;
		ObjectPool(const ObjectPool& other) = delete;
		ObjectPool& operator=(const ObjectPool&) = delete;

		T* Get();
		void Return(T* ptr);
		size_t GetFreeObjectCount() const;
		size_t GetMaxFreeObjectCount() const;

	private:
		size_t mMaxPoolSize;
		size_t mFreeObjectCount;
		std::queue<T*> mPtrs;

	};

	template <typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
		, mFreeObjectCount(0)
	{
	}

	template <typename T>
	T* ObjectPool<T>::Get()
	{
		if (mFreeObjectCount == 0)
		{
			T* p = new T();
			
			return p;
		}

		auto poped = mPtrs.front();
		mPtrs.pop();
		--mFreeObjectCount;

		return poped;
	}

	template <typename T>
	void ObjectPool<T>::Return(T* ptr)
	{
		if (mFreeObjectCount == mMaxPoolSize)
		{
			delete ptr;
			return;
		}
		
		mPtrs.push(ptr);
		++mFreeObjectCount;
		return;
	}

	template <typename T>
	size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mFreeObjectCount;
	}

	template <typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mMaxPoolSize;
	}
}


