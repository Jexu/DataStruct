#ifndef _LINK_STACK_C_H
#define _LINK_STACK_C_H
namespace linkS_c
{
	const int ERROR = -1;
	template<typename T>
	/*栈中每个元素数据类型---为一个带指针的数据域*/
	struct SNode
	{
		SNode *next = NULL;
		T data;
	};
	template<typename T>
	/*链式栈的数据结构原型*/
	struct LinkStack
	{
		/*指向栈底的指针*/
		SNode<T> *base = NULL;
		/*指向栈顶的指针*/
		SNode<T> *top = NULL;
		/*栈中当前元素个数*/
		int length = 0;
	};
	template<typename T>
	/*初始化栈*/
	void initStack(LinkStack<T> &ls)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		/*存在内存泄露，应该先释放原有资源*/
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
	/*获取当前栈顶的元素值*/
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
	/*进栈操作，将元素压入栈顶*/
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
	/*出栈操作，将栈顶元素弹出*/
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
	/*清空栈中所有元素*/
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
