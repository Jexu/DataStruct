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
		/*������ʶ����Ԫ��ʱ�����뵽ָ��position֮ǰ*/
		static const int FLAG_INSERT_PRIOR = 1;
		/*����һ��Ԫ�ص�˫�������У�Ĭ�ϲ��뵽������ĩ��*/
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
	/*��ʼ��˫������--ǰ��������ָ��NULL��length=0*/
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
	/*������ʶ����Ԫ��ʱ�����뵽ָ��position֮��*/
	//const int DulLinkList<T>::FLAG_INSERT_NEXT = 2;
	//template<typename T>
	/*����һ��Ԫ�ص�˫�������У�Ĭ�ϲ��뵽������ĩ��*/
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
	/*����Ԫ�ص�˫������ָ��λ��position֮ǰ(flag = FLAG_INSERT_PRIOR)/��(flag = FLAG_INSERT_NEXT)��position>=1 && position<= length*/
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
	/*��ȡָ��λ��position����Ԫ�أ�position>=1 && position<=length*/
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
	/*���Ҹ���Ԫ����˫�������е�һ�γ��ֵ�λ�ã����û���ҵ����򷵻�-1*/
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
	/*ɾ��˫��������Ԫ�أ�Ĭ��ɾ������βԪ��*/
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
	/*ɾ��˫��������ָ��λ��position����Ԫ�أ�position>=1 && position<=length*/
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
			p->next->prior = p->prior;	//ע�⣺ĩβԪ�ص�next=NULL��NULLû��ǰ��
		}
		this->length--;
		delete freeP;
		freeP = NULL;
	}
	template<typename T>
	/*���˫�������е�����Ԫ�أ�ֻʣ��һ��ͷ���*/
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
	/*��ȡ˫��������*/
	long DulLinkList<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}
	template<typename T>
	/*��ȡ��ǰ�ڵ��ϵ�Ԫ��*/
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

