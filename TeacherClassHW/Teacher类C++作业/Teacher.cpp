#include "Teacher.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
Teacher::Teacher (string nn, int ss, int wy)
{
	Name=nn;
	Sex=ss;
	Workyears=wy;
}
Teacher::Teacher(Teacher &obj)
{
	Name=obj.Name;
	Sex=obj.Sex;
	Workyears=obj.Workyears;

}
Teacher& Teacher::operator =(Teacher &obj)
{
	Name=obj.Name;
	Sex=obj.Sex;
	Workyears=obj.Workyears;
	return *(this);

}
void Teacher:: Show()
{
	cout<<Name<<"  "<<Sex<<"  "<<Workyears<<"  ";

}

Teacher::~Teacher(void)
{
}