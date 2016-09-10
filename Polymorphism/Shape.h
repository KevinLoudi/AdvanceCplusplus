#ifndef SHAPE_H
#define SHAPE_H
#include <iostream> 
using namespace std;
 
 
 //polymorphism means having many forms. 
 //Typically, polymorphism occurs when there is a 
 //hierarchy of classes and they are related by inheritance.
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      //int area()
      //after modification, the compiler looks at the contents of the
      //pointer instead of it's type
      
      //virtual enable call at any given point in the program
      //based on the kind of object, or dynamic linkage/late binding
      /*virtual int area()
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }*/
      
      //a pure virtual function
      //it may be redefined in a derived class to suit objects of the class
      //=0 tells the complier that the function has no body and it is a pure virtual
      //function
      virtual int area()=0;


};
//separate implementation for the function area()
class Rectangle: public Shape{
   public:
      Rectangle( int a=0, int b=0):Shape(a, b) { }
      //incorrect output
	  //function area() is being set once by the 
	  //compiler as the version defined in the base class
	  //static resolution of function call
	  //or static linkage, early binding
	  int area ()
      { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};
class Triangle: public Shape{
   public:
      Triangle( int a=0, int b=0):Shape(a, b) { }
      int area ()
      { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};
#endif
