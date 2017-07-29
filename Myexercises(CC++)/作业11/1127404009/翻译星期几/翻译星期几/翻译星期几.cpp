// 翻译星期几.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>

void main()
{
	char week1[7][12]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	char week2[]="一二三四五六日";
	char week3[12];
	int i;

	printf("Please input a name of week :\n");
	gets(week3);

	for(i=0;i<7;i++)
	{
		if(strcmp(week3,week1[i])==0)
			break;
	}
	printf("Translate it into Chinese is :\n星期%c%c\n",week2[2*i],week2[2*i+1]);

}

