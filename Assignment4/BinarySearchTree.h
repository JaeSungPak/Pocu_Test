#pragma once

#include <memory>
#include <vector>
#include "TreeNode.h"

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>> mFirst;

	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mFirst == nullptr)
		{
			mFirst = std::make_shared<TreeNode<T>>(std::move(data));
			return;
		}

		std::shared_ptr<TreeNode<T>> temp = mFirst;
		
		while (true)
		{
			if (*data > *(temp->Data))
			{
				if (temp->Right != nullptr)
				{
					temp = temp->Right;
				}
				else
				{
					temp->Right = std::make_shared<TreeNode<T>>(temp, std::move(data));
					return;
				}
			}
			else
			{
				if (temp->Left != nullptr)
				{
					temp = temp->Left;
				}
				else
				{
					temp->Left = std::make_shared<TreeNode<T>>(temp ,std::move(data));
					return;
				}
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mFirst;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		if (mFirst == nullptr)
		{
			return false;
		}

		std::shared_ptr<TreeNode<T>> temp = mFirst;

		while (true)
		{
			if (data == *(temp->Data))
			{
				return true;
			}
			else if (data > *(temp->Data))
			{
				if (temp->Right != nullptr)
				{
					temp = temp->Right;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (temp->Left != nullptr)
				{
					temp = temp->Left;
				}
				else
				{
					return false;
				}
			}
		}
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		//mFirst를 삭제할 때 경우도 추가하기★

		if (mFirst == nullptr)
		{
			return false;
		}

		std::shared_ptr<TreeNode<T>> temp = mFirst;
		bool bRight = false;

		//탐색

		while (true)
		{
			if (data == *(temp->Data))
			{
				break;
			}
			else if (data > * (temp->Data))
			{
				if (temp->Right != nullptr)
				{
					temp = temp->Right;
					bRight = true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (temp->Left != nullptr)
				{
					temp = temp->Left;
					bRight = false;
				}
				else
				{
					return false;
				}
			}
		}

		//삭제

		if (temp->Left == nullptr && temp->Right == nullptr)
		{
			if (bRight)
			{
				temp->Parent.lock()->Right = nullptr;
			}
			else
			{
				temp->Parent.lock()->Left = nullptr;
			}
		}
		else if (temp->Left != nullptr && temp->Right != nullptr)
		{
			std::shared_ptr<TreeNode<T>> low = temp->Right;

			//오른쪽 하위 값 중 가장 작은 값 찾아서 분리하기

			while (low->Left != nullptr)
			{
				low = low->Left;
			}

			if (low->Right != nullptr)
			{
				low->Right->Parent = low->Parent;

				low->Parent.lock()->Left = low->Right;
			}

			//temp의 자리를 가장 작은 값으로 대체

			if (bRight)
			{
				temp->Parent.lock()->Right = low;
			}
			else
			{
				temp->Parent.lock()->Left = low;
			}

			low->Parent = temp->Parent;
			low->Right = temp->Right;
			low->Left = temp->Left;
			
		}
		else if (temp->Left == nullptr && temp->Right != nullptr)
		{
			temp->Right->Parent = temp->Parent;

			if (bRight)
			{
				temp->Parent.lock()->Right = temp->Right;
			}
			else
			{
				temp->Parent.lock()->Left = temp->Right;
			}
		}
		else if (temp->Left != nullptr && temp->Right == nullptr)
		{
			temp->Left->Parent = temp->Parent;

			if (bRight)
			{
				temp->Parent.lock()->Right = temp->Left;
			}
			else
			{
				temp->Parent.lock()->Left = temp->Left;
			}
		}

		return true;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		return v;
	}
}