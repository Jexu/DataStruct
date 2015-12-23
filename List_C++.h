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

	/*问题的根源在于编译器对于模板(template)的编译处理过程中，

大致是这样的(果真如此么？)：

1、模板函数testFunc在编译(compile)期间并未生成具体二进制代码，

	在main函数中也没有嵌入这个函数的代码，可能只是包含了一句

	call testFunc之类的(稍后详述)

2、编译阶段，在main函数中发现了testFunc的引用，但是main.obj中没有相关的

	 可执行代码（编译器认为该函数在别处定义，这就是为什么需要链接也就是

	 LINK了，在main中虽然引用到testFunc但是只提供了一个call虚拟地址而没有

	 实际的执行代码）

3、链接阶段，将各个模块(编译期间生成的很多*.obj文件)组织起来

	 形象的说就是，在LINK的时候把testFunc“嵌入”进来，就像是一个子过程，

	 在main中从调用处jump到这里即可，执行完毕再跳出子模块，从“中断点”

	 继续执行后续语句）

4、模板在编译期间是不生成具体代码的，除非有特化的引用，比如上述的

	 testFunc(double d)，这里将参数实例化为double

详细分析

这个示例中MyTemplate.h中声明了模板函数但是具体实现放在了MyTemplate.cpp

文件中，然后主函数中引用到testFunc的一个特化实例，因为MyTemplate和Main

分别编译为MyTemplate.obj和Main.obj

(根据你编译器的设置可能会有不同，这是按照默认设置生成的中间文件名称)

在编译MyTemplate的过程中，没有找到任何特化实例（头文件为模板声明，

源文件亦为模板实现），因此不生成任何可执行实例代码

主模块Main中引用到testFunc，并且main.cpp中没有相关实现代码

(#include "MyTemplate.h"只是包含了声明)

因此只是给出了call testFunc的“字样”而不是具体执行代码，就是说寄希望于

链接阶段，在别的模块中找到testFunc的定义

于是在LINK阶段需要查找testFunc的实现定义，不幸的是，找不到了，于是出现

链接错误

error LNK2019: 无法解析的外部符号 "void __cdecl testFunc<double>(double &)"

 (??$testFunc@N@@YAXAAN@Z)，该符号在函数 _main 中被引用

那么，如何解决这个问题呢？

至少有以下几种方法：

1、在一个文件中完成模板的声明及实现

2、在模板头文件末尾添加实现文件的包含 #include "MyTemnplate.cpp"

3、在调用方(main.cpp中)包含实现文件 #include "MyTemnplate.cpp"



第二种方式还不如第一种方式简洁，实际上就是一个东西，

第三种方法可能会造成而外开销（比如多个模块都调用了这个模板的某个特化实例的

情形）

但一般来说这种开销不算什么，除非你的要求很严格，那么请采用第一种方式吧*/



/*一句话，对于定义的各种模板类，类的声明和定义必须在同一个文件中完成，不能分在两个文件中*/

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
	/*变长参数列表的构造函数，n为变长参数个数，start以及...为变长参数，用这些参数来生成list中元素*/
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
	/*线性表初始大小*/
	template <typename T>
	const int List<T>::LIST_INIT_SIZE_ = 10;

	/*线性表重分配时候增量大小*/
	template <typename T>
	const int List<T>::LIST_INCREASMENT_ = 10;

	template <typename T>
	/*获取对应位置上的元素值，position>=0&&position<length*/
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
	/*在线性表末尾添加一个元素*/
	void List<T>::addElement(T e) {
		if (this->p == NULL)
		{
			exit(ERROR);
		}
		if (this->length >= this->size)
		{
			//表示线性表已经满了，不能再加了，需要重新分配大小
			T *newP = (T *)realloc(this->p, (List::LIST_INCREASMENT_ + this->size)*sizeof(T));
			if (!newP)
			{
				//分配失败
				exit(ERROR);
			}
			this->size += List::LIST_INCREASMENT_;
		}
		*(this->p + this->length) = e;
		this->length++;
	}
	template <typename T>
	/*将另一个线性表中的所有元素全部加到当前线性表中*/
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
	/*移除对应位置上的元素值，position>=0&&position<length*/
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
	/*查找给定元素在线性表中的第一次出现的位置，从0开始，若查找到无，返回-1*/
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
	/*清空当前线性表*/
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
	/*获取当前线性表中元素个数*/
	int List<T>::getLength() {
		if (this->p == NULL)
		{
			exit(ERROR);
		}
		return this->length;
	}
}
#endif