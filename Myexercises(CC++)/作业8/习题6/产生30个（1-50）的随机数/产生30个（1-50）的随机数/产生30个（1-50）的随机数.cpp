// ����30����1-50���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num[30];
	int i=0;

	srand((unsigned)time(NULL));
	num[i]=rand()%50+1;
	do
	{
		i+=1;
		num[i]=rand()%50+1;
		printf("%d,",num[i]);
	
	}while(num[i]!=num[i-1]);










}

