// 将两个已排好序的数组合并到一个数组中.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#define N 5

void main()
{
	int i,j,temp1,temp2,end;
	int num=12,num3[6]={1,2,6,10,15};
	
		for(j=0;j<N-1;j++)	
		{
			end=num3[N-1];
			if(num>end)
				end=num;
			else 
			{
				for(i=0;i<N;i++)
				{
					if(num3[i]>num)
					{
						temp1=num3[i];
						num3[i]=num;

						for(j=i+1;j<N+1;j++)
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

		for(i=0;i<6;i++)
		{
			printf("%d ",num3[i]);
		
		}
}		