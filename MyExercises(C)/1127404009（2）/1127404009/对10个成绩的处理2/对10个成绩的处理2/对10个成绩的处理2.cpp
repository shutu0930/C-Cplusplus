// ��10���ɼ��Ĵ���2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

void main()
{
	float num[N];
	int i;
	
	void sort(float num[]);
	srand((unsigned)time(NULL));
	printf("10����ί��ѡ�ֵ����֣�\n");
	for(i=0;i<N;i++)
	{
		num[i]=(float)(rand()%10000+1)*0.01;
		printf("%.2f  ",num[i]);
	
	}
	printf("\n�����ĳɼ���\n");

	sort(num);
	
}

void sort(float num[])
{
	int i,j;
	float temp;
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(num[i]>num[j])
			{
				temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			
			}
		
		}
	
	}
	for(i=0;i<N;i++)
	{
		printf("%.2f  ",num[i]);
	
	}
	printf("\n");
}

