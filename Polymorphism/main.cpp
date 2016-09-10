#include <iostream>
#include "Shape.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Main function for the program
int main( )
{
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   // store the address of Rectangle
   shape = &rec;
   // call rectangle area.
   shape->area();

   // store the address of Triangle
   shape = &tri;
   // call triangle area.
   shape->area();
   
   return 0;
}
