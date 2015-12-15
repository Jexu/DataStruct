#pragma once
#include<iostream>
#include<malloc.h>
using namespace std;

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


