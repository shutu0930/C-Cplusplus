#pragma once
#include <iostream>
#include <string>
using namespace std;
class Teacher
{
	string Name;    //����
	int Sex; 			 //�Ա�  1-��  0-Ů
	int Workyears;    //����
public:
	Teacher (string nn, int ss, int wy); 
	Teacher (Teacher & obj); 
	Teacher& operator=( Teacher & obj);
	void Show();
	~ Teacher();
};