// EngineerProblemSolving.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "FileProcessing.h"
#include "GnerateFile.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*FileProcessing FP;
	char* infile="sensor.dat";
	char* outfile="checkedSensor.dat";
	FP.ReadandCheckDat(infile,outfile);

	string iinfile="sensor1.dat";
	FP.GenerateSummaryReport(iinfile);*/

	GnerateFile GP;
	/*string filename="Report.txt";
	GP.GenerateBallonData(filename);*/

	/*int temp(0);
	temp=GP.Accessmemory();
	cout<<"The returned number: "<<temp<<endl;*/

	char strg1[]="abbcfgwdbibbw", strg2[]="b";
    vector<string> SameStr;

	int tmpcount(0);
	tmpcount=GP.AccessString(strg1,strg2);
	cout<<"Same part count..."<<tmpcount<<endl;

	system("pause");
	return 0;
}

