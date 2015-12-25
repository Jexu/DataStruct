#ifndef _LINK_STACK_CPP_H
#define _LINK_STACK_CPP_H
namespace linkS_cpp
{
	const int ERROR = -1;
	template<typename T>
	class LinkStack
	{
	public:
		LinkStack();
		LinkStack(LinkStack &ls);
		virtual ~LinkStack();
		T getTop();
		void push(T data);
		T pop();
		void clearStack();
		int getLength();
		LinkStack& operator=(LinkStack &ls);
	private:
		template<typename T>
		/*内部类*/
		class SNode
		{
		public:
			SNode() { this->next = NULL; };
			virtual ~SNode() {};
			T data;
			SNode<T> *next;
		};
		SNode<T> *base = NULL;
		SNode<T> *top = NULL;
		int length = 0;
	};

	template<typename T>
	/*构造函数内初始化链式栈*/
	LinkStack<T>::LinkStack()
	{
		if (!this)
		{
			exit(ERROR);
		}
		SNode<T> *base = new SNode<T>();
		if (!base)
		{
			exit(ERROR);
		}
		base->next = NULL;
		this->base = base;
		this->top = this->base;
		this->length = 0;
		base = NULL;
	}
	template<typename T>
	LinkStack<T>::LinkStack(LinkStack &ls)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->base)
		{
			this->clearStack();
		}
		else
		{
			SNode<T> *base = new SNode<T>();
			if (!base)
			{
				exit(ERROR);
			}
			base->next = NULL;
			this->base = base;
			this->top = this->base;
			this->length = 0;
			base = NULL;
		}
		SNode<T> *ls_top = ls.top;
		while (ls_top->next)
		{
			ls_top = ls_top->next;
			SNode<T> *newBase = new SNode<T>();
			newBase->next = NULL;
			newBase->data = ls_top->data;
			this->base->next = newBase;
			this->base = newBase;
			newBase = NULL;
			this->length++;
		}
		ls_top = NULL;
	}

	template<typename T>
	LinkStack<T>::~LinkStack()
	{
		if (this->base!=NULL)
		{
			this->clearStack();
		delete this->base;
		this->base = this->top = NULL;
		}
	}
	template<typename T>
	/*获取当前栈顶的元素值*/
	T LinkStack<T>::getTop()
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->base == this->top || this->top->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		return this->top->next->data;
	}

	template<typename T>
	/*进栈操作，将元素压入栈顶*/
	void LinkStack<T>::push(T data)
	{
		if (!this || this->base == NULL)
		{
			exit(ERROR);
		}
		SNode<T> *newTop = new SNode<T>();
		if (!newTop)
		{
			exit(ERROR);
		}
		this->top->data = data;
		newTop->next = this->top;
		this->top = newTop;
		this->length++;
		newTop = NULL;
	}
	template<typename T>
	/*出栈操作，将栈顶元素弹出*/
	T LinkStack<T>::pop()
	{
		if (!this || this->base == NULL)
		{
			exit(ERROR);
		}
		if (this->base == this->top || this->top->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		T data = this->top->next->data;
		SNode<T> *freeP = this->top;
		this->top = this->top->next;
		delete freeP;
		freeP = NULL;
		this->length--;
		return data;
	}
	template<typename T>
	/*清空栈中所有元素*/
	void LinkStack<T>::clearStack()
	{
		if (!this || this->base == NULL)
		{
			exit(ERROR);
		}
		if (this->base == this->top || this->top->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		while (this->top->next)
		{
			SNode<T> *freeP = this->top;
			this->top = this->top->next;
			delete freeP;
			freeP = NULL;
		}
		this->length = 0;
	}

	template<typename T>
	/*获取当前栈中元素个数*/
	int LinkStack<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}
	template<typename T>
	/*=操作符重载*/
	LinkStack<T>& LinkStack<T>::operator=(LinkStack &ls)
	{
		if (!this)
		{
			exit(ERROR);
		}
		if (this->base)
		{
			this->clearStack();
		}
		else
		{
			SNode<T> *base = new SNode<T>();
			if (!base)
			{
				exit(ERROR);
			}
			base->next = NULL;
			this->base = base;
			this->top = this->base;
			this->length = 0;
			base = NULL;
		}
		SNode<T> *ls_top = ls.top;
		while (ls_top->next)
		{
			ls_top = ls_top->next;
			SNode<T> *newBase = new SNode<T>();
			newBase->next = NULL;
			newBase->data = ls_top->data;
			this->base->next = newBase;
			this->base = newBase;
			newBase = NULL;
		}
		ls_top = NULL;
		return *this;
	}
}
#endif


