// EngineerProblemSolving.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "FileProcessing.h"
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	FileProcessing FP;
	char* infile="sensor.dat";
	char* outfile="checkedSensor.dat";
	FP.ReadandCheckDat(infile,outfile);

	string iinfile="sensor1.dat";
	FP.GenerateSummaryReport(iinfile);

	system("pause");
	return 0;
}

