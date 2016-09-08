#include "StLine.h"
#include <iostream>
using namespace std;

// Member functions definitions including constructor
StLine::StLine(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    // allocate memory for the pointer;
    ptr = new int;
    *ptr = len;
}

StLine::StLine(const StLine &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
   *ptr = *obj.ptr; // copy the value
}

StLine::~StLine(void)
{
    cout << "Freeing memory!" << endl;
    delete ptr;
}
int StLine::getLength( void )
{
    return *ptr;
}


