// EngineerProblemSolving.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "FileProcessing.h"
#include "AdvanceTopics.h"
#include "GnerateFile.h"
#include "Node.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*FileProcessing FP;
	char* infile="sensor.dat";
	char* outfile="checkedSensor.dat";
	FP.ReadandCheckDat(infile,outfile);

	string iinfile="sensor1.dat";
	FP.GenerateSummaryReport(iinfile);*/

	//GnerateFile GP;
	/*string filename="Report.txt";
	GP.GenerateBallonData(filename);*/

	/*int temp(0);
	temp=GP.Accessmemory();
	cout<<"The returned number: "<<temp<<endl;*/

	/*char strg1[]="abbcfgwdbibbw", strg2[]="b";
    vector<string> SameStr;

	int tmpcount(0);
	tmpcount=GP.AccessString(strg1,strg2);
	cout<<"Same part count..."<<tmpcount<<endl;

	AdvanceTopics AT, *pAT;
	pAT=&AT;
	const int SIZE = 10;
	char ch[SIZE] = {'h','e','l','l','o','w','o','r','l','d'};
	int iDat[SIZE] = {5,2,7,8,2,5,9,8,1,9};
	double dDat[SIZE] = {-2.1,4.3,0.0,9.3,0.4,-4.2};
	string sDat[SIZE] = {"this","short","the","list","of","strings"};
	//Print smallest value in each array.
	cout << "smallest char in ch is "
		<< pAT->minVal(ch,SIZE) << endl; // Char
	cout << "smallest integer in iDat is "
		<< pAT->minVal(iDat,SIZE) << endl; // int
	cout << "smallest double in dDat is "
		<< pAT->minVal(dDat,6) << endl; // double
	cout << "smallest string in sDat is: "
		<< pAT->minVal(sDat,6) << endl; // string*/

	/*FileProcessing FP;
	FP.processimage();*/
	//pPixel.TestPixel();

	/*AdvanceTopics AT;
	int n;
	n = 6;
	cout<<"Recursive:  "<<n<<"!="<< AT.factorialR(n)<<endl;*/

	/*Node n1,n3;
	Node n2(4);
	//Test accessor methods.
	cout << "Value of n1 after default construction: "
		<< endl << n1.getData() << "," << n1.getLeft() << ","
		<< n1.getRight() << endl;
	cout << "Value of n2 after parameterized construction: "
		<< endl << n2.getData() << "," << n2.getLeft() << ","
		<< n2.getRight() << endl;

	//Test mutator methods.
	n1.setData(13);
	n1.setLeft(&n2);
	n1.setRight(&n3);
	cout << "Value of n1 after modification: " << endl
		<< n1.getData() << "," << n1.getLeft() << ","
		<< n1.getRight() << endl;
	cout << "Value of n2 after modification: " << endl
		<< n2.getData() << "," << n2.getLeft() << ","
		<< n2.getRight() << endl;
	cout << "Value of n3 after modification: " << endl
		<< n3.getData() << "," << n3.getLeft() << ","
		<< n3.getRight() << endl;*/

	Point p1(5,4);
	Square s1,s2(p1,4);
	/* Test print() */
	/* inherited from Rectangle. */
	cout << "Square s2 has: " << endl;
	s2.print(cout);
	cout << endl;
	//Test getSide().
	cout << "Length of side of s2 is "
		<< s2.getside() << endl;
	//Test area method from Rectangle
	cout << "Area of s2 is "
		<< s2.area() << endl;
	cout << "***********************\n";
	//Test setSide()
	s1.setside(3.2);
	//Test print()
	cout << "Square s1 has: " << endl;
	s1.print(cout);
	cout << endl;
	system("pause");
	return 0;
}

