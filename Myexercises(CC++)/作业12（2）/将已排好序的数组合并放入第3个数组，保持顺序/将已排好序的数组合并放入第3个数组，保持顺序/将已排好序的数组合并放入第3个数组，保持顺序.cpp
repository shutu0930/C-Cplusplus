// �����ź��������ϲ������3�����飬����˳��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5

void main()
{
	void produce(int num[],int k);						//��������
	void merge(int num1[],int num2[],int num3[]);
	
	int num1[N],num2[N],num3[2*N];
	
	printf("The first array :\n");						//���ú���������һ������
	
	produce(num1,35);
	
	printf("\nThe second array :\n");					
	
	produce(num2,25);									//���ú��������ڶ�������
	
	printf("\n");
	
	printf("The merged array:\n");
	merge(num1,num2,num3);
	printf("\n");
	
}
//========================================
//	���������ڲ���һ�����鲢��������
//	����˵����int num[]����һ������ 
//	int n����һ������������Ԫ�صķ�Χ
//========================================
void produce(int num[],int k)
{
	void sort(int num[]);
	
	int i,n,flag[35]={0};
	srand((unsigned)time(NULL));
	for(i=0;i<N;)
	{
		/*scanf("%d,",&num[i]);*/
		n=num[i]=rand()%k+1;
		if(flag[n-1]!=1)							//�����ֵ��Ϊ1����˵����������ǰ���κ����ظ�
			{	
				flag[n-1]=1;						//ʹ���ֵΪ1
				i++;								//i+1ʹѭ������
				
			}
	}
	
	sort(num);



}
//================================
//	���������ڽ���������
//	����˵����int num[]����һ������
//================================

void sort(int num[])
{
	int i,j,temp;

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
		printf("%d  ",num[i]);
	
	}
	
}
//==========================================
//	���������ڽ�һ��������������һ��������
//	����˵����int num����һ������ 
//	int num3[]����һ����
//==========================================
void merge(int num1[],int num2[],int num3[])
{
	int i,j,k;
	i=j=k=0;
	
	while(i<N&&j<N)
	{
		if(num1[i]<num2[j])
		{
			num3[k]=num1[i];
			i++;
		}
		else if(num1[i]>num2[j])
		{
			num3[k]=num2[j];
			j++;
		}
		else
		{
			num3[k]=num1[i];
				j++;
				i++;
		}
		k++;
	}
	
	while(i<N)
	{
		num3[k]=num1[i];
			i++;
			k++;
	
	}
	while(j<N)
	{
		num3[k]=num2[j];
			j++;
			k++;
	
	}
	
	
	for(i=0;i<k;i++)
	{
		printf("%d  ",num3[i]);
	
	}

	
		
}




