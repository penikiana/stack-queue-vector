#pragma once

template <typename T>
class stacknode
{
private:
	stacknode()
	{

	}
	~stacknode()
	{

	}

private:
	template <typename T>
	friend class stack;

private:
	T m_data;
	stacknode<T> m_pnext;
};

template <typename T>
class stack
{
public:
	stack()
	{
		m_pbegin = new node;
		m_pend = new node;

		m_pbegin->m_pnext = m_pend;

		m_isize = 0;
	}
	~stack()
	{
		Pnode pnode = m_pbegin;

		while (pnode)
		{
			Pnode pnext = pnode -> m_pnext;
			delete pnode;
			pnode = pnext;
		}
	}

private:
	typedef stacknode<T> node;
	typedef stacknode<T>* Pnode;

private:
	Pnode m_pbegin;
	Pnode m_pend;
	unsigned int m_isize;

public:
	void push(const T& data)
	{
		Pnode pnode = new node;
		pnode->m_data = data;

		Pnode pnext = m_pbegin->m_pnext;
		pnode->m_pnext = pnext;

		m_pbegin->m_pnext = pnode;
		++m_isize;
	}

	T pop()
	{
		if (empty())
			return 0;

		Pnode pnode = m_pbegin->m_pnext;
		Pnode pnext = pnode->m_pnext;

		T data = pnode->m_data;

		delete pnode;

		m_pbegin->m_pnext = pnext;

		--m_isize;

		return data;
	}
	T top()
	{
		if (empty())
			return 0;

		return m_pbegin->m_pnext->m_data;
	}


	bool empty()
	{
		return m_isize == 0;
	}
};

