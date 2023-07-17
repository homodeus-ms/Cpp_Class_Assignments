#pragma once

#include <memory>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		size_t mLength;
		std::shared_ptr<Node<T>> mHead;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mLength(0)
	{
		mHead = nullptr;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mHead == nullptr)
		{
			mHead = std::make_shared<Node<T>>(std::move(data));
			++mLength;
			return;
		}
		std::shared_ptr<Node<T>>newNode = std::make_shared<Node<T>>(std::move(data));
		std::shared_ptr<Node<T>> prevNode = (*this)[GetLength() - 1];
		newNode->Previous = prevNode;
		prevNode->Next = newNode;

		++mLength;
		return;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (mHead == nullptr)
		{
			mHead = std::make_shared<Node<T>>(std::move(data));
			++mLength;
			return;
		}
		if (index >= mLength)
		{
			Insert(std::move(data));
			return;
		}

		std::shared_ptr<Node<T>>newNode = std::make_shared<Node<T>>(std::move(data));

		if (index == 0)
		{
			std::shared_ptr<Node<T>> temp = mHead;
			mHead = newNode;
			newNode->Next = temp;
			temp->Previous = newNode;
			++mLength;
			return;
		}

		std::shared_ptr<Node<T>> prevNode = (*this)[index - 1];
		newNode->Previous = prevNode;
		prevNode->Next->Previous = newNode;
		newNode->Next = prevNode->Next;
		prevNode->Next = newNode;

		++mLength;
		return;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		if (mLength == 0)
		{
			return false;
		}

		std::shared_ptr<Node<T>> temp = mHead;

		for (size_t i = 0; i < mLength; ++i)
		{
			if (*temp->Data == data)
			{
				if (temp == mHead)
				{
					if (mLength == 1)
					{
						mHead = nullptr;
					}
					else
					{
						temp->Next->Previous.lock() = nullptr;
						mHead = temp->Next;
					}
					
					--mLength;
					return true;
				}

				if (temp->Next != nullptr)
				{
					temp->Next->Previous = temp->Previous;
					temp->Previous.lock()->Next = temp->Next;
				}
				else
				{
					temp->Previous.lock()->Next = nullptr;
				}
				
				--mLength;
				return true;
			}

			temp = temp->Next;
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> temp = mHead;

		for (size_t i = 0; i < mLength; ++i)
		{
			if (*temp->Data == data)
			{
				return true;
			}

			temp = temp->Next;
		}

		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mLength)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> result = this->mHead;

		for (size_t i = 0; i < index; ++i)
		{
			result = result->Next;
		}

		return result;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}
