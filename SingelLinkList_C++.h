#pragma once
#ifndef _SINGEL_LINK_LIST_CPP_H
#define _SINGEL_LINK_LIST_CPP_H
namespace sll_cpp {
	const int ERROR = -1;

	template<typename T>
	/*单向链表类*/
	class SingelLinkList
	{
	public:
		SingelLinkList();
		SingelLinkList(SingelLinkList &sl);
		virtual ~SingelLinkList();
		void insertElement(T data);
		void insertElement(T data, long position);
		void deleteElement();
		void deleteElement(long position);
		T getElement(long position);
		int findElement(T data);
		void clearSingelLinkList();
		int getLength();
	private:
		/*单向链表结点类*/
		class LNODE
		{
		public:
			/*无参构造函数*/
			LNODE()
			{
				this->next = NULL;
			};
			/*拷贝构造函数*/
			LNODE(LNODE &ln)
			{
				if (this->next)
				{
					delete this->next;
				}
				this->next = next;
				this->data = ln.data;
			};
			/*析构函数*/
			~LNODE() {};
			/*结点数据*/
			T data;
			/*指向下一个结点的指针*/
			LNODE *next;
		};
		int length = 0;
		LNODE *head;
	};
	
	template<typename T>
	SingelLinkList<T>::SingelLinkList()
	{
		this->head = new LNODE();
		if (!this->head)
		{
			exit(ERROR);
		}
		this->length = 0;
	}
	template<typename T>
	SingelLinkList<T>::SingelLinkList(SingelLinkList &sl)
	{
		if (&sl == NULL)
		{
			exit(ERROR);
		}
		if (this->head)
		{
			delete this->head;
		}
		this->head = sl.head;
		this->length = sl.length;
	}
	template<typename T>
	SingelLinkList<T>::~SingelLinkList()
	{
		if (this->head)
		{
			this->clearSingelLinkList();
			delete this->head;
		}
	}

	template<typename T>
	/*默认插到末尾,传入链表的头引用*/
	void SingelLinkList<T>::insertElement(T data)
	{
		if (!this)
		{
			exit(ERROR);
		}
		LNODE *p = this->head;
		while (p->next)
		{
			p = p->next;
		}
		LNODE *newP = new LNODE();
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
		LNODE *p = this->head;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		LNODE *newP = new LNODE();
		newP->data = data;
		newP->next = p->next;
		p->next = newP;
		this->length++;
	}

	template<typename T>
	/*默认删除最后一个元素*/
	void SingelLinkList<T>::deleteElement()
	{
		if (!this || this->length <= 0)
		{
			exit(ERROR);
		}
		LNODE *p = this->head;
		while (p->next->next)
		{
			//将指针指向链表尾部
			p = p->next;
		}
		LNODE *freeP = p->next;
		p->next = p->next->next;
		this->length--;
		delete freeP;
		freeP = NULL;
	}
	template<typename T>
	/*删除第position个位置上的值，且position>0 && position<=length；从头结点后第一个值开始*/
	void SingelLinkList<T>::deleteElement(long position)
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
		LNODE *p = this->head;
		while (p->next->next && index < position - 1)
		{
			p = p->next;
			index++;
		}
		LNODE *freeP = p->next;
		p->next = p->next->next;
		this->length--;
		delete freeP;
		freeP = NULL;
	}
	template<typename T>
	/*获取第position位置上的元素；position>0&&position<=length*/
	T SingelLinkList<T>::getElement(long position)
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
		LNODE *p = this->head;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		return p->data;
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
		LNODE *p = this->head;
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
	/*获得链表长度*/
	int SingelLinkList<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}
}
#endif