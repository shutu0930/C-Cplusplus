// ɾ���ַ�����ָ�����ַ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 50

void main()
{
	char *strdelchar(char *pstr,char ch);
	char str[N],ch,*pstr=str;				//����ָ���������ʼ��
	
	printf("Please input a string :\n");		
	
	gets(str);								//�����ַ���
	printf("Please input a character to delete :\n");
	ch=getchar();							//����Ҫɾ�����ַ�

	printf("After being deleted :\n");

	puts(strdelchar(pstr,ch));				//����������ַ�
	printf("\n");
}

//==========================================
//����������ɾ���ַ�����ָ�����ַ�
//����˵����char *pstr,char ch
//����ֵ���������������ַ������׵�ַ
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

	return pstr;				//���ؾ������������ַ������׵�ַ


}

