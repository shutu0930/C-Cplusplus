// 删除字符串中的字母和比较两个字符串大小.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#define N 50
#include<string.h>
void main()
{
	char str1[N],str2[N],ch;

	void delfromstr(char str[],char ch);
	int sstrcmp(char str1[],char str2[]);
	printf("Please input the first string :\n");			//输入字符串1
	gets(str1);
	printf("Please input a character to delete:");			//输入要删除的字母
	ch=getchar();

	delfromstr(str1,ch);									//调用函数删除字母

	printf("Please input the second string :\n");
	
	gets(str2);												//输入字符串2
	gets(str2);

	printf("The first string %c The second string\n",sstrcmp(str1,str2));		//输出字符串比较结果


}
//===================================
//本函数用于删除字符串中的指定字母
//参数说明：char str[]传入一个字符串
//			char ch 传入要删除的字母
//===================================
void delfromstr(char str[],char ch)
{
	int i,j,len;

	len=strlen(str);

	for(i=j=0;i<len;i++)
	{
		if(str[i]!=ch)
		{
			str[j++]=str[i];
		
			/*strcpy(str+i,str+i+1);*/
		}
	}
	str[j]=0;
	printf("After deleting the string is :\n");
	puts(str);

}

//======================================
//本函数用于删除字符串中的指定字母
//参数说明：char str1[]传入一个字符串
//			char str1[]传入另一个字符串
//返回值：'>','<','='
//======================================
int sstrcmp(char str1[],char str2[])
{
	int len1,len2,len,i;

	len1=strlen(str1);
	len2=strlen(str2);
	len=len1>len2?len2:len1;

	for(i=0;i<len+1;i++)
	{
		if(str1[i]>str2[i])
		{
			return '>';
			break;
		}else if(str1[i]<str2[i])
		{
			return '<';
			break;
		}	
	}
	if(i>len)
		return '=';
}
