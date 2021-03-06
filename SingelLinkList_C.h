#pragma once
#ifndef _SINGEL_LINK_LIST_C_H
#define _SINGEL_LINK_LIST_C_H
namespace sll_c {
	/*插入元素时候标记，升序插入*/
	#define FLAG_ORDER_ASC 1;
	/*插入元素时候标记，降序插入*/
	#define FLAG_ORDER_DESC 2;
	const int ERROR = -1;
	template <typename T>
	struct SLLNode
	{
		T data;
		SLLNode *next = NULL;
	};
	template<typename T>
	struct SingelLinkList
	{
		SLLNode<T> *head;
		int length;
	};

	/*创建带头结点的链表，初始化就是创建一个空头*/
	template <typename T>
	void initSingelLinkList(SingelLinkList<T> &sll)
	{
		if (&sll == NULL)
		{
			exit(ERROR);
		}
		sll.head = new SLLNode<T>;
		if (!sll.head)
		{
			exit(ERROR);
		}
		sll.length = 0;
	}

	template <typename T>
	/*默认插到末尾,传入链表的头引用*/
	void insertElement(SingelLinkList<T> &sll, T data)
	{
		if (&sll == NULL)
		{
			exit(ERROR);
		}
		SLLNode<T> *p = sll.head;
		while (p->next)
		{
			//将指针指向链表尾部
			p = p->next;
		}
		SLLNode<T> *newP = new SLLNode<T>;
		if (!newP)
		{
			exit(ERROR);
		}
		newP->data = data;
		newP->next = NULL;
		sll.length++;
		p->next = newP;
		newP = NULL;
	}

	template <typename T>
	/*插入到指定位置，传入链表头引用,规定插入值为插入到第position个值之后，且position>=0 && position<=length；0表示插入到头结点之后*/
	void insertElement(SingelLinkList<T> &sll, T data, long position)
	{
		if (&sll == NULL)
		{
			exit(ERROR);
		}
		if (position < 0 || position > sll.length)
		{
			exit(ERROR);
		}
		int index = 0;
		SLLNode<T> *p = sll.head;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		SLLNode<T> *newP = new SLLNode<T>;
		newP->data = data;
		newP->next = p->next;
		p->next = newP;
		sll.length++;
		newP = NULL;
	}
	template<typename T>
	/*插入元素到单向链表中，升序（FLAG_ORDER_ASC）或者降序（FLAG_ORDER_DESC）*/
	void insertElementOrdered(SingelLinkList<T> &sll,T data,int flag)
	{
		if (&sll == NULL)
		{
			exit(ERROR);
		}
		SLLNode<T> *p = sll.head;
		switch (flag)
		{
		case FLAG_ORDER_ASC:
			while (p->next)
			{
				p = p->next;
				if (p->data <= data)
				{
					if (p->next)
					{
						//表示还不是最后一个节点
						if (p->next->data >= data)
						{
							//插到p后面
						}
					}
					else
					{
						//已经是最后一个结点，且上面数据比data小，则将data插入到尾
					}
				}
				else
				{

				}
			}
			break;
		case FLAG_ORDER_DESC:

			break;
		default:
			break;
		}
	}
	template<typename T>
	/*默认删除最后一个元素*/
	void deleteElement(SingelLinkList<T> &sll)
	{
		if (&sll == NULL || sll.length <= 0)
		{
			exit(ERROR);
		}
		SLLNode<T> *p = sll.head;
		while (p->next->next)
		{
			//将指针指向链表尾部
			p = p->next;
		}
		SLLNode<T> *freeP = p->next;
		p->next = p->next->next;
		sll.length--;
		delete freeP;
		freeP = NULL;
	}

	template<typename T>
	/*删除第position个位置上的值，且position>0 && position<=length；从头结点后第一个值开始*/
	void deleteElement(SingelLinkList<T> &sll, long position)
	{
		if (&sll == NULL)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > sll.length)
		{
			exit(ERROR);
		}
		int index = 0;
		SLLNode<T> *p = sll.head;
		while (p->next->next && index < position - 1)
		{
			p = p->next;
			index++;
		}
		SLLNode<T> *freeP = p->next;
		p->next = p->next->next;
		sll.length--;
		delete freeP;
		freeP = NULL;
	}

	template<typename T>
	/*获取第position位置上的元素；position>0&&position<=length*/
	T getElement(const SingelLinkList<T> &sll, long position)
	{
		if (&sll == NULL)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > sll.length)
		{
			exit(ERROR);
		}
		int index = 0;
		const SLLNode<T> *p = sll.head;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		return p->data;
	}

	template<typename T>
	/*查找给定元素在链表中出现的第一次位置，position>=1 && position<=length；如果没找到，则返回-1*/
	int findElement(const SingelLinkList<T> &sll, T data)
	{
		if (&sll == NULL)
		{
			exit(ERROR);
		}
		int index = 0;
		const SLLNode<T> *p = sll.head;
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
	void clearSingelLinkList(SingelLinkList<T> &sll)
	{
		if (&sll == NULL)
		{
			exit(ERROR);
		}
		while (sll.length > 0)
		{
			deleteElement(sll,1);
		}
	}
}
#endif