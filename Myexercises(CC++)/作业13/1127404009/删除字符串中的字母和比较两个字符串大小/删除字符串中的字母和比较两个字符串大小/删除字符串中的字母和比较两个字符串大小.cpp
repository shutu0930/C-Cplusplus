// ɾ���ַ����е���ĸ�ͱȽ������ַ�����С.cpp : �������̨Ӧ�ó������ڵ㡣
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
	printf("Please input the first string :\n");			//�����ַ���1
	gets(str1);
	printf("Please input a character to delete:");			//����Ҫɾ������ĸ
	ch=getchar();

	delfromstr(str1,ch);									//���ú���ɾ����ĸ

	printf("Please input the second string :\n");
	
	gets(str2);												//�����ַ���2
	gets(str2);

	printf("The first string %c The second string\n",sstrcmp(str1,str2));		//����ַ����ȽϽ��


}
//===================================
//����������ɾ���ַ����е�ָ����ĸ
//����˵����char str[]����һ���ַ���
//			char ch ����Ҫɾ������ĸ
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
//����������ɾ���ַ����е�ָ����ĸ
//����˵����char str1[]����һ���ַ���
//			char str1[]������һ���ַ���
//����ֵ��'>','<','='
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
