#ifndef _LINK_QUEUE_C_H
#define _LINK_QUEUE_C_H
namespace linkQ_c
{
	const int ERROR = -1;
	template<typename T>
	/*队列中每个元素数据类型---为一个带指针的数据域*/
	struct SNode
	{
		SNode *next = NULL;
		T data;
	};

	template<typename T>
	/*链式队列的数据结构原型*/
	struct LinkQueue
	{
		/*指向队列尾的指针*/
		SNode<T> *rear = NULL;
		/*指向队列头的指针*/
		SNode<T> *front = NULL;
		/*队列中当前元素个数*/
		int length = 0;
	};

	template<typename T>
	/*初始化队列*/
	void initQueue(LinkQueue<T> &lq)
	{
		if (&lq == NULL)
		{
			exit(ERROR);
		}
		SNode<T> *rear = new SNode<T>;
		if (!rear)
		{
			exit(ERROR);
		}
		rear->next = NULL;
		lq.rear = rear;
		lq.front = lq.rear;
		lq.length = 0;
		rear = NULL;
	}

	template<typename T>
	/*获取当前队列头的元素值*/
	T getHead(const LinkQueue<T> &lq)
	{
		if (&lq == NULL || lq.front == NULL ||lq.rear == NULL)
		{
			exit(ERROR);
		}
		if (lq.rear == lq.front || lq.front->next == NULL || lq.length == 0)
		{
			exit(ERROR);
		}
		return lq.front->next->data;
	}

	template<typename T>
	/*进队操作，将元素压入队列尾*/
	void inQueue(LinkQueue<T> &lq, T data)
	{
		if (&lq == NULL || lq.front == NULL || lq.rear == NULL)
		{
			exit(ERROR);
		}
		SNode<T> *newRear = new SNode<T>;
		if (!newRear)
		{
			exit(ERROR);
		}
		newRear->data = data;
		newRear->next = NULL;
		lq.rear->next = newRear;
		lq.rear = newRear;
		lq.length++;
		newRear = NULL;
	}

	template<typename T>
	/*出队操作，将队头元素弹出*/
	T OutQueue(LinkQueue<T> &lq)
	{
		if (&lq == NULL || lq.front == NULL || lq.rear == NULL)
		{
			exit(ERROR);
		}
		if (lq.rear == lq.front || lq.front->next == NULL || lq.length == 0)
		{
			exit(ERROR);
		}
		T data = lq.front->next->data;
		SNode<T> *freeP = lq.front;
		lq.front = lq.front->next;
		delete freeP;
		freeP = NULL;
		lq.length--;
		return data;
	}

	template<typename T>
	/*清空队列中所有元素*/
	void clearQueue(LinkQueue<T> &lq)
	{
		if (&lq == NULL || lq.front == NULL || lq.rear == NULL)
		{
			exit(ERROR);
		}
		if (lq.rear == lq.front || lq.front->next == NULL || lq.length == 0)
		{
			exit(ERROR);
		}
		while (lq.front->next)
		{
			SNode<T> *freeP = lq.front;
			lq.front = lq.front->next;
			delete freeP;
			freeP = NULL;
		}
		lq.length = 0;
	}
}
#endif