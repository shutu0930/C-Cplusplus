// program1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

void main()
{
	int mark;
	char grade;
	printf("Please input the mark:");
	scanf("%d",&mark);

	while(mark>100||mark<0)		//输入错误时重新输入，直到输对为止
	{
	printf("Enter data error!Please reput the mark:");
	scanf("%d",&mark);
	}
	
	if(mark>90&&mark<100)		//if语句按等级分类
	grade='A';
	if(mark>80&&mark<89)
	grade='B';
	if(mark>70&&mark<79)
	grade='C';
	if(mark>60&&mark<69)
	grade='D';
	if(mark<60)
	grade='E';
	
	printf("When the mark is %d,the grade is %c\n",mark,grade);
}	
	
	

