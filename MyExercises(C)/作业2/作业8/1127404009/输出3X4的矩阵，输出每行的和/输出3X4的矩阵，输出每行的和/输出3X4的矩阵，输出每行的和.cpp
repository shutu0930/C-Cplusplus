// ���3X4�ľ������ÿ�еĺ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num[3][4];
	int i,j,sum=0;
	
	srand((unsigned)time(NULL));
	printf("Array:\n");				//�������һ��3*4�ľ���
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=3;j++)
		{
			num[i][j]=rand()%100+1;		//���ķ�ΧΪ1--100
			printf("%5d",num[i][j]);
		
		}
		printf("\n");
	}

	for(i=0;i<=2;i++)
	{
		sum=0;
		for(j=0;j<=3;j++)			//����ÿ�еĺ�
		{
			sum+=num[i][j];
			
		}
	printf("The total of the %d line is %d\n",i+1,sum);

	
	}













}

