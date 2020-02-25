#pragma once

template <typename T>
class vectornode
{
private:
	vectornode()
	{

	}
	~vectornode()
	{

	}
private:
	template <typename T>
	friend class vector;

private:
	T	m_data;
	int m_iindex;
};
template <typename T>
class vector
{
public:
	vector()
	{
		m_isize = 0;
		m_icapasity = 2;

		m_parray = new node[m_icapasity + 2];
	}

	vector(int isize)
	{
		m_parray = new node[isize + 2];
		m_icapasity = isize;
		m_isize = 0;
	}

	~vector()
	{
		delete[] m_parray;
	}

private:
	typedef vectornode<T> node;
	typedef vectornode<T>* pnode;

private:
	pnode m_parray;
	unsigned int m_isize;
	unsigned int m_icapasity;

public:
	void push_back(const T& data)
	{
		if (full())
			resize(m_isize * 2);

		m_parray[m_isize + 1].m_data = data;
		m_parray[m_isize + 1].m_iindex = m_isize;
		++m_isize;
	}

	void resize(int isize)
	{
		pnode parray = new node[isize + 2];

		memcpy(parray+1, m_parray+1, sizeof(node) * m_isize);

		delete[] m_parray;

		m_parray = parray;

		m_icapasity = isize;
	}


	bool full()
	{
		return m_isize == m_icapasity;
	}

	bool empty()
	{
		return m_isize == 0;
	}
	unsigned int size() const
	{
		return m_isize;
	}
	unsigned int capasity() const
	{
		return m_icapasity;
	}

	T operator [](int idx)
	{
		return m_parray[idx + 1].m_data;
	}
	
	void reserve(int isize)
	{
		delete[] m_parray;
		m_parray = new node[isize + 2];

		m_icapasity = isize;
		m_isize = 0;
	}
};
	
