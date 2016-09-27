// CplusplusMethod.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Tdate.h"
#include <iostream>
using namespace std;

void sfunc(Tdate *p)
{
	if (p->isLeapyear())
	{
		cout<<"is a leap year."<<endl;
	}
	else
	{
		cout<<"is not a leap year."<<endl;
	}
}

//overide
void sfunc(Tdate &p)
{
	if (p.isLeapyear())
	{
		cout<<"is a leap year."<<endl;
	}
	else
	{
		cout<<"is not a leap year."<<endl;
	}
}

int Tdate::yearcount=0;
int _tmain(int argc, _TCHAR* argv[])
{
	//Implicit call construct
	/*Tdate d, *p;
	p=&d;
	d.set(2016,9,27);
	d.print();
	cout<<"address of d: "<<&d<<endl;
	p->print();
	cout<<"address of p: "<<p<<endl;
	if (p->isLeapyear())
	{
		cout<<"is a leap year."<<endl;
	}
	else
	{
		cout<<"is not a leap year."<<endl;
	}*/

	Tdate d1,d2(2003,4,27);
	Tdate d3(d2);
	d1=d2;
	d1.print();
	d2.print();
	d3.print();
	d3.set(2008,3,4);
	sfunc(&d1);
	sfunc(d3);
	system("pause");
	return 0;
}

