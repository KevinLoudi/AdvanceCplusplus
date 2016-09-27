#pragma once

class Stduent
{
private:
	int No;
	char Name[16];
	int Score;
	//enable class counsellor to access private member of Student
	friend class Counsellor;
	friend void assess_compare(Stduent &s1, Stduent &s2);
public:
	Stduent(void);
	Stduent(int no,char *name);
	void print();
	virtual ~Stduent(void);
};

class Counsellor
{
	private:
		int No;
		char Name[16];
	public:
		Counsellor(int no,char *name);
		void assess(Stduent &s,int assessed_score);
		void assess_compare(Stduent &s1, Stduent &s2);
		~Counsellor();
};

class Commodity
{
	private:
		char No[10];
		char Name[8];
		float Price;
	public:
		Commodity();
		Commodity(char *cNo,char *cName,float cPrice=0);
		void PriceInfo();
		~Commodity();
};