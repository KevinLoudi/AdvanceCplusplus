// TurorialSeries.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;

/*void increase(int *p)
{
	(*p)++;
}

//use reference as much as I can 
void increase2(int & p)
{
	p++;
}*/

class Dummy
{
private:
	int value;
public:
	Dummy()
	{
	  value=0;
	}
	Dummy(int val)
	{
	  value=val;
	}
	Dummy operator+(Dummy a)
	{
		cout<<"Additional occured"<<endl;
		return Dummy(this->value+a.value);
	}
	Dummy operator-(Dummy a)
	{
		cout<<"Additional occured"<<endl;
		return Dummy(this->value-a.value);
	}
	inline int getvalue(){return value;}
	friend ostream &operator<<(ostream &o, Dummy a)
	{
		o<<a.value;
		return o;
	}
	//we need to be able to change it from the function
	friend istream &operator>>(istream &o, Dummy & a)
	{
		o>>a.value;
		return o;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/*Dummy a(5);
	Dummy b=3;
	Dummy c=a+b;
	
	cin>>c;
	cout<<c<<endl;
	//cout<<getvalue()<<endl;
	system("pause");*/
	return 0;
}

