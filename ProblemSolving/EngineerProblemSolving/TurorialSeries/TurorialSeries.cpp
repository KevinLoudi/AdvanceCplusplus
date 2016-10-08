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

void suspension(char *s)
{
	cout<<s<<endl;
	delete s;
}

void reverse(char *s)
{
	char *p, *q, temp;
	p=s;
	q=s+strlen(s)-1;
	while(p<q)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;q--;
	}
}

int leapyear(int year);

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

	/*Parent P;
	P.printvarP();

	Child C;
	C.printvarP();
	C.SetP(30);
	C.printvarP();
	//C.printX(); //can not access protected section
	P.printX();

	P.printvarP();*/

	int *iptr, iArray[10]={0,1,2,3,4,5,6,7,8,9};
	double *fptr,fArray[10]={9,8,7,6,5,4,3,2,1,0};
	int x;
	iptr=iArray;
	fptr=fArray;
	//address--contents
	for (int i = 0; i < 10; ++i)
	{
		cout<<i+iptr<<" "<<*(i+iptr)<<" "
		    <<i+fptr<<" "<<*(i+fptr)<<endl;
	}

	//指针数组，一个数组里包含的全是指针
	int *ap[2];
	int a=23, b=45;
	ap[0]=&a;
	ap[1]=&b;
	
	//数组指针，一个指针，指向一个数组
	int (*bp) = new int[2];
	bp[0]=0;
	bp[1]=1;

	cout<<endl;
	for (int i = 0; i < 2; ++i)
	{
		//for pointer-array, we need to use double * before retrive the contents
		cout<<i+ap<<" "<<*(*(i+ap))<<" "
			//whil for array-pointer, it's much simpler
		    <<i+bp<<" "<<*(i+bp)<<endl;
	}

	//next we demostrate the "pointer-suspension", it is when two pointer actually point
	//to the same adress, and then one deleted, the other also become void

	char *p=new char[100];
	char *s;
	s=p;
	strcpy(p,"C++ programming");
	//suspension(p);
	reverse(s);
	cout<<s<<endl;
	delete[] p;

	//a common array
	static char day[7][10]={
	"Su","Mo","Tu","We","TH","FR","Sa" 
	};

	//a point array, each element contain a pointer to a string
	static char *dday[7]={
		"Su","Mo","Tu","We","TH","FR","Sa"
	};

	for (int i = 0; i < 7; ++i)
	{
		//*(dday[i]+i) == day[i][i]
		cout<<i<<" "<<day[i]+0<<" "<<*(dday[i]+1)<<endl;
	}

	/*function-pointer===================================*/
	system("cls"); 
	int year,result;
	//declare a int type function
	int (*fnptr)(int);
	//direct the pointer to a specific function
	fnptr=leapyear;
	cout<<"Pleasr input a year:";
	cin>>year;

	//make use of the function pointer
	result=(*fnptr)(year);
	if (result==0)
	{
		cout<<year<<" is a leapyear";
	}else
	{
		cout<<year<<" is not a leapyear";
	}
    /*============================================== */
	system("pause");
	return 0;
}

int leapyear(int year)
{
	if (((year%4==0)&&(year%100!=0))||(year%400==0))
	{
		return 1;
	}else
	{
		return 0;
	}
}
