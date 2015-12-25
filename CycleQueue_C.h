#ifndef _CYCLE_QUEUE_C_H
#define _CYCLE_QUEUE_C_H
namespace cq_c
{
#define INIT_QUEUE_SIZE 100
	const int ERROR = -1;
	template<typename T>
	struct CycleQueue
	{
		/*ָ����л���ַ��ָ��*/
		T *base = NULL;
		/*ָ��ѭ������β��αָ��*/
		int rear = 0;
		/*ָ��ѭ������ͷ��αָ��*/
		int front = 0;
		/*��ǰ������Ԫ�ظ���*/
		int length = 0;
	};

	template<typename T>
	/*��ʼ�����в����������ʼ�����е��ڴ�ռ�*/
	void initQueue(CycleQueue<T> &cq)
	{
		if (&cq == NULL)
		{
			exit(ERROR);
		}
		if (cq.base)
		{
			cq.front = cq.rear = 0;
			cq.length = 0;
		}
		else
		{
			cq.base = new T[INIT_QUEUE_SIZE];
			if (!cq.base)
			{
				exit (ERROR);
			}
			cq.front = cq.rear = 0;
			cq.length = 0;
		}
	}

	template<typename T>
	/*��ȡ����ͷԪ��ֵ����ȡǰӦ���ȼ��ӿ�*/
	T getHead(const CycleQueue<T> &cq)
	{
		if (&cq == NULL || !cq.base || cq.length == 0)
		{
			exit(ERROR);
		}
		return *(cq.base + cq.front);
	}

	template<typename T>
	/*��Ӳ��������ǰӦ���ȼ�����*/
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
	/*���Բ��������ض�ͷԪ��ֵ������ǰӦ���ȼ��ӿ�*/
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
	/*��ն���*/
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
	/*�ж϶����Ƿ�Ϊ��*/
	bool isQueueEmpty(CycleQueue<T> cq)
	{
		if (&cq == NULL || !cq.base)
		{
			exit(ERROR);
		}
		return cq.length == 0 ? true : false;
	}

	template<typename T>
	/*�ж϶����Ƿ���*/
	bool isQueueFull(CycleQueue<T> cq)
	{
		if (&cq == NULL || !cq.base)
		{
			exit(ERROR);
		}
		return cq.length == INIT_QUEUE_SIZE ? true : false;
	}
}
#endif