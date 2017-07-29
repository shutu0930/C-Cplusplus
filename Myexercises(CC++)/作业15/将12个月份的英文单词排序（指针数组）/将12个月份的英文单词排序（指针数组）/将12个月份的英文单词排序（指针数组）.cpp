// 将12个月份的英文单词排序（指针数组）.cpp : 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include<stdio.h>
#include<string.h>

void sort(char *month[]);
void main()
{
	char *month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int i;											//定义指针数组
	
	for(i=0;i<12;i++)
	{
		puts(month[i]);								//输出12个月份的单词
	
	}
	
	
	
	
	printf("\n按单词长度从大到小排序：\n");

	sort(month);									//调用函数对指针数组处理

	for(i=0;i<12;i++)
	{
		puts(month[i]);								//输出排好序的12个月份的单词
	
	}

	
}

//===========================================
//本函数用于将12个月的单词按长度从大到小排序
//参数说明：char *month[]指针数组
//===========================================
void sort(char *month[])
{
	int num[12],i,j,temp1;
	char *temp2;

	for(i=0;i<12;i++)
		{
			num[i]=(int)strlen(month[i]);
		}


		for(j=0;j<11;j++)
		{
			for(i=j+1;i<12;i++)					
			{
				if(num[i]<num[j])
				{
					temp1=num[i];
					num[i]=num[j];
					num[j]=temp1;
					
					temp2=month[i];
					month[i]=month[j];
					month[j]=temp2;
				}
			}
		}

}


