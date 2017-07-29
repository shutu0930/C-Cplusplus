// 将已排好序的数组合并放入第3个数组，保持顺序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5

void main()
{
	void sort(int num[]);
	void merge(int num,int num3[]);
	int num1[N],num2[N],num3[2*N]={0};
	int i;
	
	srand((unsigned)time(NULL));
	printf("Please input the first array :\n");
	
	for(i=0;i<N;i++)
	{
		//scanf("%d ",num1[i]);
		num1[i]=rand()%25+1;
	}
	
	sort(num1);
	
	printf("\nThe second array :\n");
	
	int flag2[30]={0};
	
	for(i=0;i<N;i++)
	{
		//scanf("%d ",num2[i]);
		num2[i]=rand()%30+1;
	}
	
	sort(num2);

	printf("\n");
	for(i=0;i<N;i++)
	{
		num3[i]=num2[i];
		
	}
	printf("The merged array:\n");
	for(i=0;i<N;i++)
	{
		merge(num1[i],num3);
		
	}
	for(i=0;i<2*N;i++)
	{
		if(num3[i]!=0)
			printf("%d  ",num3[i]);
	
	}
	printf("\n");
	
}

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
void merge(int num,int num3[])
{
	int i,j,temp1,temp2,end;
	static int n=3;
	
	
		for(j=0;j<2*N;j++)	
		{
			if(num==num3[j])
			{	num=0;
				break;
			}
		
		}

		for(j=0;j<2*N;j++)
		{	
			
			 if(num!=0)
				{	
					n++;
					end=num3[n];
					if(num>end)
						num3[n]=num;
					else 
					{
						for(i=0;i<2*N-1;i++)
						{
							if(num3[i]>num)
							{
								temp1=num3[i];
								num3[i]=num;

								for(j=i+1;j<2*N;j++)
								{
									temp2=num3[j];
									num3[j]=temp1;
									temp1=temp2;
								
								}
							
								break;
							}
						}
					}
				}
		}
		
}
