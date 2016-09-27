#pragma once
#include <iostream>
using namespace std;

class Tdate
{
private:
	//a static member used to share between objects of same type
	static int yearcount;
	int year;
	int month;
	int day;
public:
	Tdate(void);
	//constructor with parameters list
	Tdate(int y,int m,int d):year(y),month(m),day(d)
	{
		cout<<"constructor with parameters list"<<endl;
		yearcount++;
	};
	//copy constructor 
	Tdate(Tdate &p)
	{
		year=p.year+1; 
	    month=p.month+1; 
		day=p.day+1;
		cout<<"copy constructor "<<endl;
		yearcount++;
	};
	void set(int y,int m,int d);
	void print();
	//when a member function is defined inside a class body,
	//it is seen as an inline function
	bool isLeapyear();
	//When a class will be taken as a base class, its deconstructe
	//function would be seen as virtual
	virtual ~Tdate(void);
};
