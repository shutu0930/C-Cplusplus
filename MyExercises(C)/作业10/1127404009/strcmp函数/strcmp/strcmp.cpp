// strcmp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 100
void main()
{
	char str1[N];										//���������ַ���
	char str2[N];

	printf("Please input a string:");                   //�����ַ���1��2
	gets(str1);
	printf("Please input another string to compare:");
	gets(str2);


	int i,j,k=0;

	i=strlen(str1);	
	j=strlen(str2);									//�ֱ�����ַ���1��2�ĳ���
	

	if(i==j)										//�ַ����������ʱ�Ƚϴ�С
	{
		while(str1[k]==str2[k])
		{
			k++;
			if(str1[k]=='\0')
				break;

		}

		if(k==i)
			printf("The two strings equal.");			//������
		else
		{
			if(str1[k]>str2[k])
				printf("1st string > 2nd string");
			else
				printf("1st string < 2nd string");
		}
	}

	if(i>j)											//�ַ���1���ַ���2��ʱ�Ƚϴ�С
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


	if(i<j)											//�ַ���2���ַ���1��ʱ�Ƚϴ�С
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
	
	
	
}

