#ifndef _LIST_CPP_H
#define _LIST_CPP_H
#include<stdarg.h>
namespace list_cpp {
	const int ERROR = -1;
	template <typename T>
	class List
	{
	public:
		List();
		List(List &l);
		List(int n, T start, ...);
		T getElement(long position);
		void addElement(T e);
		void addAll(const List<T> &l);
		T removeElement(long position);
		int findElement(T e);
		void clearList();
		int getLength();
		virtual ~List();
	private:
		T *p = NULL;
		int length = 0;
		int size = 0;
		static const int LIST_INIT_SIZE_;
		static const int LIST_INCREASMENT_;
	};

	/*����ĸ�Դ���ڱ���������ģ��(template)�ı��봦������У�

������������(�������ô��)��

1��ģ�庯��testFunc�ڱ���(compile)�ڼ䲢δ���ɾ�������ƴ��룬

	��main������Ҳû��Ƕ����������Ĵ��룬����ֻ�ǰ�����һ��

	call testFunc֮���(�Ժ�����)

2������׶Σ���main�����з�����testFunc�����ã�����main.obj��û����ص�

	 ��ִ�д��루��������Ϊ�ú����ڱ𴦶��壬�����Ϊʲô��Ҫ����Ҳ����

	 LINK�ˣ���main����Ȼ���õ�testFunc����ֻ�ṩ��һ��call�����ַ��û��

	 ʵ�ʵ�ִ�д��룩

3�����ӽ׶Σ�������ģ��(�����ڼ����ɵĺܶ�*.obj�ļ�)��֯����

	 �����˵���ǣ���LINK��ʱ���testFunc��Ƕ�롱������������һ���ӹ��̣�

	 ��main�дӵ��ô�jump�����Ｔ�ɣ�ִ�������������ģ�飬�ӡ��жϵ㡱

	 ����ִ�к�����䣩

4��ģ���ڱ����ڼ��ǲ����ɾ������ģ��������ػ������ã�����������

	 testFunc(double d)�����ｫ����ʵ����Ϊdouble

��ϸ����

���ʾ����MyTemplate.h��������ģ�庯�����Ǿ���ʵ�ַ�����MyTemplate.cpp

�ļ��У�Ȼ�������������õ�testFunc��һ���ػ�ʵ������ΪMyTemplate��Main

�ֱ����ΪMyTemplate.obj��Main.obj

(����������������ÿ��ܻ��в�ͬ�����ǰ���Ĭ���������ɵ��м��ļ�����)

�ڱ���MyTemplate�Ĺ����У�û���ҵ��κ��ػ�ʵ����ͷ�ļ�Ϊģ��������

Դ�ļ���Ϊģ��ʵ�֣�����˲������κο�ִ��ʵ������

��ģ��Main�����õ�testFunc������main.cpp��û�����ʵ�ִ���

(#include "MyTemplate.h"ֻ�ǰ���������)

���ֻ�Ǹ�����call testFunc�ġ������������Ǿ���ִ�д��룬����˵��ϣ����

���ӽ׶Σ��ڱ��ģ�����ҵ�testFunc�Ķ���

������LINK�׶���Ҫ����testFunc��ʵ�ֶ��壬���ҵ��ǣ��Ҳ����ˣ����ǳ���

���Ӵ���

error LNK2019: �޷��������ⲿ���� "void __cdecl testFunc<double>(double &)"

 (??$testFunc@N@@YAXAAN@Z)���÷����ں��� _main �б�����

��ô����ν����������أ�

���������¼��ַ�����

1����һ���ļ������ģ���������ʵ��

2����ģ��ͷ�ļ�ĩβ���ʵ���ļ��İ��� #include "MyTemnplate.cpp"

3���ڵ��÷�(main.cpp��)����ʵ���ļ� #include "MyTemnplate.cpp"



�ڶ��ַ�ʽ�������һ�ַ�ʽ��࣬ʵ���Ͼ���һ��������

�����ַ������ܻ���ɶ��⿪����������ģ�鶼���������ģ���ĳ���ػ�ʵ����

���Σ�

��һ����˵���ֿ�������ʲô���������Ҫ����ϸ���ô����õ�һ�ַ�ʽ��*/



/*һ�仰�����ڶ���ĸ���ģ���࣬��������Ͷ��������ͬһ���ļ�����ɣ����ܷ��������ļ���*/

