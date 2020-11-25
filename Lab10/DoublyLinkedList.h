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
		std::shared_ptr<Node<T>> mFirst;
		unsigned int mSize;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mSize(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mSize > 0)
		{
			std::shared_ptr<Node<T>> temp = mFirst;

			for (unsigned int i = 0; i < mSize - 1; i++)
			{
				temp = temp->Next;
			}

			temp->Next = std::make_shared<Node<T>>(std::move(data), temp);
		}
		else
		{
			mFirst = std::make_shared<Node<T>>(std::move(data));
		}

		mSize++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index >= mSize || mSize == 0)
		{
			Insert(std::move(data));

			return;
		}

		if (index == 0)
		{
			std::shared_ptr<Node<T>> temp = mFirst;

			mFirst = std::make_shared<Node<T>>(std::move(data));

			mFirst->Next = temp;

			temp->Previous = mFirst;

			mSize++;

			return;
		}

		std::shared_ptr<Node<T>> temp = mFirst;

		for (unsigned int i = 0; i < index; i++)
		{
			temp = temp->Next;
		}

		temp->Previous.lock()->Next = std::make_shared<Node<T>>(std::move(data), temp->Previous.lock());

		temp->Previous.lock()->Next->Next = temp;

		temp->Previous = temp->Previous.lock()->Next;

		mSize++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		if (mFirst == nullptr)
		{
			return false;
		}

		if (data == *(mFirst->Data))
		{
			mFirst = mFirst->Next;

			mSize--;

			return true;
		}

		std::shared_ptr<Node<T>> temp = mFirst;

		bool bIsit = false;

		unsigned int i;

		for (i = 0; i < mSize; i++)
		{
			if (*(temp->Data) == data)
			{
				bIsit = true;

				break;
			}

			temp = temp->Next;
		}

		if (!bIsit)
		{
			return false;
		}

		if (temp->Next != nullptr)
		{
			temp->Previous.lock()->Next = temp->Next;

			temp->Next->Previous = temp->Previous.lock();
		}
		else
		{
			temp->Previous.reset();
		}

		mSize--;

		return true;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		if (mFirst == nullptr)
		{
			return false;
		}

		std::shared_ptr<Node<T>> temp = mFirst;

		for (unsigned int i = 0; i < mSize; i++)
		{
			if (*(temp->Data) == data)
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
		if (index >= mSize || mFirst == nullptr)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> temp = mFirst;

		for (unsigned int i = 0; i < index; i++)
		{
			temp = temp->Next;
		}

		return temp;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mSize;
	}
}