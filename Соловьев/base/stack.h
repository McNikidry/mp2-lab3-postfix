#ifndef __STACK_H__
#define __STACK_H__

const int MAX_SIZE_STACK = 100;

template <class ValType>
class TStack
{
	ValType *pMem;
	int count;
	int size;
public:
	TStack(int len);
	~TStack();
	int GetSize() { return size; }
	bool IsEmpty();
	bool IsFull();
	void Push(ValType val); // положить элемент 
	ValType Pop(); //взять элемент
	ValType Top(); // посмотреть элемент
};

template <class ValType>
TStack<ValType>::TStack(int len)
{
	if((len<1) || (len>MAX_SIZE_STACK)) throw (len);
	size = len;
	count = 0;
	pMem=new ValType[size];
}

template<class ValType>
TStack<ValType>::~TStack()
{
	delete[] pMem;
}

template <class ValType>
bool TStack<ValType>::IsEmpty()
{
	return (count==0);
}

template<class ValType>
bool TStack<ValType>::IsFull()
{
	return(count==size);
}

template<class ValType>
void TStack<ValType>::Push(ValType val)
{
	if (IsFull()) throw("stack");
	if(!IsFull())
	pMem[count++]=val;
}

template <class ValType>
ValType TStack<ValType> ::Pop()
{
	if (IsEmpty()) throw("Stack");
	
		return pMem[(count--) - 1];
}
	template <class ValType>
	ValType TStack<ValType>::Top()
	{
		if(IsEmpty()) throw("Stack");
			return pMem[(count)-1];
	}

#endif
