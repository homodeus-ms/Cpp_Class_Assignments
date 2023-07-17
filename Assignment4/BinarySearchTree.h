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
		
		void DeleteRecursive(std::shared_ptr<TreeNode<T>>& target);
		std::shared_ptr<TreeNode<T>> GetNewParentOrNull(std::shared_ptr<TreeNode<T>>& target);

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mRoot = nullptr;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<TreeNode<T>>(std::move(data));

			return;
		}

		std::shared_ptr<TreeNode<T>> parent = mRoot;
		std::shared_ptr<TreeNode<T>> newNode = std::make_shared<TreeNode<T>>(parent, std::move(data));

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
#if 0
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
#endif
		std::shared_ptr<TreeNode<T>> target = GetTargetNodeOrNull(data);
		if (target == nullptr)
		{
			return false;
		}

		std::shared_ptr<TreeNode<T>> newParent = GetNewParentOrNull(target);

		
		if (newParent == nullptr)
		{
			if (target == mRoot)
			{
				mRoot = nullptr;
			}
			else if (target == target->Parent.lock()->Left)
			{
				target->Parent.lock()->Left = nullptr;
			}
			else
			{
				target->Parent.lock()->Right = nullptr;
			}

			return true;
		}
		
		DeleteRecursive(target);
		
		newParent->Parent = target->Parent;

		return true;
	}

	template<typename T>
	void BinarySearchTree<T>::DeleteRecursive(std::shared_ptr<TreeNode<T>>& target)
	{
		if (target->Left == nullptr && target->Right == nullptr)
		{
			return;
		}

		std::shared_ptr<TreeNode<T>> newParent = GetNewParentOrNull(target);

		DeleteRecursive(newParent);

		// newParent�� ���� �θ� ����Ű�� ���� ����
		

		// newParent�� �����θ� newParent����Ű�� ���� ����
		if (newParent->Parent.lock()->Left == newParent)
		{
			newParent->Parent.lock()->Left = nullptr;
			newParent->Parent.reset();
			
		}
		else if (newParent->Parent.lock()->Right == newParent)
		{
			newParent->Parent.lock()->Right = nullptr;
			newParent->Parent.reset();
		}

		// target�� �θ��� �ڽ����� newParent�� ����
		if (target == mRoot)
		{
			mRoot = newParent;
		}
		else if (target == target->Parent.lock()->Left)
		{
			target->Parent.lock()->Left = newParent;
			newParent->Parent = target->Parent;
		}
		else
		{
			target->Parent.lock()->Right = newParent;
			newParent->Parent = target->Parent;
		}

		// target�� �ڽĵ��� newParent�� �ޱ�
		if (newParent == mRoot)
		{
			newParent->Left = target->Left;
			if (newParent->Left != nullptr)
			{
				newParent->Left->Parent = newParent;
			}

			newParent->Right = target->Right;
			if (newParent->Right != nullptr)
			{
				newParent->Right->Parent = newParent;
			}
		}
		else
		{
			if (target->Left != nullptr && target->Left != newParent)
			{
				newParent->Left = target->Left;
				newParent->Left->Parent = newParent;
			}
			if (target->Right != nullptr && target->Right != newParent)
			{
				newParent->Right = target->Right;
				newParent->Right->Parent = newParent;
			}
		}
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::GetNewParentOrNull(std::shared_ptr<TreeNode<T>>& target)
	{
		if (target->Left == nullptr && target->Right == nullptr)
		{
			return nullptr;
		}

		std::shared_ptr<TreeNode<T>> newParent = target->Left;

		if (newParent == nullptr)
		{
			newParent = target->Right;

			while (newParent->Left != nullptr)
			{
				newParent = newParent->Left;
			}
		}
		else
		{
			while (newParent->Right != nullptr)
			{
				newParent = newParent->Right;
			}
		}

		return newParent;
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