	template <typename T>
	List<T>::List()
	{
		this->p = (T *)malloc(List::LIST_INIT_SIZE_*sizeof(T));
		if (!this->p)
		{
			exit(ERROR);
		}
		this->length = 0;
		this->size = List::LIST_INIT_SIZE_;
	}
	template <typename T>
	List<T>::List(List &l)
	{
		if (this->p)
		{
			free(this->p);
		}
		this->p = l.p;
		this->length = l.length;
		this->size = l.size;
	}
	template<typename T>
	/*�䳤�����б�Ĺ��캯����nΪ�䳤����������start�Լ�...Ϊ�䳤����������Щ����������list��Ԫ��*/
	List<T>::List(int n, T start, ...)
	{
		this->p = (T *)malloc(List::LIST_INIT_SIZE_*sizeof(T));
		if (!this->p)
		{
			exit(ERROR);
		}
		this->length = 0;
		this->size = List::LIST_INIT_SIZE_;
		va_list valuesP;
		T value = start;
		va_start(valuesP, start);
		do
		{
			this->addElement(value);
			value = va_arg(valuesP, T);
		} while (--n);
	}
	template <typename T>
	List<T>::~List()
	{
		if (this->p)
		{
			free(this->p);
		}
	}
	/*���Ա��ʼ��С*/
	template <typename T>
	const int List<T>::LIST_INIT_SIZE_ = 10;

	/*���Ա��ط���ʱ��������С*/
	template <typename T>
	const int List<T>::LIST_INCREASMENT_ = 10;

	template <typename T>
	/*��ȡ��Ӧλ���ϵ�Ԫ��ֵ��position>=0&&position<length*/
	T List<T>::getElement(long position) {
		if (!this->p)
		{
			exit(ERROR);
		}
		if (position < 0 || position >= this->length)
		{
			exit(ERROR);
		}
		return *(this->p + position);
	}
	template <typename T>
	/*�����Ա�ĩβ���һ��Ԫ��*/
	void List<T>::addElement(T e) {
		if (this->p == NULL)
		{
			exit(ERROR);
		}
		if (this->length >= this->size)
		{
			//��ʾ���Ա��Ѿ����ˣ������ټ��ˣ���Ҫ���·����С
			T *newP = (T *)realloc(this->p, (List::LIST_INCREASMENT_ + this->size)*sizeof(T));
			if (!newP)
			{
				//����ʧ��
				exit(ERROR);
			}
			this->size += List::LIST_INCREASMENT_;
		}
		*(this->p + this->length) = e;
		this->length++;
	}
	template <typename T>
	/*����һ�����Ա��е�����Ԫ��ȫ���ӵ���ǰ���Ա���*/
	void List<T>::addAll(const List<T> &l) {
		if (this->p == NULL || &l == NULL || l.p == NULL)
		{
			exit(ERROR);
		}
		for (int i = 0; i < l.length; i++)
		{
			addElement(l.getElement(i));
		}
	}
	template <typename T>
	/*�Ƴ���Ӧλ���ϵ�Ԫ��ֵ��position>=0&&position<length*/
	T List<T>::removeElement(long position) {
		if (this->p == NULL)
		{
			exit(ERROR);
		}
		if (position < 0 || position >= this->length)
		{
			exit(ERROR);
		}
		T e = *(this->p + position);
		for (int i = position + 1; i < this->length; i++)
		{
			*(this->p + i - 1) = *(this->p + i);
		}
		this->length--;
		if ((this->size - this->length) % List::LIST_INCREASMENT_ == 0 && this->size > List::LIST_INIT_SIZE_)
		{
			T *newP = (T *)realloc(this->p, (this->size - List::LIST_INCREASMENT_)*sizeof(T));
			if (!newP)
			{
				exit(ERROR);
			}
			this->p = newP;
			this->size -= List::LIST_INCREASMENT_;
			newP = NULL;
		}
		return e;
	}
	template<typename T>
	/*���Ҹ���Ԫ�������Ա��еĵ�һ�γ��ֵ�λ�ã���0��ʼ�������ҵ��ޣ�����-1*/
	int List<T>::findElement(T e)
	{
		if (this->p == NULL)
		{
			exit(ERROR);
		}
		for (int i = 0; i < this->length; i++)
		{
			if (e == *(this->p + i))
			{
				return i;
			}
		}
		return -1;
	}
	template <typename T>
	/*��յ�ǰ���Ա�*/
	void List<T>::clearList() {
		if (this->p == NULL)
		{
			exit(ERROR);
		}
		if (this->length == 0)
		{
			return;
		}
		T *newP = (T *)malloc(List::LIST_INIT_SIZE_*sizeof(T));
		if (!newP)
		{
			exit(ERROR);
		}
		free(this->p);
		this->p = newP;
		this->size = List::LIST_INIT_SIZE_;
		this->length = 0;
		newP = NULL;
	}
	template <typename T>
	/*��ȡ��ǰ���Ա���Ԫ�ظ���*/
	int List<T>::getLength() {
		if (this->p == NULL)
		{
			exit(ERROR);
		}
		return this->length;
	}
}
#endif