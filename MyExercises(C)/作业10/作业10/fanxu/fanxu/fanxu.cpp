// fanxu.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[100];          //�����ַ���1��2
	char str2[100];

	printf("Please input a string :");
	gets(str1);                 //�����ַ���1

	int i,j,k;
	for(i=0;i<=99;i++)             //�����ַ���1�ĳ���
	{
		if(str1[i]=='\0')
			break;
	}

	for(j=0;j<=i-1;j++)                    //���ַ���1����
	{
		
			str2[j]=str1[i-1-j];
			
		
	}

	str2[j]='\0';                  
	
	

	puts(str2);    //����������ַ���
	
	return 0;
}

