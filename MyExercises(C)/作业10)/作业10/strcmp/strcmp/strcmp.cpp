// strcmp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[100];        //���������ַ���
	char str2[100];

	printf("Please input a string:");                   //�����ַ���1��2
	gets(str1);
	printf("Please input another string to compare:");
	gets(str2);


	int i,j,k=0;

	for(i=0;i<=99;i++)             //�ֱ�����ַ���1��2�ĳ���
	{
		if(str1[i]=='\0')
			break;
	}
	
	for(j=0;j<=99;j++)
	{
		if(str1[j]=='\0')
			break;
	}	

	if(i==j)                                  //�ַ����������ʱ�Ƚϴ�С
	{
		while(str1[k]==str2[k])
		{
			k++;
			if(str1[k]=='\0')
				break;

		}

		if(k==i)
			printf("The two strings equal.");   //������
		else
		{
			if(str1[k]>str2[k])
				printf("1st string > 2nd string");
			else
				printf("1st string < 2nd string");
		}
	}

	if(i>j)                      //�ַ���1���ַ���2��ʱ�Ƚϴ�С
	{
		while(str1[k]==str2[k])
		{
			k++;
			if(str1[k]=='\0')
				break;
		}

		if(k==j)
			printf("1st string > 2nd string");
		else
		{
			if(str1[k]>str2[k])
				printf("1st string > 2nd string");
			else
				printf("1st string < 2nd string");
		}


	}


	if(i<j)             //�ַ���2���ַ���1��ʱ�Ƚϴ�С
	{
		while(str1[k]==str2[k])
		{
			k++;
			if(str1[k]=='\0')
				break;
		}

		if(k==i)
			printf("1st string < 2nd string");
		else
		{
			if(str1[k]>str2[k])
				printf("1st string > 2nd string");
			else
				printf("1st string < 2nd string");
		}
	}
	
	
	
	return 0;
}

