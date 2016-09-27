#include "StdAfx.h"
#include "Vehicle.h"
#include <string>
#include <iostream>
using namespace std;

Vehicle::Vehicle(void)
{
}

void Vehicle::ShowNo() const
{
	cout<<"the const No of the Vehicle"<<No<<endl;
}

void Vehicle::ShowNo()
{
	cout<<"the No of the Vehicle"<<No<<endl;
}

void Vehicle::ChangeNo(char *newNo)
{
	No = newNo;
}

Vehicle::~Vehicle(void)
{
}
