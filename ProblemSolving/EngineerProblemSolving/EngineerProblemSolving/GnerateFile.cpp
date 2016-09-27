#include "StdAfx.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "GnerateFile.h"
using namespace std;

GnerateFile::GnerateFile(void)
{
}

//generate a file of height and velocity values for a 
//weather ballon
int GnerateFile::GenerateBallonData(string outfile)
{
	ofstream balloon;
	int loops;
	double initial, increment, final,time,height,velocity;
	double max_time(0), max_height(0);
	balloon.open(outfile.c_str());
	
	// Get user input.
	cout << "Enter initial value for table (in hours) \n";
	cin >> initial;
	cout << "Enter increment between lines (in hours) \n";
	cin >> increment;
	cout << "Enter final value for table (in hours) \n";
	cin >> final;

	//set output format
	cout.setf(ios::fixed);
	cout.precision(2);
	//set output format for the file
	balloon.setf(ios::fixed);
	balloon.precision(2);

	// Print report heading.
	cout << "\n\nWeather Balloon Information \n";
	cout << "Time Height Velocity \n";
	cout << "(hrs) (meters) (meters/s) \n";

	// Determine number of iterations required.
	// Use integer index to avoid rounding error.
	loops=(int)((final-initial)/increment);
	for (int itime=0;itime<=loops;itime++)
	{
		time=initial+itime*loops;
		height = -0.12*pow(time,4) + 12*pow(time,3)
			- 380*time*time + 4100*time + 220;
		velocity = -0.48*pow(time,3) + 36*time*time
			- 760*time + 4100;

		//print the report information
		cout<<setw(6)<<time<<setw(10)<<height
			<<setw(10)<<velocity/3600<<endl;
		balloon<<setw(6)<<time<<setw(10)<<height
			<<setw(10)<<velocity/3600<<endl;

		if (height>max_height)
		{
			max_height=height;
			max_time=itime;
		}
	}
	cout<<"\nMax height and corresponding time was "
		  <<setw(8)<<max_height
		  <<" meters\nand it occurred at "
		  <<setw(6)<<max_time<<endl;
	balloon.close();
	return 0;
}

int GnerateFile::Accessmemory()
{
	/*int a(1), b(2);
	int *c=&a, *d=&b;

	cout << "a= " << a << "; address of a = " << &a << endl;
	cout << "b= " << b << "; address of b = " << &b << endl;
	cout << "c= " << c << "; content of c = " <<*c<<endl;
	cout << "d= " << d << "; content of d = " <<*d<<endl;
	
	//to see if it is possible to return a local variable
	//return a+b;
	return *c+*d;*/

	int a(1), b(2), *ptr(&a);
	cout << "a = " << a << "; address of a = " << &a << endl;
	cout << "b = " << b << "; address of b = " << &b << endl;
	cout << "ptr = " << ptr << "; address of ptr = " << &ptr << endl;
	cout << "ptr points to the value " << *ptr << endl;
	return a+b+*ptr;

}

int GnerateFile::AccessString(char str1[],char str2[])
{
	int count(0);
	char *ptr1(str1), *ptr2(str2);
	// Count number of occurrences of strg2 in strg1.
	// While function strstr does not return NULL
	// increment count and move ptr1 to next section
	// of strg1.
	while((ptr1=strstr(ptr1,ptr2))!=NULL)
	{
		count++;
		ptr1++;
	}
	// Print the number of occurrences.
	cout<<"Count: "<<count<<endl;
	return count;
}

GnerateFile::~GnerateFile(void)
{
}
