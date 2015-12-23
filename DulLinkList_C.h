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
	/*˫������ԭ��*/
	struct DulLinkList
	{
		DLLNode<T> *head;
		int length;
	};

	template<typename T>
	/*��ʼ��˫������--ǰ��������ָ��NULL��length=0*/
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
	/*����һ��Ԫ�ص�˫�������У�Ĭ�ϲ��뵽������ĩ��*/
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
	/*����Ԫ�ص�˫������ָ��λ��position֮ǰ��position>=1 && position<= length*/
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
	/*����Ԫ�ص�˫������ָ��λ��position֮��position>=1 && position<= length*/
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
	/*��ȡָ��λ��position����Ԫ�أ�position>=1 && position<=length*/
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
	/*���Ҹ���Ԫ����˫�������е�һ�γ��ֵ�λ�ã����û���ҵ����򷵻�-1*/
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
	/*ɾ��˫��������Ԫ�أ�Ĭ��ɾ������βԪ��*/
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
	/*ɾ��˫��������ָ��λ��position����Ԫ�أ�position>=1 && position<=length*/
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
			p->next->prior = p->prior;	//ע�⣺ĩβԪ�ص�next=NULL��NULLû��ǰ��
		}
		dll.length--;
		delete freeP;
		freeP = NULL;
		p = NULL;
	}

	template<typename T>
	/*���˫�������е�����Ԫ�أ�ֻʣ��һ��ͷ���*/
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