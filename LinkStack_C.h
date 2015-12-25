#ifndef _LINK_STACK_C_H
#define _LINK_STACK_C_H
namespace linkS_c
{
	const int ERROR = -1;
	template<typename T>
	/*ջ��ÿ��Ԫ����������---Ϊһ����ָ���������*/
	struct SNode
	{
		SNode *next = NULL;
		T data;
	};
	template<typename T>
	/*��ʽջ�����ݽṹԭ��*/
	struct LinkStack
	{
		/*ָ��ջ�׵�ָ��*/
		SNode<T> *base = NULL;
		/*ָ��ջ����ָ��*/
		SNode<T> *top = NULL;
		/*ջ�е�ǰԪ�ظ���*/
		int length = 0;
	};
	template<typename T>
	/*��ʼ��ջ*/
	void initStack(LinkStack<T> &ls)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		/*�����ڴ�й¶��Ӧ�����ͷ�ԭ����Դ*/
		SNode<T> *base = new SNode<T>;
		if (!base)
		{
			exit(ERROR);
		}
		base->next = NULL;
		ls.base = base;
		ls.top = ls.base;
		ls.length = 0;
		base = NULL;
	}
	template<typename T>
	/*��ȡ��ǰջ����Ԫ��ֵ*/
	T getTop(const LinkStack<T> &ls)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		if (ls.base == ls.top || ls.top->next == NULL || ls.length == 0)
		{
			exit(ERROR);
		}
		return ls.top->next->data;
	}
	template<typename T>
	/*��ջ��������Ԫ��ѹ��ջ��*/
	void push(LinkStack<T> &ls, T data)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		SNode<T> *newTop = new SNode<T>;
		if (!newTop)
		{
			exit(ERROR);
		}
		ls.top->data = data;
		newTop->next = ls.top;
		ls.top = newTop;
		ls.length++;
		newTop = NULL;
	}
	template<typename T>
	/*��ջ��������ջ��Ԫ�ص���*/
	T pop(LinkStack<T> &ls)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		if (ls.base == ls.top || ls.top->next == NULL || ls.length == 0)
		{
			exit(ERROR);
		}
		T data = ls.top->next->data;
		SNode<T> *freeP = ls.top;
		ls.top = ls.top->next;
		delete freeP;
		freeP = NULL;
		ls.length--;
		return data;
	}
	template<typename T>
	/*���ջ������Ԫ��*/
	void clearStack(LinkStack<T> &ls)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		if (ls.base == ls.top || ls.top->next == NULL || ls.length == 0)
		{
			exit(ERROR);
		}
		while (ls.top->next)
		{
			SNode<T> *freeP = ls.top;
			ls.top = ls.top->next;
			delete freeP;
			freeP = NULL;
		}
		ls.length = 0;
	}
}
#endif
