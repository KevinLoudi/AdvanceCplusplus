#pragma once
#include <vector>
#include "AdvanceTopics.h"
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
	int ProcessingHTMLFiles(string infile);

	void read_header(istream& fin,ostream& fout,int& width, int& height, int& max);
	void smooth(vector<vector<Pixel>>& image, int w, int h);
	int processimage();
	virtual ~FileProcessing(void);
};
