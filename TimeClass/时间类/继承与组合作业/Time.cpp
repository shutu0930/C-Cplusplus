#include "Time.h"
#include"TTime.h"
#include"Data.h"
#include<iostream>
#include<iomanip>
using namespace std;
Time::Time(TTime &t,Data & d):ttime(t),data(d)
{
}
Time operator++(Time &a,int)
{
	Time p(a);
	int flag=0;
	a.ttime++;
	if(a.ttime.gethour()==0)
	{
		a.data++;
	}
	return p;
}
ostream& operator<<(ostream& o,const Time &t)
{
	o<<t.data<<t.ttime<<endl;
	return o;
}

Time::~Time(void)
{
}
