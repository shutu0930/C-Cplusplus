#pragma once
#include"TTime.h"
#include"Data.h"
#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
	TTime ttime;
	Data data;
public:
	
	Time(TTime &t,Data & d);
	friend Time operator++(Time &a,int);
	friend ostream& operator<<(ostream& o,const Time &t);

	~Time(void);
};
