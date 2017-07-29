// 随机产生题目.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num1,num2,ques,answer,i,count=0;
	printf("请输入您要出的题数：");						//输入要的题数
	scanf("%d",&ques);



	for(i=1;i<=ques;i++)
	{
		srand((unsigned)time(NULL));
		int num1=rand()%100;							//随机出题目
		int num2=rand()%100;
		printf("%d.   %d+%d=",num1,num2);
		scanf("%d",&answer);
		

		if(answer==num1+num2) 
			count++;								//计算正确的题数
		
		
		
	
	
	
	}
	
	printf("您一共答了%d道题，答对了%d道题，答错了%d道题。",ques,count,ques-count);



}

