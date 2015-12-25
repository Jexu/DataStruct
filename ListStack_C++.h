#ifndef _LIST_STACK_CPP_H
#define _LIST_STACK_CPP_H
namespace ls_cpp
{
	const int ERROR = -1;
	template<typename T>
	class ListStack
	{
	public:
		ListStack();
		ListStack(ListStack &ls);
		virtual ~ListStack();
		T getTop();
		void push(T e);
		T pop();
		void clearStack();
		int getLength();
		ListStack& operator=(ListStack &ls);
	private:
		T *base = NULL;
		T *top = NULL;
		int length = 0;
		int stackSize = 0;
		static const int INIT_STACK_SIZE_ = 100;
		static const int STACK_INCREASMENT_ = 10;
	};

	template<typename T>
	/*初始化栈，分配栈初始大小*/
	ListStack<T>::ListStack()
	{
		if (!this)
		{
			exit(ERROR);
		}
		this->base = (T *)malloc(ListStack<T>::INIT_STACK_SIZE_*sizeof(T));
		if (!this->base)
		{
			exit(ERROR);
		}
		this->top = this->base;
		this->stackSize = ListStack<T>::INIT_STACK_SIZE_;
		this->length = 0;
	}
	template<typename T>
	/*拷贝构造函数*/
	ListStack<T>::ListStack(ListStack &ls)
	{
		if (this->base)
		{
			free(this->base);
		}
		this->base = (T *)malloc(ls.stackSize*sizeof(T));
		if (!this->base)
		{
			exit(ERROR);
		}
		this->top = this->base;
		for (int i = 0; i < ls.getLength(); i++)
		{
			*this->top++ = *(ls.base + i);
		}
		this->stackSize = ls.stackSize;
		this->length = ls.getLength();
	}
	template<typename T>
	/*析构函数*/
	ListStack<T>::~ListStack()
	{
		if (this->base)
		{
			free(this->base);
			this->base = this->top = NULL;
		}
	}
	template<typename T>
	/*获取当前栈顶的元素值*/
	T ListStack<T>::getTop()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->base == this->top || this->length == 0)
		{
			exit(ERROR);
		}
		return *(this->top - 1);
	}
	template<typename T>
	/*进栈操作，将元素压入栈顶*/
	void ListStack<T>::push(T e)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->top - this->base >= this->stackSize)
		{
			T *newBase = (T *)realloc(this->base, (this->stackSize + ListStack<T>::STACK_INCREASMENT_)*sizeof(T));
			if (!newBase)
			{
				exit(ERROR);
			}
			this->base = newBase;
			this->top = this->base + this->stackSize;
			this->stackSize += ListStack<T>::STACK_INCREASMENT_;
			newBase = NULL;
		}
		*this->top++ = e;
		this->length++;
	}
	template<typename T>
	/*出栈操作，将栈顶元素弹出*/
	T ListStack<T>::pop()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->top == this->base || this->length == 0)
		{
			exit(ERROR);
		}
		T e = *--this->top;
		this->length--;
		if (this->top != this->base && (this->stackSize - (this->top - this->base + 1)) % ListStack<T>::STACK_INCREASMENT_ == 0)
		{
			T *newBase = (T *)realloc(this->base, (this->stackSize - ListStack<T>::STACK_INCREASMENT_)*sizeof(T));
			if (!newBase)
			{
				*this->top++ = e;
				this->length++;
				exit(ERROR);
			}
			int distance = this->top - this->base;
			this->base = newBase;
			this->top = this->base + distance;
			this->stackSize -= ListStack<T>::STACK_INCREASMENT_;
			newBase = NULL;
		}
		return e;
	}
	template<typename T>
	/*获得当前栈中元素个数*/
	int ListStack<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}
	template<typename T>
	/*清空栈中所有元素*/
	void ListStack<T>::clearStack()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->top == this->base || this->length == 0)
		{
			exit(ERROR);
		}
		if (this->stackSize > ListStack<T>::INIT_STACK_SIZE_)
		{
			T *newBase = (T *)realloc(this->base, INIT_STACK_SIZE_*(sizeof(T)));
			if (!newBase)
			{
				exit(ERROR);
			}
			this->base = newBase;
			newBase = NULL;
		}
		this->top = this->base;
		this->length = 0;
		this->stackSize = ListStack<T>::INIT_STACK_SIZE_;
	}
	template<typename T>
	/*=操作符重载*/
	ListStack<T>& ListStack<T>::operator=(ListStack &ls)
	{
		if (this->base)
		{
			free(this->base);
		}
		this->base = (T *)malloc(ls.stackSize * sizeof(T));
		if (!this->base)
		{
			exit(ERROR);
		}
		this->top = this->base;
		this->stackSize = ls.stackSize;
		this->length = ls.getLength();
		for (int i = 0; i < ls.getLength(); i++)
		{
			*this->top++ = *(ls.base + i);
		}
		return *this;
	}
}
#endif


