#pragma once
#include "Teacher.h"
#include <iostream>
#include <string>
using namespace std;
class UniversityTeacher :public Teacher
{
	int Workgrade;
public:
	UniversityTeacher(string name="Mike",int sex=1,int workyears=5,int workgrade=7);
	UniversityTeacher(UniversityTeacher &obj);
	friend UniversityTeacher& operator++(UniversityTeacher& ut);
	friend UniversityTeacher operator++(UniversityTeacher& ut,int);
	void Show();
	~UniversityTeacher(void);
};
