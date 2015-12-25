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
		/*�ڲ���*/
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
	/*���캯���ڳ�ʼ����ʽջ*/
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
	/*��ȡ��ǰջ����Ԫ��ֵ*/
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
	/*��ջ��������Ԫ��ѹ��ջ��*/
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
	/*��ջ��������ջ��Ԫ�ص���*/
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
	/*���ջ������Ԫ��*/
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
	/*��ȡ��ǰջ��Ԫ�ظ���*/
	int LinkStack<T>::getLength()
	{
		if (!this)
		{
			exit(ERROR);
		}
		return this->length;
	}
	template<typename T>
	/*=����������*/
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


