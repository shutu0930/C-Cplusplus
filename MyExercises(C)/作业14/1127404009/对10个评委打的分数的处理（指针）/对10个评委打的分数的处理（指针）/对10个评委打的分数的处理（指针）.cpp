// ��10����ί��ķ����Ĵ���ָ�룩.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#define N 10

void main()
{
	float max_min_aver(float *pnum,float *pmax,float *pmin,int n);

	float num[N],max,min,*p=num,*pmax=&max,*pmin=&min;
	int i;

	printf("Please input 10 scores :\n");					//����10����ί�Ĵ��

	for(i=0;i<10;i++)
	{
		scanf("%f,",p++);
	}
	p=num;

	printf("The max_score is :%.3f\nThe min_score is :%.3f\nThe average_score is :%.3f\n",*pmax,*pmin,max_min_aver(p,pmax,pmin,N-2));

															//���ú�����ָ�������߷���ͷֺ�ȥ�������ͷֵ�ƽ��ֵ



}
//==================================================================
//�����������ҳ������е����ֵ����Сֵ�����ȥ�������Сֵ���ƽ����
//����˵����float *p,float *pmax,float *pmin,int n
//==================================================================

float max_min_aver(float *p,float *pmax,float *pmin,int n)
{
	int i;
	float aver,sum=0;
	*pmax=*pmin=*p;					//��ʼ��ָ�����

	for(i=0;i<N;i++)
	{
		sum+=*(p+i);				//���
		if(*pmax<*(p+i))			//����ָ���������Сֵ
			*pmax=*(p+i);
		if(*pmin>*(p+i))
			*pmin=*(p+i);
	}

	aver=(sum-*pmax-*pmin)/(N-2);

	return aver;



}