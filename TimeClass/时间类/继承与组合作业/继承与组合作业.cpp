// 继承与组合作业.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"TTime.h"
#include"Data.h"
#include"Time.h"
#include<iostream>
#include<iomanip>
using namespace std;
void main()
{
	TTime t(23,59,59);
	Data d(2012,5,4);
	Time tt(t,d);
	tt++;
	cout<<tt<<endl;
	

	
}

