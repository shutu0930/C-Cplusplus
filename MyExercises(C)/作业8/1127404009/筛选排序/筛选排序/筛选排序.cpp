// ɸѡ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num[10];							//��������
	int i,j,temp;
	srand((unsigned)time(NULL));
	
	printf("Before being sorted the integers:\n");	//�������10��Ҫ���е�����
	
	for(i=0;i<=9;i++)
	{
		num[i]=rand();			//10���������θ����������10����
		printf("%d,",num[i]);
	}
	printf("\n");

	for(j=0;j<=8;j++)
	{
		for(i=0;i<=8-j;i++)					//ɸѡ���򷨣�����������
		{
			if(num[i+j+1]<num[j])
			{
				temp=num[i+j+1];
				num[i+j+1]=num[j];
				num[j]=temp;
			}
		}
	}
	
	printf("After being sorted the integers:\n");	
	
	for(i=0;i<=9;i++)						//�������������
	{
		printf("%d,",num[i]);
	}

	printf("\n");

}

