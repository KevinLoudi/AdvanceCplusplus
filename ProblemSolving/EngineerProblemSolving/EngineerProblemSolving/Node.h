#ifndef NODE_H
#define NODE_H

#include <fstream>
using namespace std;

class Node
{
public:
	Node(); //default constructor
	Node(int);//parameterized constructor
	//Accessors
	Node* getLeft() const;
	Node* getRight() const;
	int getData() const;
	//Mutators
	void setLeft(Node*);
	void setRight(Node*);
	void setData(int v);
	virtual ~Node(void);
private:
	int data;
	Node *left;
	Node *right;
};

class Point
{
	//Type declaration statements
	//Data members.
private:
	double xCoord, yCoord; //Class attributes

public:
	//Declaration statements for class methods
	//Constructors for Point class
	Point(); //default constructor
	Point(double x, double  y); //parameterized constructor

	//Overloaded operators
	double operator - (const Point& rhs) const;  
	bool operator ==(const Point& rhs) const; 

	//Accessor Methods
	double getX() const {return xCoord;}
	double getY() const {return yCoord;}

	//Mutator Methods
	void setX(double newX); 
	void setY(double newY); 
	void input(istream& in);
	virtual ~Point(void){};
};

class Rectangle: public Point
{
private:
	double width, height;
	Point origin;

public:
	//Constructors
	Rectangle();
	Rectangle(double w, double p, double x, double y);
	//Accessor methods.
	double getWidth() const;
	double getHeight() const;
	Point getOrigin() const;
	double area() const;
	//Mutator methods.
	void setWidth(double w);
	void setHeight(double h);
	void setOrigin(Point p);
	void move(double dx, double dy);
	void print(ostream& out) const;
};

class Square: public Rectangle, Point
{
  public:
	  //Constructors
	  Square();
	  Square(const Point&, double s);
	  double getside() const;
	  void setside(double);
};
#endif