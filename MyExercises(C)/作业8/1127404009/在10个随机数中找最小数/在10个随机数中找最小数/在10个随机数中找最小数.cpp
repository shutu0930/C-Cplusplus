// ��10�������������С��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num[10];						//������������
	int i,j=1,sum,min;
	float aver;
	
	srand((unsigned)time(NULL));
	for(i=0;i<=9;i++)
	{
		num[i]=rand();
		printf("%d\n",num[i]);			//�������10�����������Ƿֱ𸳸�����ĸ���Ԫ��
	
	}
	min=num[0];
	sum=num[0];
	for(i=1;i<=9;i++)					//�����Сֵ
	{
		if(num[i]<min)
		{
			j=i+1;						//j��ֵΪ��Сֵ������
			min=num[i];
		}
	
	sum+=num[i];						//��10�����ĺ�
	
	
	}

	aver=(float)sum/10;					//����10������ƽ��ֵ
	
	printf("��СֵΪ%d���ǵ�%d��������10������ƽ��ֵΪ%.1f\n",min,j,aver);


	






}

