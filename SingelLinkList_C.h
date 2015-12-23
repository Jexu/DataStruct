#pragma once
#ifndef _SINGEL_LINK_LIST_C_H
#define _SINGEL_LINK_LIST_C_H
namespace sll_c {
	/*����Ԫ��ʱ���ǣ��������*/
	#define FLAG_ORDER_ASC 1;
	/*����Ԫ��ʱ���ǣ��������*/
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

	/*������ͷ����������ʼ�����Ǵ���һ����ͷ*/
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
	/*Ĭ�ϲ嵽ĩβ,���������ͷ����*/
	void insertElement(SingelLinkList<T> &sll, T data)
	{
		if (&sll == NULL)
		{
			exit(ERROR);
		}
		SLLNode<T> *p = sll.head;
		while (p->next)
		{
			//��ָ��ָ������β��
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
	/*���뵽ָ��λ�ã���������ͷ����,�涨����ֵΪ���뵽��position��ֵ֮����position>=0 && position<=length��0��ʾ���뵽ͷ���֮��*/
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
	/*����Ԫ�ص����������У�����FLAG_ORDER_ASC�����߽���FLAG_ORDER_DESC��*/
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
						//��ʾ���������һ���ڵ�
						if (p->next->data >= data)
						{
							//�嵽p����
						}
					}
					else
					{
						//�Ѿ������һ����㣬���������ݱ�dataС����data���뵽β
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
	/*Ĭ��ɾ�����һ��Ԫ��*/
	void deleteElement(SingelLinkList<T> &sll)
	{
		if (&sll == NULL || sll.length <= 0)
		{
			exit(ERROR);
		}
		SLLNode<T> *p = sll.head;
		while (p->next->next)
		{
			//��ָ��ָ������β��
			p = p->next;
		}
		SLLNode<T> *freeP = p->next;
		p->next = p->next->next;
		sll.length--;
		delete freeP;
		freeP = NULL;
	}

	template<typename T>
	/*ɾ����position��λ���ϵ�ֵ����position>0 && position<=length����ͷ�����һ��ֵ��ʼ*/
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
	/*��ȡ��positionλ���ϵ�Ԫ�أ�position>0&&position<=length*/
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
	/*���Ҹ���Ԫ���������г��ֵĵ�һ��λ�ã�position>=1 && position<=length�����û�ҵ����򷵻�-1*/
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
	/*�������*/
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