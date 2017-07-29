// 十六进制转换为十进制.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 15

void main()
{
	char num[N];

	int transform(char num[]);

	printf("请输入一个十六进制的数：\n");

	gets(num);

	printf("将其转换为十进制为：\n%d\n",transform(num));

}
int transform(char num[])
{
	int i,len,place,numd=0;

	len=strlen(num);

	for(i=0;i<len;i++)
	{
		if(num[i]>='0'&& num[i]<='9')
		{
			place=num[i]-'0';
		}
		else if(num[i]>='a'&& num[i]<='f')
		{
			place=num[i]-'a'+10;
		}
		else if(num[i]>='A'&& num[i]<='F')
		{
			place=num[i]-'A'+10;
		}
		numd+=(int)pow(16.0,(len-i-1)*1.0)*place;
	
	}
	
	return numd;





}

