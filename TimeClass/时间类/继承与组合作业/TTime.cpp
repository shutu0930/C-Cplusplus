#include "TTime.h"
#include<iostream>
#include<iomanip>
using namespace std;

TTime &operator++(TTime &a)
{
	if(!(a.second=(a.second+1)%60)&&!(a.minute=(a.minute+1)%60))
		a.hour=(a.hour+1)%24;
	return a;
}
TTime operator++(TTime &a,int)
{
	TTime t(a);
	if(!(a.second=(a.second+1)%60)&&!(a.minute=(a.minute+1)%60))
		a.hour=(a.hour+1)%24;
	return t;
}
ostream & operator<<(ostream &o,const TTime& t)
{
	o<<setfill('0')<<setw(2)<<t.hour<<":"<<setw(2)<<t.minute<<":"<<setw(2)<<t.second<<"\n"<<setfill(' ');
	return o;
}
TTime::TTime(int h,int m,int s)
{
	hour=h;minute=m;second=s;
}
int& TTime::gethour()
{
	return hour;
}

TTime::~TTime(void)
{
}
