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


class Parent
{
private:
	int varS;
	void printvarS();
public:
	int varP;
	void printvarP();
	Parent(){varS=5;varP=10;}
protected:
	int varX;
	void printX()
	{
	  cout<<"X="<<varX<<endl;
    }
	void SetX(int x){varX=x;}
};

void Parent::printvarP()
{
	cout<<"P="<<varP<<endl;
}
void Parent::printvarS()
{
	cout<<"S="<<varS<<endl;
}

//everything in public section have
//been copied to the child class
class Child:public Parent
{
public:
	void SetP(int a)
	{
		varP=a;
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

	//Dynamic Memory Allocation
	/*cout<<sizeof(int)<<endl;
	cout<<sizeof(double)<<endl;
	//this is reserved when the program is started
	int *p = new int; //the address will be store

	//this is reserved when the program is complied
	int a=10;
	
	*p=100;
	cout<<*p<<endl;

	delete p; //free the allocated memory
	//plan to switch pointer to somewhere else
	//free memory before action
	p=&a;


	//int A[100] = new int; //400bytes
	int N;
	cout<<"Enter number of elements: ";
	cin>>N;

	int *A = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin>>A[i];
	}
	cout<<"........"<<endl;
	for (int i = 0; i < N; ++i)
	{
		cout<<A[i]<<endl;
	}

    //delete with a bracket, or your only delete one element
	delete[] A;*/

	Parent P;
	P.printvarP();

	Child C;
	C.printvarP();
	C.SetP(30);
	C.printvarP();
	//C.printX(); //can not access protected section
	P.printX();

	P.printvarP();

	system("pause");
	return 0;
}

