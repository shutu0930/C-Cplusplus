// ���㳤�ȵĺ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
void main()
{
	char str[50];
	int count=0;
	
	gets(str);

	while(str[count]!=0)
	{
		count++;
	}

	printf("��%d����Ч�ַ���\n",count);

}

