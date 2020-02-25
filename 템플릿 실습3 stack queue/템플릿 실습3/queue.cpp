#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	int inum = 100;

	Queue<int> queue;

	for (int i = 0; i < 100; ++i)
	{
		queue.push(i + 1);
	}

	while (!queue.empty())
	{
		cout << queue.pop() << endl;
	}

	circleQueue<int, 10> queue1;

	for (int i= 0; i < 10; ++i)
	{
		queue1.push(i + 1);
	}

	cout << "3°³ pop" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << queue1.pop() << endl;
	}

	cout << "4°³ push" << endl;
	for (int i = 0; i < 4; ++i)
	{
		queue1.push(i + 1);
	}

	cout << "½Ï´Ù pop" << endl;
	while (!queue1.empty())
	{
		cout << queue1.pop() << endl;
	}
}