#pragma once
#include <iostream>
using namespace std;

class AdvanceTopics
{
public:
	AdvanceTopics(void);
	template <typename D>
	D minVal(const D x[], int n);

	template<typename X>
	X factorialR(X n);
	virtual ~AdvanceTopics(void);
};

template <typename D>
D AdvanceTopics::minVal(const D x[], int n)
{
	D min_x;
	min_x=x[0];

	for (int k=1;k<n;++k)
	{
		if (x[k]<min_x)
		{
			min_x=x[k];
		}
	}
	return min_x;
}


template<typename X>
X AdvanceTopics::factorialR(X n)
{
	/* Recursive reference until n is equal to 0. */
	if (n==0)
	{
		//Solution is known, Return unique solution
		return 1;
	}
	//Reduce the problem
	return n*factorialR(n-1);
}

class Pixel
{
   public:
	   static const unsigned int MAXVAL = 255;
	   static const unsigned short RMASK = 4;
	   static const unsigned short GMASK = 2;
	   static const unsigned short BMASK = 1;
	   static const unsigned short CHECK = 7;

	   //Constructors 
	   Pixel(); //Default
	   Pixel(unsigned ); //Grey scale
	   Pixel(unsigned,unsigned,unsigned); //Full color range

	   //Overloaded operators.
	   //Addition.
	   Pixel operator+(const Pixel& p) const;

	    //Multiplication of a Pixel by a floating point value.
	   Pixel operator*(double v) const;

	   //Division of a Pixel by an integer value.
	   Pixel operator/(unsigned v) const;

	   //Input operator.
	   friend istream& operator >>(istream& in, Pixel& p);

	   //Output operator.
	   friend ostream& operator <<(ostream& out, const Pixel& p);

	   bool overflow();
	   void reset();
	   void TestPixel();
   private:
	   void validate();
	   unsigned int red, green, blue;
	   unsigned short overflowFlag;
};