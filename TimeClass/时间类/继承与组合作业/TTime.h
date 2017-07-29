#pragma once
#include "TTime.h"
#include<iostream>
using namespace std;
class TTime
{
	int hour,minute,second;

public:
	TTime(int h,int m,int s);
	
	friend TTime& operator++(TTime &a);
	friend TTime operator++(TTime &a,int);
	friend ostream& operator<<(ostream& o,const TTime &t);
	int& gethour();
	friend class Time;
	~TTime(void);
};
