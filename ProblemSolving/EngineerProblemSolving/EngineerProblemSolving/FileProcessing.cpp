#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "FileProcessing.h"
#include "AdvanceTopics.h"
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

void FileProcessing::read_header(istream& fin,ostream& fout,int& width, int& height, int& max)
{
	char header[100];
	char ch;
	//get magic number
	fin.getline(header,100);
	//write magic number
	fout<<header<<endl;
	cout<<header<<endl;
	//Get all comment lines and write to new file.
	fin>>ch;
	while(ch=='#')
	{
		fin.getline(header,100);
		fout <<ch << header << endl;
		cout << ch <<header << endl;
		fin >> ch;
	}
	fin.putback(ch);
	// Input width and height of image.
	fin >> width >> height;
	cout << width <<" " << height << endl;
	fout << width << " " << height << endl;
	// Input maximum color value.
	fin >> max;
	cout << max << endl;
	fout << max << endl;
	return;
}

void FileProcessing::smooth(vector<vector<Pixel>>& image, int w, int h)
{
	for(int i=1; i<h-1; i++)
		for(int j=1; j<w-1; j++)
			image[i][j] = (image[i][j] + image[i+1][j] + image[i-1][j]
		     + image[i][j+1] + image[i][j-1])/5;
}

int FileProcessing::processimage()
{
	// Declare objects.
	int height, width, max, i, j;
	string filename="tree_1.ppm";
	ifstream fin;
	ofstream fout;
	//open file for input
	fin.open(filename.c_str());
	if(fin.fail())
	{
		cerr << "Error opening input file\n";
	}
	else
	{
		filename = "smoothed_" + filename;
		fout.open(filename.c_str());
		read_header(fin,fout,width, height, max);
		vector<vector<Pixel>> image(height,width);
		// Read the image.
		for(i=0; i<height; i++)
			for(j=0; j<width; j++)
			{
				fin >> image[i][j];
			}
			//Smooth the image
			smooth(image,width,height);
			//write modified image to new file
			for(i=0;i<height;i++)
				for (j=0;j<width;j++)
				{
					fout<<image[i][j]<<" ";
					if ((j+1)%5==0)
					{
						fout<<endl;
					}
				}
	}
	return 0;
}

FileProcessing::~FileProcessing(void)
{
}
