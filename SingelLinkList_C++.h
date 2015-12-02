#pragma once
#include<iostream>
using namespace std;

namespace sll_cpp {


	const int ERROR = -1;
	template<typename T>
	class SingelLinkList
	{
	public:
		SingelLinkList();
		virtual ~SingelLinkList();
		void insertElement(T data);
		void insertElement(T data, long position);
		void deleteElement();
		void deleteElement(long position);
		T getElement(long position);
		int findElement(T data);
		void clearSingelLinkList();
		int getLength();
		T getData();
		SingelLinkList<T> *next = NULL;
	private:
		union {
			T data;
			int length = 0;
		};
	};


	template<typename T>
	SingelLinkList<T>::SingelLinkList()
	{
		this->next = NULL;
		this->length = 0;
	}

	template<typename T>
	SingelLinkList<T>::~SingelLinkList()
	{

	}

	template<typename T>
	/*Ĭ�ϲ嵽ĩβ,���������ͷ����*/
	void SingelLinkList<T>::insertElement(T data)
	{
		if (!this)
		{
			exit(ERROR);
		}
		SingelLinkList<T> *p = this;
		while (p->next)
		{
			p = p->next;
		}
		SingelLinkList<T> *newP = new SingelLinkList<T>();
		newP->data = data;
		newP->next = NULL;
		p->next = newP;
		this->length++;
	}
	template<typename T>
	/*���뵽ָ��λ�ã���������ͷ����,�涨����ֵΪ���뵽��position��ֵ֮����position>=0 && position<=length��0��ʾ���뵽ͷ���֮��*/
	void SingelLinkList<T>::insertElement(T data, long position)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (position < 0 || position > this->length)
		{
			exit(ERROR);
		}
		int index = 0;
		SingelLinkList<T> *p = this;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		SingelLinkList<T> *newP = new SingelLinkList<T>();
		newP->data = data;
		newP->next = p->next;
		p->next = newP;
		this->length++;
	}

	template<typename T>
	/*Ĭ��ɾ�����һ��Ԫ��*/
	void SingelLinkList<T>::deleteElement()
	{
		if (this == NULL || this->length <= 0)
		{
			exit(ERROR);
		}
		SingelLinkList<T> *p = this;
		while (p->next->next)
		{
			//��ָ��ָ������β��
			p = p->next;
		}
		SingelLinkList<T> *freeP = p->next;
		p->next = p->next->next;
		this->length--;
		delete freeP;
		freeP = NULL;
	}
	template<typename T>
	/*ɾ����position��λ���ϵ�ֵ����position>0 && position<=length����ͷ�����һ��ֵ��ʼ*/
	void SingelLinkList<T>::deleteElement(long position)
	{
		if (this == NULL)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > this->length)
		{
			exit(ERROR);
		}
		int index = 0;
		SingelLinkList<T> *p = this;
		while (p->next->next && index < position - 1)
		{
			p = p->next;
			index++;
		}
		SingelLinkList<T> *freeP = p->next;
		p->next = p->next->next;
		this->length--;
		delete freeP;
		freeP = NULL;
	}
	template<typename T>
	/*��ȡ��positionλ���ϵ�Ԫ�أ�position>0&&position<=length*/
	T SingelLinkList<T>::getElement(long position)
	{
		if (this == NULL)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > this->length)
		{
			exit(ERROR);
		}
		int index = 0;
		SingelLinkList<T> *p = this;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		return p->getData();
	}

	template<typename T>
	/*���Ҹ���Ԫ���������е�һ�γ��ֵ�λ�ã�position>=1 && position<=length�����û�ҵ����򷵻�-1*/
	int SingelLinkList<T>::findElement(T data)
	{
		if (!this)
		{
			exit(ERROR);
		}
		int index = 0;
		SingelLinkList<T> *p = this;
		while (p->next)
		{
			p = p->next;
			index++;
			if (p->data == data)
			{
				p = NULL;
				return index;
			}
		}
		p = NULL;
		return -1;
	}
	template<typename T>
	/*�������*/
	void SingelLinkList<T>::clearSingelLinkList()
	{
		if (this == NULL)
		{
			exit(ERROR);
		}
		while (this->length > 0)
		{
			this->deleteElement(1);
		}
	}

	template<typename T>
	/*���������*/
	int SingelLinkList<T>::getLength()
	{
		if (this == NULL)
		{
			exit(ERROR);
		}
		return this->length;
	}

	template<typename T>
	/*��õ�ǰ����ϵ�����*/
	T SingelLinkList<T>::getData()
	{
		return this->data;
	}

}