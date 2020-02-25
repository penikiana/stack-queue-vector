#pragma once

template <typename T>
class QueueNode
{
private:
	QueueNode():
		m_pnext(NULL),
		m_pprev(NULL)
	{
	

	}
	~QueueNode()
	{

	}
private:
	template <typename T>
	friend class Queue;

private: 
	T m_data;
	QueueNode<T>* m_pnext;
	QueueNode<T>* m_pprev;
};


template <typename T>
class Queue
{
public:

	Queue()
	{
		m_pbegin = new NODE;
		m_pend = new NODE;

		m_pbegin->m_pnext = m_pend;
		m_pend->m_pprev = m_pbegin;

		m_isize = 0;
	}
	~Queue()
	{

	}

private:
	typedef QueueNode<T> NODE;
	typedef QueueNode<T>* PNODE;

private:
	PNODE m_pbegin;
	PNODE m_pend;
	unsigned int m_isize;

public:
	void push(const T& data)
	{
		PNODE pnode = new NODE;

		pnode->m_data = data;

		PNODE pprev = m_pend->m_pprev;

		pprev->m_pnext = pnode;
		pnode->m_pprev = pprev;

		pnode->m_pnext = m_pend;
		m_pend->m_pprev = pnode;

		++m_isize;
	}

	T pop()
	{
		if (empty())
			return 0;

		PNODE pnode = m_pbegin->m_pnext;

		T data = pnode->m_data;

		m_pbegin->m_pnext = pnode->m_pnext;
		pnode->m_pnext -> m_pprev = m_pbegin;

		delete pnode;
		--m_isize;

		return data;
	}

	bool empty()
	{
		return m_isize == 0;
	}
};

template <typename T, int SIZE=100>
class circleQueue
{
public:
	circleQueue()
	{
		m_isize = 0;
		m_ihead = 0;
		m_itail = 0;
	}
	~circleQueue()
	{

	}

private: 
	T m_Data[SIZE+1];
	unsigned int m_isize;
	unsigned int m_ihead;
	unsigned int m_itail;

public:
	void push(const T& data)
	{
		if (full())
			return;

		int idx = (m_itail + 1) %(SIZE+1);

		m_Data[idx] = data;

		m_itail = idx;

		++m_isize;
	}

	T pop()
	{
		if (empty())
			return 0;

		int idx = (m_ihead + 1) % (SIZE + 1);

		T data = m_Data[idx];

		m_ihead = idx;
		--m_isize;

		return data;
	}

	bool full()
	{
		return m_isize;
	}

	bool empty()
	{
		return m_isize = 0;
	}
};

