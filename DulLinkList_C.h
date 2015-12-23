#ifndef _DUL_LINK_LIST_H
#define _DUL_LINK_LIST_H
namespace dll_c {
	const int ERROR = -1;
	template<typename T>
	struct DLLNode
	{
		T data;
		DLLNode *prior = NULL;
		DLLNode *next = NULL;
	};
	template<typename T>
	/*双向链表原型*/
	struct DulLinkList
	{
		DLLNode<T> *head;
		int length;
	};

	template<typename T>
	/*初始化双向链表--前驱，后驱指向NULL，length=0*/
	void initDulLinkList(DulLinkList<T> &dll)
	{
		if (&dll == NULL)
		{
			exit(ERROR);
		}
		dll.head = new DLLNode<T>;
		if (!dll.head)
		{
			exit(ERROR);
		}
		dll.head->prior = NULL;
		dll.length = 0;
	}

	template<typename T>
	/*插入一个元素到双向链表中，默认插入到链表最末端*/
	void insertElement(DulLinkList<T> &dll, T data)
	{
		if (&dll == NULL)
		{
			exit(ERROR);
		}
		DLLNode<T> *p = dll.head;
		while (p->next)
		{
			p = p->next;
		}
		DLLNode<T> *newP = new DLLNode<T>;
		newP->data = data;
		newP->next = NULL;
		newP->prior = p;
		p->next = newP;
		dll.length++;
		p = NULL;
		newP = NULL;
	}

	template<typename T>
	/*插入元素到双向链表指定位置position之前，position>=1 && position<= length*/
	void insertElementPrior(DulLinkList<T> &dll, T data, long position)
	{
		if (&dll == NULL)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > dll.length)
		{
			exit(ERROR);
		}
		int index = 0;
		DLLNode<T> *p = dll.head;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		DLLNode<T> *newP = new DLLNode<T>;
		newP->data = data;
		newP->next = p;
		newP->prior = p->prior;
		p->prior->next = newP;
		p->prior = newP;
		dll.length++;
		p = NULL;
		newP = NULL;
	}
	template<typename T>
	/*插入元素到双向链表指定位置position之后，position>=1 && position<= length*/
	void insertElementNext(DulLinkList<T> &dll, T data, long position)
	{
		if (&dll == NULL)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > dll.length)
		{
			exit(ERROR);
		}
		int index = 0;
		DLLNode<T> *p = dll.head;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		DLLNode<T> *newP = new DLLNode<T>;
		newP->data = data;
		newP->next = p->next;
		newP->prior = p;
		if (position != dll.length)
		{
			p->next->prior = newP;
		}
		p->next = newP;
		dll.length++;
		p = NULL;
		newP = NULL;
	}

	template<typename T>
	/*获取指定位置position处的元素，position>=1 && position<=length*/
	T getElement(const DulLinkList<T> &dll, long position)
	{
		if (&dll == NULL)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > dll.length)
		{
			exit(ERROR);
		}
		int index = 0;
		const DLLNode<T> *p = dll.head;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		return p->data;
	}

	template<typename T>
	/*查找给定元素在双向链表中第一次出现的位置，如果没有找到，则返回-1*/
	long findElement(const DulLinkList<T> &dll, T data)
	{
		if (&dll == NULL)
		{
			exit(ERROR);
		}
		int index = 0;
		const DLLNode<T> *p = dll.head;
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
	void deleteElement(DulLinkList<T> &dll)
	{
		if (&dll == NULL)
		{
			exit(ERROR);
		}
		DLLNode<T> *p = dll.head;
		while (p->next)
		{
			p = p->next;
		}
		DLLNode<T> *freeP = p;
		p->prior->next = p->next;
		dll.length--;
		delete freeP;
		freeP = NULL;
		p = NULL;
	}

	template<typename T>
	/*删除双向链表中指定位置position处的元素，position>=1 && position<=length*/
	void deleteElement(DulLinkList<T> &dll, long position)
	{
		if (&dll == NULL)
		{
			exit(ERROR);
		}
		if (position <= 0 || position > dll.length)
		{
			exit(ERROR);
		}
		int index = 0;
		DLLNode<T> *p = dll.head;
		while (p->next && index < position)
		{
			p = p->next;
			index++;
		}
		DLLNode<T> *freeP = p;
		p->prior->next = p->next;
		if (position != dll.length)
		{
			p->next->prior = p->prior;	//注意：末尾元素的next=NULL，NULL没有前驱
		}
		dll.length--;
		delete freeP;
		freeP = NULL;
		p = NULL;
	}

	template<typename T>
	/*清空双向链表中的所有元素，只剩下一个头结点*/
	void clearDulLinkList(DulLinkList<T> &dll)
	{
		if (&dll == NULL)
		{
			exit(ERROR);
		}
		while (dll.length > 0)
		{
			deleteElement(dll, 1);
		}
	}
}
#endif