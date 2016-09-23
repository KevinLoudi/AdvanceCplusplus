#pragma once
using namespace std;

class FileProcessing
{
public:
	struct  Report
	{
		int num_data;
		double aver_data;
		double max_data;
		double min_data;
	};
	 
	FileProcessing(void);
	int ReadandCheckDat(char* infile,char* outfile);
	int GenerateSummaryReport(string infile);
	virtual ~FileProcessing(void);
};
