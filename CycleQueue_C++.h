#pragma once
#include<iostream>
#include<malloc.h>
using namespace std;

namespace cq_cpp
{	
	const int ERROR = -1;
	template<typename T>
	/*循环队列类---数组实现*/
	class CycleQueue
	{
	public:
		/*默认构造函数，默认创建大小为I_Q_S的循环队列*/
		CycleQueue();
		/*指定构造对应大小的循环队列*/
		CycleQueue(int queueSize);
		/*析构函数，销毁循环队列*/
		virtual ~CycleQueue();
		/*获取队列头元素值，获取前应该先检查队空*/
		T getHead();
		/*入队操作，入队前应该先检查队满*/
		void inQueue(T e);
		/*出对操作，返回队头元素值，出队前应该先检查队空*/
		T outQueue();
		/*获取当前队列中元素个数*/
		int getLength();
		/*清空队列*/
		void clearQueue();
		/*判断队列是否为空*/
		bool isQueueEmpty();
		/*判断队列是否满*/
		bool isQueueFull();
	private:
		/*指向队列基地址的指针*/
		T *base = NULL;
		/*指向循环队列尾的伪指针*/
		int rear = 0;
		/*指向循环队列头的伪指针*/
		int front = 0;
		/*当前队列中元素个数*/
		int length = 0;
		/*初始化时候分配的循环队列大小*/
		int init_queue_size;
		/*默认构造循环队列大小为100*/
		static const int I_Q_S = 100;
	};


	template<typename T>
	CycleQueue<T>::CycleQueue()
	{
		if (!this)
		{
			exit(ERROR);
		}
		this->base = (T *)malloc(CycleQueue<T>::I_Q_S*sizeof(T));
		if (!this->base)
		{
			exit(ERROR);
		}
		this->front = this->rear = 0;
		this->length = 0;
		this->init_queue_size = CycleQueue<T>::I_Q_S;
	}

	template<typename T>
	CycleQueue<T>::CycleQueue(int queueSize)
	{
		if (!this)
		{
			exit(ERROR);
		}
		this->base = (T *)malloc(CycleQueue<T>::queueSize*sizeof(T));
		if (!this->base)
		{
			exit(ERROR);
		}
		this->front = this->rear = 0;
		this->length = 0;
		this->init_queue_size = queueSize;
	}

	template<typename T>
	CycleQueue<T>::~CycleQueue()
	{
		if (this && this->base)
		{
			delete this->base;
		}
	}

	template<typename T> 
	T CycleQueue<T>::getHead()
	{
		if (!this || !this->base || this->length == 0)
		{
			exit(ERROR);
		}
		return *(this->base + this->front);
	}

	template<typename T>
	void CycleQueue<T>::inQueue(T e)
	{
		if (!this || !this->base || (this->rear + 1) % this->init_queue_size == this->front)
		{
			exit(ERROR);
		}
		*(this->base + this->rear) = e;
		this->length++;
		this->rear = (this->rear + 1) % this->init_queue_size;
	}

	template<typename T>
	T CycleQueue<T>::outQueue()
	{
		if (!this || !this->base || this->front == this->rear)
		{
			exit(ERROR);
		}
		T e = *(this->base + this->front);
		this->length--;
		this->front = (this->front + 1) % this->init_queue_size;
		return e;
	}

	template<typename T>
	int CycleQueue<T>::getLength()
	{
		if (!this || !this->base)
		{
			exit(ERROR);
		}
		return this->length;
	}

	template<typename T>
	void CycleQueue<T>::clearQueue()
	{
		if (!this || !this->base)
		{
			exit(ERROR);
		}
		this->front = this->rear = 0;
		this->length = 0;
	}

	template<typename T>
	bool CycleQueue<T>::isQueueEmpty()
	{
		if (!this || !this->base)
		{
			exit(ERROR);
		}
		return this->length == 0 ? true : false;
	}

	template<typename T>
	bool CycleQueue<T>::isQueueFull()
	{
		if (!this || !this->base)
		{
			exit(ERROR);
		}
		return this->length == this->init_queue_size ? true : false;
	}
	
}


