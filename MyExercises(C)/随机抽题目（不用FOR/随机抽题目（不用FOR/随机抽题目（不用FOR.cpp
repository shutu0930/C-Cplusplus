// 随机抽题目（不用FOR.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num1,num2,ques,answer,i=1,count=0;
	printf("请输入您要出的题数：");							//输入要的题数
	scanf("%d",&ques);



	while(i<=ques)
	{
		srand((unsigned)time(NULL));						//随机出题目
		int num1=rand()%100;
		int num2=rand()%100;
		printf("%d.  %d+%d=",i,num1,num2);
		scanf("%d",&answer);
		i++;

		if(answer==num1+num2)								//计算正确的题数
			count++;
	
	
	}
	
	
	printf("您一共答了%d道题，答对了%d道题，答错了%d道题。",ques,count,ques-count);



}

