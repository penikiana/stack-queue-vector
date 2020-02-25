#include <iostream>
#include <string>
#include "cLinkedList.h"

using namespace std;

int main()
{
	cLinkedList<int>	listInt;
	cLinkedList<float>	listFloat;

	for (int i = 0; i < 102; ++i) {
		listInt.push_back(i + 1);
	}

	cout << listInt.size() << endl;

	cLinkedList<int>::iterator iter;
	for (iter = listInt.begin(); iter != listInt.end(); ++iter)
	{
		cout<< *iter << endl;
	}

	cLinkedList<int>::reverse_iterator riter;

	for (riter = listInt.rbegin(); riter != listInt.rend(); ++riter) {
		cout << *riter << endl;
	}
}