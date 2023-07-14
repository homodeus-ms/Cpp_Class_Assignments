#pragma once

#include <memory>
#include <vector>


namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	void OrderRecursive(std::vector<T>& v, std::shared_ptr<TreeNode<T>> ptr);

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;
		std::shared_ptr<TreeNode<T>> GetTargetNodeOrNull(const T& data) const;
		void DeleteReorder(std::shared_ptr<TreeNode<T>>& target);

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mRoot = nullptr;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			mRoot = make_shared<TreeNode<T>>(std::move(data));

			return;
		}

		std::shared_ptr<TreeNode<T>> parent = mRoot;
		std::shared_ptr<TreeNode<T>> newNode = make_shared<TreeNode<T>>(parent, std::move(data));

		while (true)
		{
			if (*newNode->Data <= *parent->Data)
			{
				if (parent->Left == nullptr)
				{
					newNode->Parent = parent;
					parent->Left = newNode;
					return;
				}
				parent = parent->Left;
				continue;
			}
			else
			{
				if (parent->Right == nullptr)
				{
					newNode->Parent = parent;
					parent->Right = newNode;
					return;
				}
				parent = parent->Right;
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> ptr = mRoot;

		while (ptr != nullptr)
		{
			if (data == *ptr->Data)
			{
				return true;
			}
			else if (data < *ptr->Data)
			{
				ptr = ptr->Left;
				continue;
			}
			else
			{
				ptr = ptr->Right;
			}
		}

		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> target = GetTargetNodeOrNull(data);

		if (target == nullptr)
		{
			return false;
		}
		if (target->Left == nullptr && target->Right == nullptr)
		{
			if (target == mRoot)
			{
				mRoot = nullptr;
			}
			else if (target->Parent.lock()->Left == target)
			{
				target->Parent.lock()->Left.reset();
			}
			else
			{
				target->Parent.lock()->Right.reset();
			}
			return true;
		}

		DeleteReorder(target);
		//std::shared_ptr<TreeNode<T>> newParent = target->Left

		return true;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		std::shared_ptr<TreeNode<T>> ptr = startNode;

		OrderRecursive(v, ptr);

		return v;
	}
	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::GetTargetNodeOrNull(const T& data) const
	{
		std::shared_ptr<TreeNode<T>> ptr = mRoot;

		while (ptr != nullptr)
		{
			if (data == *ptr->Data)
			{
				return ptr;
			}
			else if (data < *ptr->Data)
			{
				ptr = ptr->Left;
				continue;
			}
			else
			{
				ptr = ptr->Right;
			}
		}

		return nullptr;
	}
	template<typename T>
	void BinarySearchTree<T>::DeleteReorder(std::shared_ptr<TreeNode<T>>& target)
	{
		std::shared_ptr<TreeNode<T>> newParent = target->Left;

		if (newParent != nullptr)
		{
			while (newParent->Right != nullptr)
			{
				newParent = newParent->Right;
			}

			goto REORDER;
		}
		else
		{
			newParent = target->Right;

			while (newParent->Left != nullptr)
			{
				newParent = newParent->Left;
			}
		}

	REORDER:


		if (target->Left != nullptr && target->Left != newParent)
		{
			if (newParent->Parent.lock() == target->Left)
			{
				target->Left->Right = nullptr;
			}
			newParent->Left = target->Left;
			target->Left->Parent = newParent;
		}
		if (target->Right != nullptr && target->Right != newParent)
		{
			if (newParent->Parent.lock() == target->Right)
			{
				target->Right->Left = nullptr;
			}
			newParent->Right = target->Right;
			target->Right->Parent = newParent;
		}

		newParent->Parent = target->Parent.lock();

		if (target->Parent.lock() == nullptr)
		{
			mRoot = newParent;
			return;
		}

		if (target == target->Parent.lock()->Left)
		{
			target->Parent.lock()->Left = newParent;
			return;
		}
		target->Parent.lock()->Right = newParent;
		
	}

	template<typename T>
	void OrderRecursive(std::vector<T>& v, std::shared_ptr<TreeNode<T>> ptr)
	{
		if (ptr == nullptr)
		{
			return;
		}

		OrderRecursive(v, ptr->Left);
		v.push_back(*ptr->Data);
		OrderRecursive(v, ptr->Right);
	}
}
