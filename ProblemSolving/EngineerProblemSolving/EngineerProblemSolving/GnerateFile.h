#pragma once
#include "fileprocessing.h"
using namespace std;

class GnerateFile : public FileProcessing
{
public:
	GnerateFile(void);
	int GenerateBallonData(string outfile);
	int Accessmemory();
	int AccessString(char str1[],char str2[]);
	virtual ~GnerateFile(void);
};
