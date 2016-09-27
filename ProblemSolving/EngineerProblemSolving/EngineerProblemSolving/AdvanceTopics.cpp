#include "StdAfx.h"
#include "AdvanceTopics.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define INFILENAME "tree_1.ppm"

AdvanceTopics::AdvanceTopics(void)
{
}

AdvanceTopics::~AdvanceTopics(void)
{
}
/*----------------------------------------------------------------*/
Pixel::Pixel(void)
{
	//Black
	red=green=blue=0;
	return;
}
/*----------------------------------------------------------------*/
Pixel::Pixel(unsigned int value)         
{
	//Grey scale
	red=green=blue=value;
	validate();
	return;
}
/*----------------------------------------------------------------*/
Pixel::Pixel(unsigned int r,unsigned int g,unsigned int b)
{
	//Full color range
	red=r;
	green=g;
	blue=b;
	validate();
	return;
}

Pixel Pixel::operator+(const Pixel& p) const
{
	Pixel temp;
	temp.red=red+p.red;
	temp.green = green + p.green;
	temp.blue = blue + p.blue;
	temp.validate();
	return temp;
}

Pixel Pixel::operator*(double v) const
{
	Pixel temp;
	temp.red = red*v;
	temp.green = green*v;
	temp.blue = blue*v;
	temp.validate();
	return temp;
}

Pixel Pixel::operator/(unsigned v) const
{
	Pixel temp;
	temp.red = red/v;
	temp.green = green/v;
	temp.blue = blue/v;
	temp.validate();
	return temp;
}

bool Pixel::overflow()
{
	return(overflowFlag&CHECK); //0111
}

void Pixel::reset()
{
	if (red>MAXVAL) red=MAXVAL;
	if(green > MAXVAL) green = MAXVAL;
	if(blue > MAXVAL) blue = MAXVAL;
	overflowFlag = 0;
}

void Pixel::TestPixel()
{
	//Test constructors
	Pixel defaultP;
	Pixel grayP(100);
	Pixel redP(255,0,0);
	Pixel image(0);
	image=redP+grayP;
	image.validate();
	//Test output operator
	cout << "Default pixel: " << defaultP << endl;
	cout << "Gray pixel: " << grayP << endl;
	cout << "Red pixel: " << redP << endl;
	//Test arithmetic operators
	//Addition
	defaultP = grayP + redP;
	cout << "After addition, defaultP: " << defaultP << endl;
}

void Pixel::validate()
{
	if(red > MAXVAL) overflowFlag = overflowFlag|RMASK;//0100
	if(green > MAXVAL) overflowFlag = overflowFlag|GMASK;//0010
	if(blue > MAXVAL) overflowFlag = overflowFlag|BMASK;//0001
}

ostream& operator<<(ostream& out,const Pixel& p)
{
	out<<p.red<<":";
	out<<p.green<<":";
	out<<p.blue<<":";
	//shoud be output in dex
	out<<p.overflowFlag<<endl;
	return out;
}

istream& operator>>(istream& in,Pixel& p)
{
	in>>p.red>>p.green>>p.blue;
	p.validate();
	return in;
}