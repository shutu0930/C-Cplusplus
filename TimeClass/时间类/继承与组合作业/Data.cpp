#include "Data.h"
#include<iostream>
#include<iomanip>
using namespace std;

Data &operator++(Data &a)
{
	int days;
	switch(a.month)
	{
		case(2):
				if((a.year%4==0&&a.year%100!=0)||(a.year%400==0)) 
					days=29;
				else 
					days=28;
				break;
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):days=31;break;
		default:days=30;
	}
	if(!(a.day=(a.day+1)%days)&&!(a.month=(a.month+1)%12))
		a.year=a.year+1;
	return a;
}

Data operator++(Data &a,int)
{
	Data t(a);
	int days;
	switch(a.month)
	{
		case(2):
				if((a.year%4==0&&a.year%100!=0)||(a.year%400==0)) 
					days=29;
				else 
					days=28;
				break;
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):days=31;break;
		default:days=30;
	}
	if(!(a.day=(a.day+1)%days)&&!(a.month=(a.month+1)%12))
		a.year=a.year+1;
	return t;
}
ostream & operator<<(ostream &o,const Data& t)
{
	o<<setw(4)<<t.year<<'-'<<setw(2)<<t.month<<'-'<<setw(2)<<t.day<<"\n"<<setfill(' ');
	return o;
}
Data::Data(int y,int m,int d)
{
	year=y;month=m;day=d;
}

Data::~Data(void)
{
}