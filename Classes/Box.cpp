#include <iostream>
#include "Box.h"
#include <string>
using namespace std;

Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    ptr = new int;
    *ptr=len;
}

//using initalization list to initialize fields
//to initalize multiply fields
//Line::Line(double len,double wid,string col):length(len),width(wid),color(col)
//{
//	cout << "Object is being created" << endl;
//	length = len;
//}

Line::~Line(void)
{
	cout << "Freeing memory!" << endl;
	delete ptr;
}

Line::Line(const Line &obj)
{
	cout<<"Copy constructot allocating ptr."<<endl;
	ptr=new int;
	*ptr=*obj.ptr;
}

void Line::setLength( double len )
{
    length = len;
}

double Line::getLength( void )
{
    //return length;
	  return *ptr;
}
