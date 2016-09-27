#pragma once
#include <string>
#include <iostream>
using namespace std;

class Vehicle
{
private:
	const char *No;
public:
	Vehicle(void);
	Vehicle(char *pNo):No(pNo){};
	//a constant member versus a ordinary member
	void ShowNo() const;
	void ShowNo();
	void ChangeNo(char *newNo);
	virtual ~Vehicle(void);
};
