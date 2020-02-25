#include <iostream>
/*
using namespace std;
template<typename T>

void outputtype()
{
	cout << typeid(T).name() << endl;
}

template <typename T>
void outputdata(T data)
{
	cout << "이 아래는 출력, 데이터" << endl;
	cout << typeid(T).name() << endl;
	cout << data << endl;
}

typedef struct _tags
{

}tags, *s;

class ccar
{
public:
	ccar()
	{

	}
	~ccar()
	{

	}
};
enum TEST
{

};

class ctemplate
{
public:
	ctemplate()
	{

	}
	~ctemplate()
	{

	}
public:
	template <class T, class T1>
	void output(T a, T1 b)
	{
		cout << a << endl;
		cout << b << endl;
	}
};

template <typename T>
class ctemplate1
{
public:
	ctemplate1()
	{
		cout << "template1 class type :" <<typeid(T).name()<< endl;
	}
	~ctemplate1()
	{

	}
private:
	T		m_Data;
public:
	void output()
	{
		cout << typeid(T).name() << endl;
		cout << m_Data << endl;
	}
};

int main()
{
	outputtype<int>();
	outputtype<float>();
	outputtype<s>();
	outputtype<ccar>();
	outputtype<TEST>(); 

	outputdata(10);
	outputdata(3.1);
	outputdata(382.383f);
	outputdata('a');
	outputdata("ZZZZZZZZZZZZ");

	ctemplate tem;
	tem.output(10, 3.14f);

	ctemplate1<int> tem1;

	tem1.output();

	ctemplate1<ctemplate> tem2;
	
}
*/