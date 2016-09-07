#ifndef BOX_H
#define BOX_H

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
	  Line(double len);//assign inital value
	  void setLength(double len);
	  double getLength( void );
	
	private:
	  double length;
};
#endif
