#ifndef _LIST_STACK_C_H
#define _LIST_STACK_C_H
namespace ls_c
{
	/*栈初始化大小*/
#define INIT_STACK_SIZE  100
	/*栈增量大小*/
#define STACK_INCREASMENT  10
	const int ERROR = -1;

	template<typename T>
	struct ListStack
	{
		/*指向栈顶的指针*/
		T *top = NULL;
		/*指向栈底的指针*/
		T *base = NULL;
		/*栈当前大小*/
		int stackSize = 0;
		/*栈中元素个数*/
		int length = 0;
	};

	template<typename T>
	/*初始化栈，分配栈初始大小*/
	void initStack(ListStack<T> &ls)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		ls.base = (T *)malloc(INIT_STACK_SIZE*sizeof(T));
		if (!ls.base)
		{
			exit(ERROR);
		}
		ls.top = ls.base;
		ls.stackSize = INIT_STACK_SIZE;
		ls.length = 0;
	}

	template<typename T>
	/*获取当前栈顶的元素值*/
	T getTop(const ListStack<T> &ls)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		if (ls.base == ls.top || ls.length == 0)
		{
			exit(ERROR);
		}
		return *(ls.top - 1);
	}

	template<typename T>
	/*进栈操作，将元素压入栈顶*/
	void push(ListStack<T> &ls, T e)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		if (ls.top - ls.base >= ls.stackSize)
		{
			T *newBase = (T *)realloc(ls.base, (ls.stackSize + STACK_INCREASMENT)*sizeof(T));
			if (!newBase)
			{
				exit(ERROR);
			}
			ls.base = newBase;
			ls.top = ls.base + ls.stackSize;
			ls.stackSize += STACK_INCREASMENT;
			newBase = NULL;
		}
		*ls.top++ = e;
		ls.length++;
	}

	template<typename T>
	/*出栈操作，将栈顶元素弹出*/
	T pop(ListStack<T> &ls)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		if (ls.top == ls.base || ls.length == 0)
		{
			exit(ERROR);
		}
		T e = *--ls.top;
		ls.length--;
		if (ls.top != ls.base && (ls.stackSize - (ls.top - ls.base + 1)) % STACK_INCREASMENT == 0)
		{
			T *newBase = (T *)realloc(ls.base, (ls.stackSize - STACK_INCREASMENT)*sizeof(T));
			if (!newBase)
			{
				*ls.top++ = e;
				ls.length++;
				exit(ERROR);
			}
			int distance = ls.top - ls.base;
			ls.base = newBase;
			ls.top = ls.base + distance;
			ls.stackSize -= STACK_INCREASMENT;
			newBase = NULL;
		}
		return e;
	}

	template<typename T>
	/*清空栈中所有元素*/
	void clearStack(ListStack<T> &ls)
	{
		if (&ls == NULL)
		{
			exit(ERROR);
		}
		if (ls.top == ls.base || ls.length == 0)
		{
			exit(ERROR);
		}
		if (ls.stackSize > INIT_STACK_SIZE)
		{
			T *newBase = (T *)realloc(ls.base, INIT_STACK_SIZE*(sizeof(T)));
			if (!newBase)
			{
				exit(ERROR);
			}
			ls.base = newBase;
		}
		ls.top = ls.base;
		ls.length = 0;
		ls.stackSize = INIT_STACK_SIZE;
	}
}
#endif