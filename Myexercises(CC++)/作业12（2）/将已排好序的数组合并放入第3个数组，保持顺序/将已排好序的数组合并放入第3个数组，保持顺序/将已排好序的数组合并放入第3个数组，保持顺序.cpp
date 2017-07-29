// 将已排好序的数组合并放入第3个数组，保持顺序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5

void main()
{
	void produce(int num[],int k);						//函数声明
	void merge(int num1[],int num2[],int num3[]);
	
	int num1[N],num2[N],num3[2*N];
	
	printf("The first array :\n");						//调用函数产生第一个数组
	
	produce(num1,35);
	
	printf("\nThe second array :\n");					
	
	produce(num2,25);									//调用函数产生第二个数组
	
	printf("\n");
	
	printf("The merged array:\n");
	merge(num1,num2,num3);
	printf("\n");
	
}
//========================================
//	本函数用于产生一个数组并将其排序
//	参数说明：int num[]传入一个数组 
//	int n传入一整数控制数组元素的范围
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
		if(flag[n-1]!=1)							//若标记值不为1，则说明该数不与前面任何数重复
			{	
				flag[n-1]=1;						//使标记值为1
				i++;								//i+1使循环进行
				
			}
	}
	
	sort(num);



}
//================================
//	本函数用于将数组排序
//	参数说明：int num[]传入一个数组
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
//	本函数用于将一个整数插入排序到一个数组中
//	参数说明：int num传入一个整数 
//	int num3[]传入一数组
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




