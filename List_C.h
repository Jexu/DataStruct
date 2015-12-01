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

	/*��ʼ�����Ա�*/
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

	/*��ȡ��Ӧλ���ϵ�Ԫ��ֵ---position>=0&&position<l.length*/
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
	/*����Ԫ��---Ĭ����ӵ���ĩ��*/
	template <typename T>
	void addElement(List<T> &l, T e) {
		if (&l == NULL || l.p == NULL)
		{
			exit(ERROR);
		}
		if (l.length >= l.size)
		{
			//��ʾ���Ա��Ѿ����ˣ������ټ��ˣ���Ҫ���·����С
			T *newP = (T *)realloc(l.p, (LIST_INCREASMENT + l.size)*sizeof(T));
			if (!newP)
			{
				//����ʧ��
				exit(ERROR);
			}
			l.size = l.size + LIST_INCREASMENT;
		}
		*(l.p + l.length) = e;
		l.length++;
	}

	/*����һ�����Ա�������Ԫ��һ����ȫ�ӽ�ȥ--l_child�ӵ�l_parent��*/
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

	/*�Ƴ�һ��λ���ϵ�ֵposition>=0&&position<l.length�������ظ�ֵ*/
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
	/*���Ҹ���Ԫ�������Ա��еĵ�һ�γ��ֵ�λ��,��0��ʼ�������ҵ��ޣ�����-1*/
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

	/*������Ա�������Ԫ��*/
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



