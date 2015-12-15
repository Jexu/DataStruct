#include<iostream>
#include<malloc.h>
using namespace std;

namespace cq_c
{
	const int ERROR = -1;
#define INIT_QUEUE_SIZE 100

	template<typename T>
	struct CycleQueue
	{
		/*指向队列基地址的指针*/
		T *base = NULL;
		/*指向循环队列尾的伪指针*/
		int rear = 0;
		/*指向循环队列头的伪指针*/
		int front = 0;
		/*当前队列中元素个数*/
		int length = 0;
	};

	template<typename T>
	/*初始化队列操作，分配初始化队列的内存空间*/
	void initQueue(CycleQueue<T> &cq)
	{
		if (&cq == NULL)
		{
			exit(ERROR);
		}
		cq.base = (T *)malloc(INIT_QUEUE_SIZE*sizeof(T));
		if (!cq.base)
		{
			exit (ERROR);
		}
		cq.front = cq.rear = 0;
		cq.length = 0;
	}

	template<typename T>
	/*获取队列头元素值，获取前应该先检查队空*/
	T getHead(CycleQueue<T> cq)
	{
		if (&cq == NULL || !cq.base || cq.length == 0)
		{
			exit(ERROR);
		}
		return *(cq.base + cq.front);
	}

	template<typename T>
	/*入队操作，入队前应该先检查队满*/
	void inQueue(CycleQueue<T> &cq, T e)
	{
		if (&cq == NULL || !cq.base || (cq.rear + 1)%INIT_QUEUE_SIZE == cq.front)
		{
			exit(ERROR);
		}
		*(cq.base + cq.rear) = e;
		cq.length++;
		cq.rear = (cq.rear + 1) % INIT_QUEUE_SIZE;
	}

	template<typename T>
	/*出对操作，返回队头元素值，出队前应该先检查队空*/
	T outQueue(CycleQueue<T> &cq)
	{
		if (&cq == NULL || !cq.base || cq.front == cq.rear)
		{
			exit(ERROR);
		}
		T e = *(cq.base + cq.front);
		cq.length--;
		cq.front = (cq.front + 1) % INIT_QUEUE_SIZE;
		return e;
	}

	template<typename T>
	/*清空队列*/
	void clearQueue(CycleQueue<T> &cq)
	{
		if (&cq == NULL || !cq.base)
		{
			exit(ERROR);
		}
		cq.front = cq.rear = 0;
		cq.length = 0;
	}

	template<typename T>
	/*判断队列是否为空*/
	bool isQueueEmpty(CycleQueue<T> cq)
	{
		if (&cq == NULL || !cq.base)
		{
			exit(ERROR);
		}
		return cq.length == 0 ? true : false;
	}

	template<typename T>
	/*判断队列是否满*/
	bool isQueueFull(CycleQueue<T> cq)
	{
		if (&cq == NULL || !cq.base)
		{
			exit(ERROR);
		}
		return cq.length == INIT_QUEUE_SIZE ? true : false;
	}
}