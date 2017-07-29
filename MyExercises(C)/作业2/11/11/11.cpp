// 11.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct StudentInfo)
struct StudentInfo

{
	char xh[12];	//学号
	char xm[12];	//姓名
	int  sex;		//性别0-表示女生1-表示男生
	int  dycj;		//德育成绩
	int  zycj;		//智育成绩
	int  tycj;		//体育成绩
	double zhcjpji; //综合测评成绩
	struct StudentInfo *next;
};

void main()
{
	FILE *fp;
	struct StudentInfo temp[59];

	int count=0;
	fp=fopen("D:\\in.dat","rb");
	
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	
	while(fread(&temp[0],LEN-8,1,fp)==1)
	{
		printf("%s%s\n",temp[0].xh,temp[0].xm);
		count++;
		
	}
	fclose(fp);
}

