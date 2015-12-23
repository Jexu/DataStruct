#pragma once
#ifndef _SINGEL_LINK_LIST_CPP_H
#define _SINGEL_LINK_LIST_CPP_H
namespace sll_cpp {
	const int ERROR = -1;

	template<typename T>
	/*����������*/
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
		/*������������*/
		class LNODE
		{
		public:
			/*�޲ι��캯��*/
			LNODE()
			{
				this->next = NULL;
			};
			/*�������캯��*/
			LNODE(LNODE &ln)
			{
				if (this->next)
				{
					delete this->next;
				}
				this->next = next;
				this->data = ln.data;
			};
			/*��������*/
			~LNODE() {};
			/*�������*/
			T data;
			/*ָ����һ������ָ��*/
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
	/*Ĭ�ϲ嵽ĩβ,���������ͷ����*/
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
	/*Ĭ��ɾ�����һ��Ԫ��*/
	void SingelLinkList<T>::deleteElement()
	{
		if (!this || this->length <= 0)
		{
			exit(ERROR);
		}
		LNODE *p = this->head;
		while (p->next->next)
		{
			//��ָ��ָ������β��
			p = p->next;
		}
		LNODE *freeP = p->next;
		p->next = p->next->next;
		this->length--;
		delete freeP;
		freeP = NULL;
	}
	template<typename T>
	/*ɾ����position��λ���ϵ�ֵ����position>0 && position<=length����ͷ�����һ��ֵ��ʼ*/
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
	/*��ȡ��positionλ���ϵ�Ԫ�أ�position>0&&position<=length*/
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
	/*���Ҹ���Ԫ���������е�һ�γ��ֵ�λ�ã�position>=1 && position<=length�����û�ҵ����򷵻�-1*/
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
	/*�������*/
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
	/*���������*/
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