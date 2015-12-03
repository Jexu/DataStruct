#pragma once
#include<iostream>
using namespace std;

namespace dll_cpp {
	const int ERROR = -1;
	template<typename T>
	class DulLinkList
	{
	public:
		DulLinkList();
		virtual ~DulLinkList();
		void insertElement(T data);
		void insertElement(T data, long position, int flag);
		T getElement(long position);
		long findElement(T data);
		void deleteElement();
		void deleteElement(long position);
		void clearDulLinkList();
		long getLength();
		//bool hasNext();
		//bool hasPrevious();
		T getData();
		/*用来标识插入元素时，插入到指定position之前*/
		static const int FLAG_INSERT_PRIOR = 1;
		/*插入一个元素到双向链表中，默认插入到链表最末端*/
		static const int FLAG_INSERT_NEXT = 2;
		DulLinkList<T> *prior = NULL;
		DulLinkList<T> *next = NULL;
	private:
		union
		{
			T data;
			long length = 0;
		};
	};

	template<typename T>
	/*初始化双向链表--前驱，后驱指向NULL，length=0*/
	DulLinkList<T>::DulLinkList()
	{
		this->length = 0;
		this->prior = NULL;
		this->next = NULL;
	}
	template<typename T>
	DulLinkList<T>::~DulLinkList()
	{

	}
	template<typename T>
	
	//const int DulLinkList<T>::FLAG_INSERT_PRIOR = 1;
	//template<typename T>
	/*用来标识插入元素时，插入到指定position之后*/
	//const int DulLinkList<T>::FLAG_INSERT_NEXT = 2;
	//template<typename T>
	/*插入一个元素到双向链表中，默认插入到链表最末端*/
	void DulLinkList<T>::insertElement(T data)
	{
		if (!this)
		{
			exit(ERROR);
		}
		DulLinkList<T> *p = this;
		while (p->next)
		{
			p = p->next;
		}
		DulLinkList<T> *newP = new DulLinkList<T>;
		newP->data = data;
		newP->next = NULL;
		newP->prior = p;
		p->next = newP;
		this->length++;
		p = NULL;
	}
	template<typename T>
	/*插入元素到双向链表指定位置position之前(flag = FLAG_INSERT_PRIOR)/后(flag = FLAG_INSERT_NEXT)，position>=1 && position<= length*/
	void DulLinkList<T>::insertElement(T data, long position, const int flag)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > this->length)
		{
			exit(ERROR);
		}
		int index = 0;
		DulLinkList<T> *p = this;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		DulLinkList<T> *newP = new DulLinkList<T>();
		newP->data = data;
		switch (flag)
		{
		case DulLinkList::FLAG_INSERT_PRIOR:
			newP->next = p;
			newP->prior = p->prior;
			p->prior->next = newP;
			p->prior = newP;
			break;

		case DulLinkList::FLAG_INSERT_NEXT:
			newP->next = p->next;
			newP->prior = p;
			if (position != this->length)
			{
				p->next->prior = newP;
			}
			p->next = newP;
			break;
		default:
			break;
		}
		this->length++;
		p = NULL;
	}
	template<typename T>
	/*获取指定位置position处的元素，position>=1 && position<=length*/
	T DulLinkList<T>::getElement(long position)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > this->length)
		{
			exit(ERROR);
		}
		int index = 0;
		DulLinkList<T> *p = this;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		return p->data;
	}
	template<typename T>
	/*查找给定元素在双向链表中第一次出现的位置，如果没有找到，则返回-1*/
	long DulLinkList<T>::findElement(T data)
	{
		if (!this)
		{
			exit(ERROR);
		}
		int index = 0;
		DulLinkList<T> *p = this;
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
	/*删除双向链表中元素，默认删除链表尾元素*/
	void DulLinkList<T>::deleteElement()
	{
		if (!this)
		{
			exit(ERROR);
		}
		DulLinkList<T> *p = this;
		while (p->next)
		{
			p = p->next;
		}
		DulLinkList<T> *freeP = p;
		p->prior->next = p->next;
		this->length--;
		delete freeP;
		freeP = NULL;
	}
	template<typename T>
	/*删除双向链表中指定位置position处的元素，position>=1 && position<=length*/
	void DulLinkList<T>::deleteElement(long position)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > this->length)
		{
			exit(ERROR);
		}
		int index = 0;
		DulLinkList<T> *p = this;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		DulLinkList<T> *freeP = p;
		p->prior->next = p->next;
		if (position != this->length)
		{
			p->next->prior = p->prior;	//注意：末尾元素的next=NULL，NULL没有前驱
		}
		this->length--;
		delete freeP;
		freeP = NULL;
	}
	template<typename T>
	/*清空双向链表中的所有元素，只剩下一个头结点*/
	void DulLinkList<T>::clearDulLinkList()
	{
		if (!this)
		{
			exit(ERROR);
		}
		while (this->length > 0)
		{
			this->deleteElement(1);
		}
	}
	template<typename T>
	/*获取双向链表长度*/
	long DulLinkList<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}
	template<typename T>
	/*获取当前节点上的元素*/
	T DulLinkList<T>::getData()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->data;
	}
	/*template<typename T>
	bool DulLinkList<T>::hasNext()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this = this->next)
		{
			return true;
		}
		return false;
	}

	template<typename T>
	bool DulLinkList<T>::hasPrevious()
	{
		if (!this)
		{	
			exit(ERROR);
		}
		if (this = this->prior)
		{
			return true;
		}
		return false;
	}*/
}

