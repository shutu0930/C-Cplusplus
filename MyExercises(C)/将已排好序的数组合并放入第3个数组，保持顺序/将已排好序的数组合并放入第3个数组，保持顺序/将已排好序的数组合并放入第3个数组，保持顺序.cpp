// �����ź��������ϲ������3�����飬����˳��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 15

void main()
{
	void sort(int num[],int n);
	int num1[N],num2[N],num3[2*N]={0};
	int i,j,temp;
	
	srand((unsigned)time(NULL));
	printf("Please input the first array :\n");
	
	int flag1[25]={0};
	for(i=0;i<N;)
	{
		//scanf("%d ",num1[i]);
		num1[i]=rand()%25+1;
		if(flag1[num1[i]-1]!=1)				//�����ֵ��Ϊ1����˵����������ǰ���κ����ظ�
			{	
				flag1[num1[i]-1]=1;				//ʹ���ֵΪ1
				i++;						//j+1ʹѭ������
				
			}
	}
	
	sort(num1,N);
	
	printf("\nThe second array :\n");
	
	int flag2[30]={0};
	
	for(i=0;i<N;)
	{
		//scanf("%d ",num2[i]);
		num2[i]=rand()%30+1;
		if(flag2[num2[i]-1]!=1)				//�����ֵ��Ϊ1����˵����������ǰ���κ����ظ�
			{	
				flag2[num2[i]-1]=1;				//ʹ���ֵΪ1
				i++;						//j+1ʹѭ������
				
			}
	}
	
	sort(num2,N);

	printf("\n");
	for(i=0;i<N;i++)
	{
		num3[i]=num1[i];
	
	}

	





	
	

}

void sort(int num[],int n)
{
	int i,j,temp;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(num[i]>num[j])
			{
				temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",num[i]);
	}
	
}
void merge()
{
	int i,j;
	
	for(j=0;j<N;j++)
	{
		for(i=N-1;i>=0;i--)
		{
			
			if(num2[j]<num3[i])
			{
				num3[i+1]=num3[i];
			}
			
			else if(num2[j]>num3[i])
			{
				num3[i+1]=num2[j];
			}
		
		}
		
	
	}
	

	for(i=0;i<2*N;i++)
	{
		printf("%d ",num3[i]);
	
	}




}