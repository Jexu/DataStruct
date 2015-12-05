#pragma once
#include<iostream>
#include<malloc.h>
using namespace std;

namespace ls_c
{
	const int ERROR = -1;
	/*ջ��ʼ����С*/
#define INIT_STACK_SIZE  100
	/*ջ������С*/
#define STACK_INCREASMENT  10
	
	template<typename T>
	struct ListStack
	{
		/*ָ��ջ����ָ��*/
		T *top = NULL;
		/*ָ��ջ�׵�ָ��*/
		T *base = NULL;
		/*ջ��ǰ��С*/
		int stackSize = 0;
		/*ջ��Ԫ�ظ���*/
		int length = 0;
	};

	template<typename T>
	/*��ʼ��ջ������ջ��ʼ��С*/
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
	/*��ȡ��ǰջ����Ԫ��ֵ*/
	T getTop(ListStack<T> ls)
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
	/*��ջ��������Ԫ��ѹ��ջ��*/
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
		}
		*ls.top++ = e;
		ls.length++;
	}

	template<typename T>
	/*��ջ��������ջ��Ԫ�ص���*/
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
		if (ls.top != ls.base && (ls.stackSize - (ls.top - ls.base + 1))%STACK_INCREASMENT == 0)
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
		}
		return e;
	}

	template<typename T>
	/*���ջ������Ԫ��*/
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
		ls.top = ls.base;
		ls.length = 0;
		ls.stackSize = INIT_STACK_SIZE;
	}
}