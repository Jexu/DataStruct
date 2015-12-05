#pragma once
#include<iostream>
using namespace std;

namespace ls_cpp
{
	const int ERROR = -1;

	template<typename T>
	class ListStack
	{
	public:
		ListStack();
		virtual ~ListStack();
		T getTop();
		void push(T e);
		T pop();
		void clearStack();
		int getLength();
	private:
		T *base = NULL;
		T *top = NULL;
		int length = 0;
		int stackSize = 0;
		static const int INIT_STACK_SIZE_ = 100;
		static const int STACK_INCREASMENT_ = 10;
	};

	template<typename T>
	/*��ʼ��ջ������ջ��ʼ��С*/
	ListStack<T>::ListStack()
	{
		if (!this)
		{
			exit(ERROR);
		}
		this->base = (T *)malloc(ListStack<T>::INIT_STACK_SIZE_*sizeof(T));
		if (!this->base)
		{
			exit(ERROR);
		}
		this->top = this->base;
		this->stackSize = ListStack<T>::INIT_STACK_SIZE_;
		this->length = 0;
	}

	template<typename T>
	ListStack<T>::~ListStack()
	{
	}

	template<typename T>
	/*��ȡ��ǰջ����Ԫ��ֵ*/
	T ListStack<T>::getTop()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->base == this->top || this->length == 0)
		{
			exit(ERROR);
		}
		return *(this->top - 1);
	}

	template<typename T>
	/*��ջ��������Ԫ��ѹ��ջ��*/
	void ListStack<T>::push(T e)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->top - this->base >= this->stackSize)
		{
			T *newBase = (T *)realloc(this->base, (this->stackSize + ListStack<T>::STACK_INCREASMENT_)*sizeof(T));
			if (!newBase)
			{
				exit(ERROR);
			}
			this->base = newBase;
			this->top = this->base + this->stackSize;
			this->stackSize += ListStack<T>::STACK_INCREASMENT_;
		}
		*this->top++ = e;
		this->length++;
	}

	template<typename T>
	/*��ջ��������ջ��Ԫ�ص���*/
	T ListStack<T>::pop()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->top == this->base || this->length == 0)
		{
			exit(ERROR);
		}
		T e = *--this->top;
		this->length--;
		if (this->top != this->base && (this->stackSize - (this->top - this->base + 1)) % ListStack<T>::STACK_INCREASMENT_ == 0)
		{
			T *newBase = (T *)realloc(this->base, (this->stackSize - ListStack<T>::STACK_INCREASMENT_)*sizeof(T));
			if (!newBase)
			{
				*this->top++ = e;
				this->length++;
				exit(ERROR);
			}
			int distance = this->top - this->base;
			this->base = newBase;
			this->top = this->base + distance;
			this->stackSize -= ListStack<T>::STACK_INCREASMENT_;
		}
		return e;
	}

	template<typename T>
	/*��õ�ǰջ��Ԫ�ظ���*/
	int ListStack<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}

	template<typename T>
	/*���ջ������Ԫ��*/
	void ListStack<T>::clearStack()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->top == this->base || this->length == 0)
		{
			exit(ERROR);
		}
		this->top = this->base;
		this->length = 0;
		this->stackSize = ListStack<T>::INIT_STACK_SIZE_;
	}
}


