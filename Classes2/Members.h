#ifndef MEMBERS_H
#define MEMBERS_H
#include <iostream>
using namespace std;

class Box
{
	double width;
  public:
  	Box(double wid,double len);
  	~Box();
  	double length;
  	//A friend function of a class is defined outside 
	//that class' scope but it has the right to access 
	//all private and protected members of the class
    friend void printWidth( Box box ); //friends are not member functions.
    void setWidth( double wid );
};

class Boxx
{
	public:
	  //static it means no matter how many objects of 
	  //the class are created, there is only one copy of the static member
	  
	  //All static data is initialized to zero when the 
	  //first object is created
	  static int objectCount;
	  // Constructor definition
      Boxx(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
         // Increase every time object is created
         objectCount++;
      }
      double Volume()
      {
         return length * breadth * height;
      }
      int compare(Boxx box)
      {
         return this->Volume() > box.Volume();
      }
      //By declaring a function member as static, 
	  //you make it independent of any particular 
	  //object of the class. 
      static int getCount()
      {
         return objectCount;
      }
    private:
	  double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box		
};

//Inheritance allows us to define a class in terms of another class
//provide opportunity to reuse the code functionality and 
//fast implementation time
//base class->derived class
class Shape{
  public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
  protected:
      int width;
      int height;
};

class PaintCost{
	public:
		int getCost(int area){
			return area*70;
		}
};

//derived class
//access-specifier: public, protected, or private 
class Rectangle: public Shape{
	public:
		int getArea(){
			return (width*height);
		}
};
#endif
