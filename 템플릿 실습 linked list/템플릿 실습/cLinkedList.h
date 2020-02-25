#pragma once

template <typename T>
class cListNode
{
private:
	cListNode():
		m_pNext(NULL),
		m_pPrev(NULL)
	{

	}
	~cListNode()
	{

	}

private:
	template <typename T>
	friend class cLinkedList;
	template <typename T>
	friend class CListIterator;
	template <typename T>
	friend class Creverseiterator;

private:
	T	m_Data;
	cListNode<T>*	m_pNext;
	cListNode<T>*	m_pPrev;
};

template <typename T>
class CListIterator
{
public:
	CListIterator()
	{

	}
	~CListIterator()
	{

	}
private:
	template <typename T>
	friend class cLinkedList;


private:
	typedef cListNode<T>	NODE;
	typedef cListNode<T>*	PNODE;

private:
	PNODE m_pNode;

public:
	bool operator ==(const CListIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}
	bool operator !=(const CListIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++()
	{
		m_pNode = m_pNode->m_pNext;
	}
	void operator --()
	{
		m_pNode = m_pNode->m_pNext;
	}
	T operator *()
	{
		return m_pNode->m_Data;
	}

};

template <typename T>
class Creverseiterator
{
public:
	Creverseiterator()
	{

	}
	~Creverseiterator()
	{

	}

private:
	template <typename T>
	friend class CLinkedList;

private:
	typedef cListNode<T> NODE;
	typedef cListNode<T>* PNODE;

private:
	PNODE m_pNode;

public:
	bool operator ==(const Creverseiterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}
	void operator ++()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	void operator --()
	{
		m_pNode = m_pNode->m_pNext;
	}
	T operator* ()
	{
		return m_pNode->m_Data;
	}
};

template <typename T>
class cLinkedList
{
public:
	cLinkedList()
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}
	~cLinkedList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
		m_iSize = 0;
	}
private:
	typedef cListNode<T>	NODE;
	typedef cListNode<T>*	PNODE;

public:
	typedef CListIterator<T> iterator;
	typedef Creverseiterator<T> reverse_iterator;


private:
	PNODE		m_pBegin;
	PNODE		m_pEnd;
	unsigned int m_iSize;

public:
	void push_back(const T& data)
	{
		PNODE pNode = new NODE;

		pNode->m_Data = data;

		PNODE pPrev = m_pEnd->m_pPrev;

		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_front(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE pFirst = m_pBegin->m_Data_pNext;

		pFirst->m_pPrev = pNode;
		pNode->m_pNext = pFirst;

		pNode->m_pPrev = m_pBegin;
		m_pBegin->m_Data -> pNext = pNode;

		++m_iSize;
	}

	unsigned int size() const
	{
		return m_iSize;
	}

	bool empty() const
	{
		return m_iSize == 0;
	}
	void clear()
	{
		PNODE pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd) {
			PNODE pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_iSize = 0;

	}

	iterator begin()
	{
		iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;
		return iter;
	}

	iterator end()
	{
		iterator iter;
		iter.m_pNode = m_pEnd;
		return iter;
	}

	reverse_iterator rbegin()
	{
		reverse_iterator iter;
		iter.m_pNode = m_pEnd->m_pPrev;
		return iter;
	}
	reverse_iterator rend()
	{
		reverse_iterator iter;
		iter.m_pNode = m_pBegin;
		return iter;
	}

};

