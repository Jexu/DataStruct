#pragma once
#include<iostream>
#include<malloc.h>
using namespace std;

namespace linkS_cpp
{
	const int ERROR = -1;
	template<typename T>
	class LinkStack
	{
	public:
		LinkStack();
		virtual ~LinkStack();
		T getTop();
		void push(T data);
		T pop();
		void clearStack();
		int getLength();
	private:
		template<typename T>
		/*�ڲ���*/
		class SNode
		{
		public:
			SNode() {};
			virtual ~SNode() {};
			T data;
			SNode<T> *next = NULL;
		};
		SNode<T> *base = NULL;
		SNode<T> *top = NULL;
		int length = 0;
	};

	template<typename T>
	/*���캯���ڳ�ʼ����ʽջ*/
	LinkStack<T>::LinkStack()
	{
		if (!this)
		{
			exit(ERROR);
		}
		SNode<T> *base = new SNode<T>();
		if (!base)
		{
			exit(ERROR);
		}
		base->next = NULL;
		this->base = base;
		this->top = this->base;
		this->length = 0;
	}

	template<typename T>
	LinkStack<T>::~LinkStack()
	{
	}

	template<typename T>
	/*��ȡ��ǰջ����Ԫ��ֵ*/
	T LinkStack<T>::getTop()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->base == this->top || this->top->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		return this->top->next->data;
	}

	template<typename T>
	/*��ջ��������Ԫ��ѹ��ջ��*/
	void LinkStack<T>::push(T data)
	{
		if (!this)
		{
			exit(ERROR);
		}
		SNode<T> *newTop = new SNode<T>();
		if (!newTop)
		{
			exit(ERROR);
		}
		this->top->data = data;
		newTop->next = this->top;
		this->top = newTop;
		this->length++;
	}

	template<typename T>
	/*��ջ��������ջ��Ԫ�ص���*/
	T LinkStack<T>::pop()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->base == this->top || this->top->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		T data = this->top->next->data;
		SNode<T> *freeP = this->top;
		this->top = this->top->next;
		delete freeP;
		freeP = NULL;
		this->length--;
		return data;
	}

	template<typename T>
	/*���ջ������Ԫ��*/
	void LinkStack<T>::clearStack()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->base == this->top || this->top->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		while (this->top->next)
		{
			SNode<T> *freeP = this->top;
			this->top = this->top->next;
			delete freeP;
			freeP = NULL;
		}
		this->length = 0;
	}

	template<typename T>
	/*��ȡ��ǰջ��Ԫ�ظ���*/
	int LinkStack<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}

}


