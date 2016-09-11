//#include <iostream>
////reading from standard input and writing to standard output respectively
//#include <fstream>
//#include <iostream>
//#include "Methods.h"
//using namespace std;
//
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
////fstream: file stream generally, and has the capabilities of both 
////ofstream and ifstream which means it can create files, 
////write information to files, and read information from files.
////int main() {
////	
////	char data[100];
////	
////	//open a file in write mode
////	//used to create files and to write information to files
////	ofstream outfile;
////	outfile.open("afile.txt");
////	
////    cout << "Writing to the file" << endl;
////    cout << "Enter your name: "; 
////    //read the line from outside
////    cin.getline(data,100);
////    
////    //write inputted data into the file
////    outfile<<data<<endl;
////    
////    cout<<"Enter your age:";
////	cin>>data;
////	//ignore the extra characters left by previous read statement
////	cin.ignore();
////	
////	//again write inputted data into the file
////    outfile<<data<<endl;
////	
////	//close the opened file.
////	outfile.close();
////	
////	//open a file in read mode
////	//used to read information from files
////	ifstream infile;
////	infile.open("afile.txt");
////	
////	//write the data at the screen
////	cout<<"Reading from the file"<<endl;
////	infile>>data;
////    
////    //again read the data from the file and display it
////	cout<<data<<endl;
////	
////	//closr the opened file
////	infile.close();
////	
////	return 0;
////}
//
//double division(int a, int b)
//{
//   if( b == 0 )
//   {
//   	//throw exception anywhere within a code block
//      throw "Division by zero condition!";
//   }
//   return (a/b);
//}
//
//int main()
//{
//	int x=50;
//	int y=0;
//	double z=0;
//	
//	try
//	{
//		//protected code
//		z=division(x,y);
//		cout<<z<<endl;
//	}catch(const char* msg)
//	{
//		//code to handle any exception
//		cerr<<msg<<endl;
//	}
//	
//	return 0;
//   
//}

//#include <iostream>
//#include <exception>
//using namespace std;
//
//struct MyException : public exception
//{
//  const char * what () const throw ()
//  {
//    return "C++ Exception";
//  }
//};
// 
//int main()
//{
//  try
//  {
//    throw MyException();
//  }
//  catch(MyException& e)
//  {
//    std::cout << "MyException caught" << std::endl;
//    std::cout << e.what()<< std::endl;
//  }
//  catch(std::exception& e)
//  {
//    //Other errors
//  }
//}

//dynamic memory 

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	//new data-type could be any built-in data type or user defined
//	//data types
//	double* pvalue=NULL;//initialize pointer with null
//	pvalue=new double;//request memory for the variable
//	
//	//malloc() are nor recommended in C++
//	*pvalue=2949.99;//store value at allocated address
//	cout<<"Value of pvalue: "<<*pvalue<<endl;
//	
//	delete pvalue; //free up the memory
//	
//	return 0;
//}

#include <iostream>
using namespace std;

class Box
{
   public:
      Box() { 
         cout << "Constructor called!" <<endl; 
      }
      ~Box() { 
         cout << "Destructor called!" <<endl; 
      }
};

int main()
{
	//allocate memory for an array
	char* pvalue=NULL;
	pvalue=new char[20];//request memory for the variable
	delet [] pvalue;
	
	//operator for a multi-dimensional array
	int ROW=2;
	int COL=3;
	//allocate memory for rows
	double **ppvalue=new double* [ROW];
	
	//allocate memory for columns
	for(int i=0;i<COL;i++)
	{
		ppvalue[i]=new double[COL];
	}
	
	
	Box* myBoxArray=new Box[4];
	
	delete[] myBoxArray;
	
	return 0;
}


