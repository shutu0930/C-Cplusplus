// fanxu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[100];          //定义字符串1、2
	char str2[100];

	printf("Please input a string :");
	gets(str1);                 //输入字符串1

	int i,j,k;
	for(i=0;i<=99;i++)             //计算字符串1的长度
	{
		if(str1[i]=='\0')
			break;
	}

	for(j=0;j<=i-1;j++)                    //将字符串1反序
	{
		
			str2[j]=str1[i-1-j];
			
		
	}

	str2[j]='\0';                  
	
	

	puts(str2);    //输出反序后的字符串
	
	return 0;
}

