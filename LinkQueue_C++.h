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
		/*�ڲ���---������ÿ��Ԫ��������*/
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
	/*���캯���ڳ�ʼ����ʽ����*/
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
	/*��ȡ��ǰ���ж���Ԫ��ֵ*/
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
	/*���Ӳ�������Ԫ��ѹ���β*/
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
	/*���Ӳ����������ж�Ԫ�ص���*/
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
	/*��ն���������Ԫ��*/
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
	/*��ȡ��ǰ������Ԫ�ظ���*/
	int LinkQueue<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}

}


