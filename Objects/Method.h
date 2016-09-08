#ifndef METHOD_H
#define METHOD_H
#include <iostream>
using namespace std;

//function overloading and operator overloading
//specify more than one definition for a function 
//name or an operator in the same scope
class printData
{
	//overload function
	public:
	  //declarations have different arguments and 
	  //obviously different definition (implementation)
	  void print(int i) {
        cout << "Printing int: " << i << endl;
      }

      void print(double f) {
        cout << "Printing float: " << f << endl;
      }

      void print(char* c) {
        cout << "Printing character: " << c << endl;
      }
};

class Box
{
	public:
	  double getVolume(void)
      {
         return length * breadth * height;
      }
      void setLength( double len )
      {
          length = len;
      }

      void setBreadth( double bre )
      {
          breadth = bre;
      }

      void setHeight( double hei )
      {
          height = hei;
      }
      
      //overload + operator to add two Box objects
      //binary operators take two arguments 
      //such as +, -, *, /
      Box operator+(const Box& b)
      {
      	Box box;
      	box.length= this->length+b.length;
      	box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
	  }
    private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

//example of using unary operator on a single iperand
class Distance
{
	private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
    public:
      // required constructors
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      friend ostream &operator<<(ostream &output,const Distance &D)
      {
      	output<<"Feet: "<<D.feet<<"Inches: "<<D.inches;
	  }
	  friend istream &operator>>(istream &input,Distance &D)
	  {
	  	input>>D.feet>>D.inches;
	  	return input;
	  }
      // method to display distance
      void displayDistance()
      {
         cout << " Feets: " << feet << " Inches: " << inches <<endl;
      }
      //overload minus (-) operator
      Distance operator- ()
      {
      	feet = -feet;
      	inches = -inches;
      	return Distance(feet,inches);
	  }
	  //overload no
	  bool operator! ()
	  {
	  	return (feet<0)||(inches<0);
	  }
	  //
	  bool operator <(const Distance& d)
	  {
	  	if(feet<d.feet){
	  		return true;
		  }
		if(feet==d.feet&&inches<d.inches){
			return true;
		}
		return false;
	  }
};

class Time
{
	private:
      int hours;             // 0 to 23
      int minutes;           // 0 to 59
      
    public:
      // required constructors
      Time(){
         hours = 0;
         minutes = 0;
      }
      Time(int h, int m){
         hours = h;
         minutes = m;
      }
      // method to display time
      void displayTime()
      {
         cout << "H: " << hours << " M:" << minutes <<endl;
      }
      //overload prefix ++ operator
      Time operator++ ()
      {
      	++minutes;
      	if(minutes>60)
      	{
      	  minutes-=60;
		  ++hours;	
		}
		return Time(hours,minutes);
	  }
	  //overloaded postfix ++ operator
      Time operator++( int )         
      {
         // save the orignal value
         Time T(hours, minutes);
         // increment this object
         ++minutes;                    
         if(minutes >= 60)
         {
            ++hours;
            minutes -= 60;
         }
         // return old original value
         return T; 
      }

	  
};
#endif
