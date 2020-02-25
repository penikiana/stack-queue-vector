#include <iostream>
#include "vector.h"
#include "stack.h"
using namespace std;

int main()
{/*
	vector<int> vecint;

	vecint.reserve(100);

	for (int i = 0; i < 100; ++i)
	{
		vecint.push_back(i + 1);
	}

	for (int i = 0; i < vecint.size(); ++i)
	{
		cout << vecint[i] << endl;
	}
	*/
	stack<int> stackint;

	for (int i = 0; i < 100; ++i)
	{
		stackint.push(i + 1);
	}

	while (!stackint.empty())
	{
		cout << stackint.pop() << endl;
	}

	return 0;
}