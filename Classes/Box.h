#ifndef BOX_H
#define BOX_H
#include <string>
using namespace std;

class Box
{
	/*access attributes of the members */
	public:
      double length;   // Length of a box
      double breadth;  // Breadth of a box
      double height;   // Height of a box
	protected:
};

class Line
{
	public:
	  //a constructor
	  //a special member function of a 
	  //class that is executed whenever 
	  //we create new objects of that class.
	  //Line(); //a default constructor with no parameter
	  //Line(double len,double wid,string col);//assign inital value
	  //Line(double len):length(len);
	  
	  void setLength(double len);
	  double getLength( void );
	  
	  //A destructor is a special member function of a class 
	  //that is executed whenever an object of it's class goes 
	  //out of scope or whenever the delete expression is applied 
	  //to a pointer to the object of that class
	  ~Line(); //declaration of the destructor
	  
	  //The copy constructor is a constructor which creates an object 
	  //by initializing it with an object of the same class, which has 
	  //been created previously
	  Line(int len);
	  
	  //obj is a reference to an object being used to initlize 
	  //another object
	  Line(const Line &obj); //copy constructor
	
	private:
	  double length;
	  double width;
	  string color;
	  int *ptr;
};
#endif
