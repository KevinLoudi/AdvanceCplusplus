#include "StdAfx.h"
#include "Tdate.h"
#include <iostream>
using namespace std;

Tdate::Tdate(void)
{
	cout<<"implict constructot"<<endl;
	yearcount++;
}

void Tdate::set(int y,int m,int d)
{
   year=y;
   month=m;
   day=d;
}

void Tdate::print()
{
	cout<<"Now ther are "<<yearcount<<" date objects.";
	cout<<"Date: "<<year<<"--"<<month<<"--"<<day<<endl;	
}

bool Tdate::isLeapyear()
{
	return(((year%4==0)&&(year%100!=0))||(year%400==0));
}

Tdate::~Tdate(void)
{
	cout<<"destruction is called."<<endl;
	yearcount--;
}
