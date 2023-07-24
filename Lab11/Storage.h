#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage final
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage() = delete;

		Storage(const Storage& other);
		Storage& operator=(const Storage& other);

		Storage(Storage&& other);
		Storage& operator=(Storage&& other);

		~Storage() = default;

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mPtr;
		unsigned int mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mLength(length)
		, mPtr(std::make_unique<T[]>(length))
	{
		/*
		for (size_t i = 0; i < mLength; ++i)
		{
			mPtr[i] = NULL;
		}
		*/
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mLength(length)
		, mPtr(new T[length])
	{
		for (size_t i = 0; i < mLength; ++i)
		{
			mPtr[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(const Storage<T>& other)
		: mLength(other.mLength)
		, mPtr(new T[other.mLength])
	{
		for (size_t i = 0; i < mLength; ++i)
		{
			mPtr[i] = other.mPtr[i];
		}
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage<T>& other)
	{
		if (this != &other)
		{
			mPtr.reset();

			mLength = other.mLength;

			mPtr = std::make_unique<T[]>(other.mLength);

			for (size_t i = 0; i < mLength; ++i)
			{
				mPtr[i] = other.mPtr[i];
			}
		}

		return *this;
	}

	template<typename T>
	Storage<T>::Storage(Storage<T>&& other)
		: mLength(other.mLength)
		, mPtr(std::move(other.mPtr))
	{
		other.mLength = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other)
	{
		if (this != &other)
		{
			mPtr.reset();

			mPtr = std::move(other.mPtr);
			mLength = other.mLength;

			other.mLength = 0;
		}

		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mLength)
		{
			return false;
		}

		mPtr[index] = data;

		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return mPtr;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}
