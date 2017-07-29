// 按长度排星期的单词.cpp : 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include<stdio.h>
#include<string.h>

void main()
{
	char week[7][12]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	char temp2[12];
	int num[7],i,j,temp1;
	
	for(i=0;i<7;i++)
	{
		puts(week[i]);
	
	}
	
	for(i=0;i<7;i++)
	{
		num[i]=(int)strlen(week[i]);
	}


	for(j=0;j<6;j++)
	{
		for(i=j+1;i<7;i++)					
		{
			if(num[i]<num[j])
			{
				temp1=num[i];
				num[i]=num[j];
				num[j]=temp1;
				
				strcpy(temp2,week[i]);
				strcpy(week[i],week[j]);
				strcpy(week[j],temp2);

				

			}
		}
	}
	printf("\n");

	for(i=0;i<7;i++)
	{
		puts(week[i]);
	
	}
}


