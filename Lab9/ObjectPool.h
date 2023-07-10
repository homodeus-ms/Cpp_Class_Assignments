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
		std::queue<std::unique_ptr<T>> mPtrs;

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
			std::unique_ptr<T> p = std::make_unique<T>();
			T* temp = p.release();
			
			return temp;
		}

		auto p = std::move(mPtrs.front());
		mPtrs.pop();
		--mFreeObjectCount;

		return p.release();
	}

	template <typename T>
	void ObjectPool<T>::Return(T* ptr)
	{
		if (mFreeObjectCount == mMaxPoolSize)
		{
			delete ptr;
			return;
		}
		std::unique_ptr<T> p(ptr);
		mPtrs.push(std::move(p));
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


