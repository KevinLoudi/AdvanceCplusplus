#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include "FileProcessing.h"
using namespace std;

#define REPORT_FILE "sensor1Report.txt"

FileProcessing::FileProcessing(void)
{
}

//read data from a file and valid it 
int FileProcessing::ReadandCheckDat(char* infile,char* outfile)
{
	ifstream fin(infile);
	//ifstream fin(INFILE);
	ofstream fout(outfile);

	if (fin.fail())
	{
		cerr<<"could not open input file sensor.dat\n";
		return -1; //exit(1)
	}
	if(fout. fail())
	{
		cerr << "could not open output file checkedSensor.dat\n";
		return -1; //exit(1)
	}

	//All files are open.
	double t, motion;
	int count(0);
	fin>>t>>motion;
	while(!fin.eof())
	{
		++count;
		if (t>=0&&motion>=0)
		{
			fout<<t<<" "<<motion<<endl;
		}
		//write invaild data to standaed error
		else
		{
			cerr<<"Bad data encountered on line"
			      <<count<<endl
				  <<t<<" "<<motion<<endl;
		}
	 fin>>t>>motion;
	}
	fin.close();
	fout.close();
	return 0;
}

//generates a summary report from a data file
int FileProcessing::GenerateSummaryReport(string infile)
{
	ifstream sensor;
	ofstream report;
	Report Re;
	double time, motion,sum=0;

	//open the file to read data
	sensor.open(infile.c_str());
	if (sensor.fail())
	{
		cerr<<"Failed to open the input file"<<infile.c_str()<<endl;
		return -1;
	}
	
	//open the report file
	report.open(REPORT_FILE);

	sensor>>Re.num_data;
	sensor>>time>>motion;
	Re.max_data=Re.min_data=motion;

	//read the remaining data and compute the summary
	for (int k=1;k<Re.num_data;k++)
	{
		sensor>>time>>motion;
		sum+=motion;
		if (motion>Re.max_data)
		{
			Re.max_data=motion;
		}
		if (motion<Re.min_data)
		{
			Re.min_data=motion;
		}
	}

	//output report in a setted format
	report.setf(ios::fixed);
	report.setf(ios::showpoint);
	report.precision(3);

	// Print summary information.
	report << "Number of sensor readings: "
		<< Re.num_data << endl;
	report << "Average reading: "
		<< sum/Re.num_data << endl;
	report << "Maximum reading: "
		<< Re.max_data << endl;
	report << "Minimum reading: "
		<< Re.min_data << endl;

	sensor.close();
	report.close();
	return 0;
}

int FileProcessing::ProcessingHTMLFiles(string infile)
{


	return 0;
}

FileProcessing::~FileProcessing(void)
{
}
