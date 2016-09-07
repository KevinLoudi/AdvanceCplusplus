#include <iostream>
#include "Box.h"
using namespace std;

Line::Line(double len)
{
    cout << "Object is being created" << endl;
    length = len;
}

void Line::setLength( double len )
{
    length = len;
}

double Line::getLength( void )
{
    return length;
}
