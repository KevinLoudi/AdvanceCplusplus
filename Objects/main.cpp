//from http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
#include <iostream>
#include "Method.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int main() {
//   printData pd;
// 
//   // Call print to print integer
//   pd.print(5);
//   // Call print to print float
//   pd.print(500.263);
//   // Call print to print character
//   pd.print("Hello C++");
// 
//   return 0;
//}

//int main( )
//{
//   Box Box1;                // Declare Box1 of type Box
//   Box Box2;                // Declare Box2 of type Box
//   Box Box3;                // Declare Box3 of type Box
//   double volume = 0.0;     // Store the volume of a box here
// 
//   // box 1 specification
//   Box1.setLength(6.0); 
//   Box1.setBreadth(7.0); 
//   Box1.setHeight(5.0);
// 
//   // box 2 specification
//   Box2.setLength(12.0); 
//   Box2.setBreadth(13.0); 
//   Box2.setHeight(10.0);
// 
//   // volume of box 1
//   volume = Box1.getVolume();
//   cout << "Volume of Box1 : " << volume <<endl;
// 
//   // volume of box 2
//   volume = Box2.getVolume();
//   cout << "Volume of Box2 : " << volume <<endl;
//
//   // Add two object as follows:
//   Box3=Box1+Box2;
//
//   // volume of box 3
//   volume = Box3.getVolume();
//   cout << "Volume of Box3 : " << volume <<endl;
//
//   return 0;
//}

//int main()
//{
//	Distance D1(11,10), D2(-5,11);
//	
//	-D1;
//	D1.displayDistance();
//	
//	-D2;
//	D2.displayDistance();
//	
//   if(D1<D2)
//   {
//      cout << "D1 is less than D2 " << endl;
//   }
//   else
//   {
//      cout << "D2 is less than D1 " << endl;
//   }
//	
//	//Distance D3(-2,12);
//	//cout<<"Whether D has minus members: "<<(!D3)<<endl;
//	
//	return 0;
//}

//  int main()
//  {
//  	Distance D1(11,10),D2(5,11),D3;
//  	
//  	cout<<"Enter the value of object: "<<endl;
//  	cin>>D3;
//    cout << "First Distance : " << D1 << endl;
//    cout << "Second Distance :" << D2 << endl;
//    cout << "Third Distance :" << D3 << endl;
//    return 0;
//  }

// int main()
//  {
//    Time T1(11,59),T2(10,40);
   
//    ++T1;                    // increment T1
//    T1.displayTime();        // display T1
//    ++T1;                    // increment T1 again
//    T1.displayTime();        // display T1
 
//    T2++;                    // increment T2
//    T2.displayTime();        // display T2
//    T2++;                    // increment T2 again
//    T2.displayTime();        // display T2
//    return 0;
// }


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
