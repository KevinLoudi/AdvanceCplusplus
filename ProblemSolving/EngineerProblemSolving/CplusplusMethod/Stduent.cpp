#include "StdAfx.h"
#include "Stduent.h"
#include <string>
#include <iostream>
using namespace std;

Stduent::Stduent(void)
{
}

Stduent::Stduent(int no,char *name)
{
	No=no;
	strcpy(Name,name);
}

void Stduent::print()
{
	cout<<"["<<No<<"] "<<Name<<endl;
}

Stduent::~Stduent(void)
{
}

Counsellor::Counsellor(int no,char *name)
{
	No=no;
	strcpy(Name,name);
}

void Counsellor::assess(Stduent &s,int assessed_score)
{
	s.Score=assessed_score;
}

void Counsellor::assess_compare(Stduent &s1, Stduent &s2)
{
	if (s1.Score>s2.Score)
	{
		cout<<s1.Name<<" performed better"<<endl;
	}
	else
	{
		cout<<s2.Name<<" performed better"<<endl;
	}
}

Counsellor::~Counsellor()
{

}

Commodity::Commodity(char *cNo,char *cName,float cPrice/*=0*/)
{
	strcpy(No,cNo);
	strcpy(Name,cName);
	Price=cPrice;
}

Commodity::Commodity()
{

}

void Commodity::PriceInfo()
{	
	//cout<<"the Price of "<<Name<<" is "<<Price<<endl;
	//when create objects of tha same class, a implicte point "this" point to 
	//itself
	cout<<"the Price of "<<this->Name<<" is "<<Price<<endl;
}

Commodity::~Commodity()
{

}
