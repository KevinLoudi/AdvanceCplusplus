#include <iostream>
#include "Members.h"
using namespace std;

//If a function is inline, the compiler places 
//a copy of the code of that function at each 
//point where the function is called at compile time.
inline int Max(int x,int y)
{
	return (x>y)?x:y;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Boxx::objectCount=0;

int main() {
//   Box box(25.4,10.7);
// 
//   // set box width with member function
//   box.setWidth(10.0);
//   
//   // Use friend function to print the wdith.
//   printWidth( box );
// 
//   return 0;

//   cout << "Max (20,10): " << Max(20,10) << endl;
//   cout << "Max (0,200): " << Max(0,200) << endl;
//   cout << "Max (100,1010): " << Max(100,1010) << endl;
//   return 0;

//   Boxx Box1(3.3, 1.2, 1.5);    // Declare box1
//   Boxx Box2(8.5, 6.0, 2.0);    // Declare box2
//
//   if(Box1.compare(Box2))
//   {
//      cout << "Box2 is smaller than Box1" <<endl;
//   }
//   else
//   {
//      cout << "Box2 is equal to or larger than Box1" <<endl;
//   }
//   return 0;

//    Boxx Box1(3.3, 1.2, 1.5);    // Declare box1
//    Boxx Box2(8.5, 6.0, 2.0);    // Declare box2
//    
//    //A pointer to a C++ class is done exactly 
//	//the same way as a pointer to a structure 
//    Boxx *ptrBox;                // Declare pointer to a class.
//    
//    //access members of a pointer to a class 
//	//you use the member access operator -> operator
//	
//	// Save the address of first object
//    ptrBox = &Box1;
//    
//    
//    // Now try to access a member using member access operator
//    cout << "Volume of Box1: " << ptrBox->Volume() << endl;
//
//    // Save the address of first object
//    ptrBox = &Box2;
//
//    // Now try to access a member using member access operator
//    cout << "Volume of Box2: " << ptrBox->Volume() << endl;
//    
//    //print total number of objects
//    //A static member is shared by all objects of the class. 
//	//All static data is initialized to zero when the first object is created
//    //cout<<"Total objects: "<<Boxx::objectCount<<endl;
//  
//    cout<<"Final Stage Count: "<<Boxx::getCount()<<endl;
//  
//    //scope resolution operator :: to 
//    //identify which class it belongs to
//    return 0;

	  Rectangle Rect;
	  
	  Rect.setWidth(5);
	  Rect.setHeight(7);
	  
	  // Print the area of the object.
	  cout<<"Total area: "<<Rect.getArea()<<endl;
	  
	  return 0;
}
