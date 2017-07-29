// 删除字符串中指定的字符.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 50

void main()
{
	char *strdelchar(char *pstr,char ch);
	char str[N],ch,*pstr=str;				//定义指针变量并初始化
	
	printf("Please input a string :\n");		
	
	gets(str);								//输入字符串
	printf("Please input a character to delete :\n");
	ch=getchar();							//输入要删除的字符

	printf("After being deleted :\n");

	puts(strdelchar(pstr,ch));				//输出处理后的字符
	printf("\n");
}

//==========================================
//本函数用于删除字符串中指定的字符
//参数说明：char *pstr,char ch
//返回值：经函数处理后的字符串的首地址
//=========================================
char *strdelchar(char *pstr,char ch)
{
	int i,j;
	for(i=j=0;*(pstr+i)!='\0';i++)		
	{
		if(*(pstr+i)!=ch)
		{
			*(pstr+j)=*(pstr+i);
			j++;
		}
	}
	*(pstr+j)='\0';

	return pstr;				//返回经函数处理后的字符串的首地址


}

