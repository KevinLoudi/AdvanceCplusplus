#include "Members.h"
#include <iostream>
using namespace std;

Box::Box(double wid,double len):width(wid),length(len)
{
	cout<<"Initlize Class Member"<<endl;
	width=wid;
	length=len;
}

Box::~Box()
{
	cout<<"Free Memory"<<endl;
}

// Member function definition
void Box::setWidth( double wid )
{
    width = wid;
}

// Note: printWidth() is not a member function of any class.
void printWidth( Box box )
{
   /* Because printWidth() is a friend of Box, it can
    directly access any member of this class */
   cout << "Width of box : " << box.width <<endl;
}
