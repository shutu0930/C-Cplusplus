// Teacher��C++��ҵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "UniversityTeacher.h"
#include <iostream>
using namespace std;

void main()
{
	UniversityTeacher t1;
	UniversityTeacher t2(t1);
	t1.Show();
	t2.Show();
	t2=t1++;
	t1.Show();
	t2.Show();
	t2=++t1;
	t1.Show();
	t2.Show();
}

