#ifndef _LINK_QUEUE_C_H
#define _LINK_QUEUE_C_H
namespace linkQ_c
{
	const int ERROR = -1;
	template<typename T>
	/*������ÿ��Ԫ����������---Ϊһ����ָ���������*/
	struct SNode
	{
		SNode *next = NULL;
		T data;
	};

	template<typename T>
	/*��ʽ���е����ݽṹԭ��*/
	struct LinkQueue
	{
		/*ָ�����β��ָ��*/
		SNode<T> *rear = NULL;
		/*ָ�����ͷ��ָ��*/
		SNode<T> *front = NULL;
		/*�����е�ǰԪ�ظ���*/
		int length = 0;
	};

	template<typename T>
	/*��ʼ������*/
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
	/*��ȡ��ǰ����ͷ��Ԫ��ֵ*/
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
	/*���Ӳ�������Ԫ��ѹ�����β*/
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
	/*���Ӳ���������ͷԪ�ص���*/
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
	/*��ն���������Ԫ��*/
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