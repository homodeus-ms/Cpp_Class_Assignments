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

		std::shared_ptr<Node<T>> p = mHead;

		while (p->Next != nullptr)
		{
			p = p->Next;
		}

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));
		newNode->Previous = p;
		p->Next = newNode;

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

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));
		std::shared_ptr<Node<T>> nextNode = (*this)[index];
		nextNode->Previous.lock()->Next = newNode;
		newNode->Previous = nextNode->Previous;
		newNode->Next = nextNode;
		nextNode->Previous = newNode;

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

		if (*(mHead->Data) == data)
		{
			mHead = mHead->Next;
			mHead->Previous.lock() = nullptr;
			--mLength;
			return true;
		}

		std::shared_ptr<Node<T>> p = mHead;

		while (p != nullptr)
		{
			if (*(p->Data) == data)
			{
				p->Previous.lock()->Next = p->Next;

				if (p->Next != nullptr)
				{
					p->Next->Previous = p->Previous;
				}

				--mLength;

				return true;
			}
			p = p->Next;
		}

		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> p = mHead;

		for (size_t i = 0; i < mLength; ++i)
		{
			if (*(p->Data) == data)
			{
				return true;
			}
			p = p->Next;
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

		std::shared_ptr<Node<T>> p = mHead;

		for (size_t i = 0; i < index; ++i)
		{
			p = p->Next;
		}

		return p;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}