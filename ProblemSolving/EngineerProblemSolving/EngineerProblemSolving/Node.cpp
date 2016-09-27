#include "StdAfx.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

//Constructors.
Node::Node() : data(0),left(0),right(0)
{}

Node::Node(int v):data(v), left(0), right(0)
{}

//Accessors
Node* Node::getLeft() const
{
	return left;
}
Node* Node::getRight() const
{
	return right;
}
int Node::getData() const
{
	return data;
}
//Mutators
void Node::setLeft(Node* l)
{
	left=l;
}
void Node::setRight(Node* r)
{
	right=r;
}
void Node::setData(int v)
{
	data=v;
}

Node::~Node(void)
{
}

//Default constructor
Point::Point()
{
	//cout << "Constructing Point object, default: \n";
	//cout << "initializing to zero" << endl;
	xCoord = 0.0;
	yCoord = 0.0;
}

Point::Point(double x, double y)
{
	//input parameters x,y
	//cout << "Constructing Point object, parameterized: \n";
	//cout << "input parameters: " << x << "," << y << endl;
	xCoord = x;
	yCoord = y;
}

void Point::setX(double newX)
{
	xCoord=newX;
}

void Point::setY(double newY)
{
	yCoord=newY;
}

void Point::input(istream& in)
{
	double x, y;
	in>>x>>y;
	xCoord=x;
	yCoord=y;
}

bool Point::operator==(const Point& rhs) const
{	
	if(rhs.xCoord == xCoord &&
		rhs.yCoord == yCoord )
	{
		return true;
	}
	else
	{
		return false;
	}
}

double Point::operator-(const Point& rhs) const
{
	double t1, t2, d;
	t1 = rhs.xCoord - xCoord; //(x2-x1)
	t2 = rhs.yCoord - yCoord; //(y2-y1)
	d = sqrt( pow(t1,2) + pow(t2,2) );
	return d;
}

//

Rectangle::Rectangle():origin(0,0)
{
	cout << "Constructing Rectangle() ..." << this << endl;
	width=height=1;
}

Rectangle::Rectangle(double w, double h, double x, double y)
{
	cout << "Constructing Rectangle(parameter list)..."<< this <<endl;
	width=w;
	height=h;
}

double Rectangle::getWidth() const{return width;}

double Rectangle::getHeight() const{return height;}

Point Rectangle::getOrigin() const{return origin;}

double Rectangle::area() const {return width*height;}

void Rectangle::setWidth(double w){width=w;}

void Rectangle::setHeight(double h){height=h;}

void Rectangle::setOrigin(Point p){origin=p;}

void Rectangle::move(double dx, double dy)
{
	origin.setX(origin.getX()+dx);
	origin.setY(origin.getY()+dy);
}

void Rectangle::print(ostream& out) const
{
	out<<"Width: "<<getWidth()<<" Height: " << getHeight();
	out<<"\nOrigin at: (" <<this->getOrigin().getX()
		<< "," << this->getOrigin().getY() << ")";
}


Square::Square()
{
	//Rectangle constructor called implicitly.
	cout<<"Construction Square().."<<this<<endl;
}

Square::Square(const Point&, double s)
{
	//Parameterized constructor explicitly called in parameter list.
	cout << "Constructing Square( Point, double).. " << this
		<< endl;
}

double Square::getside() const
{
	return getWidth();
}

void Square::setside(double s)
{
	setWidth(s);
	setHeight(s);
}
