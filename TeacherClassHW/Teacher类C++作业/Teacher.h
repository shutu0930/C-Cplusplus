#pragma once
#include <iostream>
#include <string>
using namespace std;
class Teacher
{
	string Name;    //姓名
	int Sex; 			 //性别  1-男  0-女
	int Workyears;    //教龄
public:
	Teacher (string nn, int ss, int wy); 
	Teacher (Teacher & obj); 
	Teacher& operator=( Teacher & obj);
	void Show();
	~ Teacher();
};