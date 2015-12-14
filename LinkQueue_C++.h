#pragma once
#include<iostream>
#include<malloc.h>
using namespace std;

namespace linkQ_cpp
{
	const int ERROR = -1;
	template<typename T>
	class LinkQueue
	{
	public:
		LinkQueue();
		virtual ~LinkQueue();
		T getHead();
		void inQueue(T data);
		T outQueue();
		void clearQueue();
		int getLength();
	private:
		template<typename T>
		/*内部类---队列中每个元素类型类*/
		class SNode
		{
		public:
			SNode() {};
			virtual ~SNode() {};
			T data;
			SNode<T> *next = NULL;
		};
		SNode<T> *rear = NULL;
		SNode<T> *front = NULL;
		int length = 0;
	};

	template<typename T>
	/*构造函数内初始化链式队列*/
	LinkQueue<T>::LinkQueue()
	{
		if (!this)
		{
			exit(ERROR);
		}
		SNode<T> *rear = new SNode<T>();
		if (!rear)
		{
			exit(ERROR);
		}
		rear->next = NULL;
		this->rear = rear;
		this->front = this->rear;
		this->length = 0;
	}

	template<typename T>
	LinkQueue<T>::~LinkQueue()
	{
	}

	template<typename T>
	/*获取当前队列顶的元素值*/
	T LinkQueue<T>::getHead()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->rear == this->front || this->front->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		return this->front->next->data;
	}

	template<typename T>
	/*进队操作，将元素压入队尾*/
	void LinkQueue<T>::inQueue(T data)
	{
		if (!this)
		{
			exit(ERROR);
		}
		SNode<T> *newRear = new SNode<T>();
		if (!newRear)
		{
			exit(ERROR);
		}
		newRear->data = data;
		newRear->next = NULL;
		this->rear->next = newRear;
		this->rear = newRear;
		this->length++;
	}

	template<typename T>
	/*出队操作，将队列顶元素弹出*/
	T LinkQueue<T>::outQueue()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->rear == this->front || this->front->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		T data = this->front->next->data;
		SNode<T> *freeP = this->front;
		this->front = this->front->next;
		delete freeP;
		freeP = NULL;
		this->length--;
		return data;
	}

	template<typename T>
	/*清空队列中所有元素*/
	void LinkQueue<T>::clearQueue()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->rear == this->front || this->front->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		while (this->front->next)
		{
			SNode<T> *freeP = this->front;
			this->front = this->front->next;
			delete freeP;
			freeP = NULL;
		}
		this->length = 0;
	}

	template<typename T>
	/*获取当前队列中元素个数*/
	int LinkQueue<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}

}


