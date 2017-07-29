#pragma once
#include "Data.h"
#include<iostream>
using namespace std;
class Data
{
	int year,month,day;

public:
	Data(int y,int m,int d);
	friend Data& operator++(Data &a);
	friend Data operator++(Data &a,int);
	friend ostream& operator<<(ostream& o,const Data &t);
	friend class Time;
	~Data(void);
};