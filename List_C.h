#include<malloc.h>

namespace list_c
{
	const int ERROR = -1;
	template <typename T>
	struct List {
#define LIST_INIT_SIZE  100
#define LIST_INCREASMENT  10
		T *p = NULL;
		int length = 0;
		int size = 0;
	};

	/*初始化线性表*/
	template <typename T>
	void initList(List<T> &l) {
		l.p = (T *)malloc(LIST_INIT_SIZE*sizeof(T));
		if (!l.p)
		{
			exit(ERROR);
		}
		l.length = 0;
		l.size = LIST_INIT_SIZE;
	}

	/*获取对应位置上的元素值---position>=0&&position<l.length*/
	template <typename T>
	T getElement(List<T> l, long position) {
		if (&l == NULL || l.p == NULL)
		{
			exit(ERROR);
		}
		if (position <0 || position >= l.length)
		{
			exit(ERROR);
		}
		return *(l.p + position);
	}
	/*加入元素---默认添加到最末端*/
	template <typename T>
	void addElement(List<T> &l, T e) {
		if (&l == NULL || l.p == NULL)
		{
			exit(ERROR);
		}
		if (l.length >= l.size)
		{
			//表示线性表已经满了，不能再加了，需要重新分配大小
			T *newP = (T *)realloc(l.p, (LIST_INCREASMENT + l.size)*sizeof(T));
			if (!newP)
			{
				//分配失败
				exit(ERROR);
			}
			l.size = l.size + LIST_INCREASMENT;
		}
		*(l.p + l.length) = e;
		l.length++;
	}

	/*将另一个线性表中所有元素一次性全加进去--l_child加到l_parent中*/
	template <typename T>
	void addAll(List<T> &l_parent, List<T> l_child) {
		if (&l_parent == NULL || l_parent.p == NULL || &l_child == NULL || l_child.p == NULL)
		{
			exit(ERROR);
		}
		for (int i = 0; i < l_child.length; i++)
		{
			addElement(l_parent, getElement(l_child, i));
		}
	}

	/*移除一个位置上的值position>=0&&position<l.length，并返回该值*/
	template <typename T>
	T removeElement(List<T> &l, long position) {
		if (&l == NULL || l.p == NULL)
		{
			exit(ERROR);
		}
		if (position <0 || position >= l.length)
		{
			exit(ERROR);
		}
		T e = *(l.p + position);
		for (int i = position + 1; i < l.length; i++)
		{
			*(l.p + i - 1) = *(l.p + i);
		}
		l.length--;
		if ((l.size - l.length) % LIST_INCREASMENT == 0 && l.size>LIST_INIT_SIZE)
		{
			T *newP = (T *)realloc(l.p, (l.size - LIST_INCREASMENT)*sizeof(T));
			if (!newP)
			{
				exit(ERROR);
			}
			l.p = newP;
			l.size -= LIST_INCREASMENT;
		}

		return e;
	}

	template<typename T>
	/*查找给定元素在线性表中的第一次出现的位置,从0开始，若查找到无，返回-1*/
	int findElement(List<T> l, T e)
	{
		if (&l == NULL || l.p == NULL)
		{
			exit(ERROR);
		}
		for (int i = 0; i < l.length; i++)
		{
			if (e == *(l.p + i))
			{
				return i;
			}

		}
		return -1;
	}

	/*清除线性表中所有元素*/
	template <typename T>
	void clearList(List<T> &l) {
		if (&l == NULL || l.p == NULL)
		{
			exit(ERROR);
		}
		if (l.length == 0)
		{
			return;
		}
		T *newP = (T *)malloc(LIST_INIT_SIZE*sizeof(T));
		if (!newP)
		{
			exit(ERROR);
		}
		l.p = newP;
		l.size = LIST_INIT_SIZE;
		l.length = 0;
	}
}



