#include "UniversityTeacher.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
UniversityTeacher::UniversityTeacher(string name,int sex,int workyears,int workgrade):Teacher(name,sex,workyears)
{
	Workgrade=workgrade;

}
UniversityTeacher::UniversityTeacher(UniversityTeacher &obj):Teacher(obj)
{
	
	Workgrade=obj.Workgrade;

}
UniversityTeacher& operator++(UniversityTeacher& ut)
{
	++(ut.Workgrade);
	return ut;
}
UniversityTeacher operator++(UniversityTeacher& ut,int)
{
	UniversityTeacher put(ut);
	++(ut.Workgrade);
	return put;

}
void UniversityTeacher::Show()
{
	Teacher::Show();
	cout<<Workgrade<<endl;
}
UniversityTeacher::~UniversityTeacher(void)
{
}
