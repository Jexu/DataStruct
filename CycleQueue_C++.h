#ifndef _CYCLE_QUEUE_CPP_H
#define _CYCLE_QUEUE_CPP_H
namespace cq_cpp
{	
	const int ERROR = -1;
	template<typename T>
	/*ѭ��������---����ʵ��*/
	class CycleQueue
	{
	public:
		/*Ĭ�Ϲ��캯����Ĭ�ϴ�����СΪI_Q_S��ѭ������*/
		CycleQueue();
		/*ָ�������Ӧ��С��ѭ������*/
		CycleQueue(int queueSize);
		/*�������캯��*/
		CycleQueue(CycleQueue &cq);
		/*��������������ѭ������*/
		virtual ~CycleQueue();
		/*��ȡ����ͷԪ��ֵ����ȡǰӦ���ȼ��ӿ�*/
		T getHead();
		/*��Ӳ��������ǰӦ���ȼ�����*/
		void inQueue(T e);
		/*���Բ��������ض�ͷԪ��ֵ������ǰӦ���ȼ��ӿ�*/
		T outQueue();
		/*��ȡ��ǰ������Ԫ�ظ���*/
		int getLength();
		/*��ն���*/
		void clearQueue();
		/*�ж϶����Ƿ�Ϊ��*/
		bool isQueueEmpty();
		/*�ж϶����Ƿ���*/
		bool isQueueFull();
		/*=����������*/
		CycleQueue& operator=(CycleQueue &cq);
	private:
		/*ָ����л���ַ��ָ��*/
		T *base = NULL;
		/*ָ��ѭ������β��αָ��*/
		int rear = 0;
		/*ָ��ѭ������ͷ��αָ��*/
		int front = 0;
		/*��ǰ������Ԫ�ظ���*/
		int length = 0;
		/*��ʼ��ʱ������ѭ�����д�С*/
		int init_queue_size;
		/*Ĭ�Ϲ���ѭ�����д�СΪ100*/
		static const int I_Q_S = 100;
	};
	template<typename T>
	CycleQueue<T>::CycleQueue()
	{
		if (!this)
		{
			exit(ERROR);
		}
		this->base = new T[I_Q_S];
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
		this->base = new T[queueSize];
		if (!this->base)
		{
			exit(ERROR);
		}
		this->front = this->rear = 0;
		this->length = 0;
		this->init_queue_size = queueSize;
	}
	template<typename T>
	CycleQueue<T>::CycleQueue(CycleQueue &cq)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->init_queue_size != cq.init_queue_size)
		{
			if (this->base)
			{
				delete[] this->base;
			}
			this->base = new T[cq.init_queue_size];
			if (!this->base)
			{
				exit(ERROR);
			}
			this->front = this->rear = 0;
			this->init_queue_size = cq.init_queue_size;
		}
		else if(this->base && this->init_queue_size == cq.init_queue_size)
		{
			this->front = this->rear = 0;
		}
		for (int i = 0; i < cq.length; i++)
		{
			*(this->base + (cq.front + i)%cq.init_queue_size)  = *(cq.base + (cq.front + i) % cq.init_queue_size);
		}
		this->front = cq.front;
		this->rear = cq.rear;
		this->length = cq.length;
	}

	template<typename T>
	CycleQueue<T>::~CycleQueue()
	{
		if (this && this->base)
		{
			delete[] this->base;
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
	template<typename T>
	CycleQueue<T>& CycleQueue<T>::operator=(CycleQueue &cq)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->init_queue_size != cq.init_queue_size)
		{
			if (this->base)
			{
				delete[] this->base;
			}
			this->base = new T[cq.init_queue_size];
			if (!this->base)
			{
				exit(ERROR);
			}
			this->front = this->rear = 0;
			this->init_queue_size = cq.init_queue_size;
		}
		else if (this->base && this->init_queue_size == cq.init_queue_size)
		{
			this->front = this->rear = 0;
		}
		for (int i = 0; i < cq.length; i++)
		{
			*(this->base + (cq.front + i) % cq.init_queue_size) = *(cq.base + (cq.front + i) % cq.init_queue_size);
		}
		this->front = cq.front;
		this->rear = cq.rear;
		this->length = cq.length;
		return *this;
	}
}
#endif


