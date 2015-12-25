#ifndef _LINK_QUEUE_CPP_H
#define _LINK_QUEUE_CPP_H
namespace linkQ_cpp
{
	const int ERROR = -1;
	template<typename T>
	class LinkQueue
	{
	public:
		LinkQueue();
		LinkQueue(LinkQueue &lq);
		virtual ~LinkQueue();
		T getHead();
		void inQueue(T data);
		T outQueue();
		void clearQueue();
		int getLength();
		LinkQueue& operator=(LinkQueue &lq);
	private:
		template<typename T>
		/*内部类---队列中每个元素类型类*/
		class SNode
		{
		public:
			SNode() { this->next = NULL; };
			virtual ~SNode() {};
			T data;
			SNode<T> *next;
		};
		SNode<T> *rear;
		SNode<T> *front;
		int length = 0;
	};

	template<typename T>
	/*构造函数内初始化链式队列*/
	LinkQueue<T>::LinkQueue()
	{
		if (!this)
		{
			exit(ERROR);
		}
		SNode<T> *rear = new SNode<T>();
		if (!rear)
		{
			exit(ERROR);
		}
		rear->next = NULL;
		this->rear = rear;
		this->front = this->rear;
		this->length = 0;
		rear = NULL;
	}
	template<typename T>
	/*拷贝构造函数*/
	LinkQueue<T>::LinkQueue(LinkQueue &lq)
	{
		if (!this || lq.rear == NULL || lq.front == NULL)
		{
			exit(ERROR);
		}
		if (this->rear != this->front)
		{
			this->clearQueue();
			delete this->front;
		}
		SNode<T> *rear = new SNode<T>();
		if (!rear)
		{
			exit(ERROR);
		}
		rear->next = NULL;
		this->rear = rear;
		this->front = this->rear;
		rear = NULL;
		SNode<T> *lq_front = lq.front;
		while (lq_front->next)
		{
			lq_front = lq_front->next;
			SNode<T> *newRear = new SNode<T>();
			newRear->data = lq_front->data;
			newRear->next = NULL;
			this->rear->next = newRear;
			this->rear = newRear;
			newRear = NULL;
		}
		this->length = lq.getLength();
		lq_front = NULL;
	}
	template<typename T>
	/*析构函数*/
	LinkQueue<T>::~LinkQueue()
	{
		if (this->rear != NULL && this->front != NULL)
		{
			this->clearQueue();
			delete this->front;
			this->front = this->rear = NULL;
		}
	}
	template<typename T>
	/*获取当前队列顶的元素值*/
	T LinkQueue<T>::getHead()
	{
		if (!this || this->rear == NULL || this->front == NULL)
		{
			exit(ERROR);
		}
		if (this->rear == this->front || this->front->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		return this->front->next->data;
	}

	template<typename T>
	/*进队操作，将元素压入队尾*/
	void LinkQueue<T>::inQueue(T data)
	{
		if (!this || this->rear == NULL || this->front == NULL)
		{
			exit(ERROR);
		}
		SNode<T> *newRear = new SNode<T>();
		if (!newRear)
		{
			exit(ERROR);
		}
		newRear->data = data;
		newRear->next = NULL;
		this->rear->next = newRear;
		this->rear = newRear;
		this->length++;
		newRear = NULL;
	}
	template<typename T>
	/*出队操作，将队列顶元素弹出*/
	T LinkQueue<T>::outQueue()
	{
		if (!this || this->rear == NULL || this->front == NULL)
		{
			exit(ERROR);
		}
		if (this->rear == this->front || this->front->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		T data = this->front->next->data;
		SNode<T> *freeP = this->front;
		this->front = this->front->next;
		delete freeP;
		freeP = NULL;
		this->length--;
		return data;
	}

	template<typename T>
	/*清空队列中所有元素*/
	void LinkQueue<T>::clearQueue()
	{
		if (!this || this->rear == NULL || this->front == NULL)
		{
			exit(ERROR);
		}
		if (this->rear == this->front || this->front->next == NULL || this->length == 0)
		{
			exit(ERROR);
		}
		while (this->front->next)
		{
			SNode<T> *freeP = this->front;
			this->front = this->front->next;
			delete freeP;
			freeP = NULL;
		}
		this->length = 0;
	}

	template<typename T>
	/*获取当前队列中元素个数*/
	int LinkQueue<T>::getLength()
	{
		if (!this || this->rear == NULL || this->front == NULL)
		{
			exit(ERROR);
		}
		return this->length;
	}
	template<typename T>
	/*=操作符重载*/
	LinkQueue<T>& LinkQueue<T>::operator=(LinkQueue &lq)
	{
		if (!this || lq.rear == NULL || lq.front == NULL)
		{
			exit(ERROR);
		}
		if (this->rear != this->front)
		{
			this->clearQueue();
			delete this->front;
		}
		SNode<T> *rear = new SNode<T>();
		if (!rear)
		{
			exit(ERROR);
		}
		rear->next = NULL;
		this->rear = rear;
		this->front = this->rear;
		rear = NULL;
		SNode<T> *lq_front = lq.front;
		while (lq_front->next)
		{
			lq_front = lq_front->next;
			SNode<T> *newRear = new SNode<T>();
			newRear->data = lq_front->data;
			newRear->next = NULL;
			this->rear->next = newRear;
			this->rear = newRear;
			newRear = NULL;
		}
		this->length = lq.getLength();
		lq_front = NULL;
		return *this;
	}
}
#endif


