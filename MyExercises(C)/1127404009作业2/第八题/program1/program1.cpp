// program1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>

void main()
{
	int mark;
	char grade;
	printf("Please input the mark:");
	scanf("%d",&mark);

	while(mark>100||mark<0)		//�������ʱ�������룬ֱ�����Ϊֹ
	{
	printf("Enter data error!Please reput the mark:");
	scanf("%d",&mark);
	}
	
	if(mark>90&&mark<100)		//if��䰴�ȼ�����
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
	
	

