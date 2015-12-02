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
	/*默认插到末尾,传入链表的头引用*/
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
	/*插入到指定位置，传入链表头引用,规定插入值为插入到第position个值之后，且position>=0 && position<=length；0表示插入到头结点之后*/
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
	/*默认删除最后一个元素*/
	void SingelLinkList<T>::deleteElement()
	{
		if (this == NULL || this->length <= 0)
		{
			exit(ERROR);
		}
		SingelLinkList<T> *p = this;
		while (p->next->next)
		{
			//将指针指向链表尾部
			p = p->next;
		}
		SingelLinkList<T> *freeP = p->next;
		p->next = p->next->next;
		this->length--;
		delete freeP;
		freeP = NULL;
	}
	template<typename T>
	/*删除第position个位置上的值，且position>0 && position<=length；从头结点后第一个值开始*/
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
	/*获取第position位置上的元素；position>0&&position<=length*/
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
	/*查找给定元素在链表中第一次出现的位置，position>=1 && position<=length；如果没找到，则返回-1*/
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
	/*清空链表*/
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
	/*获得链表长度*/
	int SingelLinkList<T>::getLength()
	{
		if (this == NULL)
		{
			exit(ERROR);
		}
		return this->length;
	}

	template<typename T>
	/*获得当前结点上的数据*/
	T SingelLinkList<T>::getData()
	{
		return this->data;
	}

}