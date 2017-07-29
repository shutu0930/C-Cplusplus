// ltrim和rtrim(指针).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 50
void main()
{
	char *trim(char *pstr,int *plen);
	char str[N],*pstr=str;				//定义指针变量并初始化
	int len,*plen=&len;
	
	printf("Please input some words:\n");
	gets(str);

	len=(int)strlen(str);
	printf("Before trimmed the length is :%d\n",*plen);
	
	trim(pstr,plen);					//调用trim函数
	printf("After being trimmed the words are :\n%s\nThe length is :%d\n",trim(pstr,plen),*plen);

}

//===========================================
//本函数用于删除字符数组中开头和结尾的空格符
//参数说明：char *pstr,int *plen
//返回值：trim后的字符串首地址
//===========================================
char *trim(char *pstr,int *plen)
{
	int i,j;
	
	for(i=0;i<*plen;i++)				//用于删除字符串开头的空格符
	{
		if(*(pstr+i)!=' ')
		{
			strcpy(pstr,pstr+i);
			break;
		}
		
	}
	
	for(j=*plen-1-i;j>=0;j--)			//用于删除字符串结尾的空格符
	{
		if(*(pstr+j)!=' ')
		{
			*(pstr+j+1)=0;
			break;
		}
	}
	*plen=(int)strlen(pstr);
	return pstr;						//返回trim后的字符串首地址


}