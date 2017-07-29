// 第三题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<string.h>
#define N 20
void change(FILE *fp);

void main()
{
	FILE *fp;
	char filename[N];
	printf("Please input the filename to output data :\n");
	gets(filename);
	fp=fopen(filename,"w");
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	change(fp);
	fclose(fp);
}
void change(FILE *fp)
{
	char ch;
	ch=getchar();
	printf("Please enter a string to save in the disk (end with '!'):\n");
	ch=getchar();
	while(ch!='!')
	{
		
		if(ch>='a'||ch<='z')
		{
			ch-=32;
		}
		fputc(ch,fp);
		putchar(ch);
		ch=getchar();
	}
	
	putchar('\n');

}