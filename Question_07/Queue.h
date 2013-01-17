#ifndef _QUEUE_H__
#define _QUEUE_H__

#include <stack>
#include <exception>

using namespace std;

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();

	void appendTail(const T &node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
Queue<T>::Queue()
{
}

template <typename T>
Queue<T>::~Queue()
{
}

template <typename T>
void Queue<T>::appendTail(const T &node)
{
	stack1.push(node);
}

template <typename T>
T Queue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() != 0)
		{
			T &data = stack1.top();
			stack2.push(data);
			stack1.pop();
		}
	}

	if (stack2.size() == 0)
		throw new exception();

	T head = stack2.top();
	stack2.pop();

	return head;
}

#endif
