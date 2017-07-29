// 文件加密改进.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 100

int main()
{
	FILE *fp;
	char filename1[N];
	printf("Please input the filename1 :\n");
	gets(filename1);
	fp=fopen(filename1,"r");
	if(fp==NULL)
	{
		printf("Can't open the file!\n");
		return -1;
	
	
	}
	FILE *fpout;
	char filename2[N];
	printf("Please input the filename2 :\n");
	gets(filename2);
	fp=fopen(filename2,"w");
	if(fpout==NULL)
	{
		printf("Can't open the file!\n");
		return -1;
	
	}
	char ch,temp=0X80;

	while(feof(fp)==0)
	{
		ch=fgetc(fp);
		if(ch!=EOF)
		{
			putchar(ch);
			ch=ch^temp;
			fputc(ch,fpout);
		
		}
	
	}
	fclose(fp);
	fclose(fpout);
	
	return 0;
}

