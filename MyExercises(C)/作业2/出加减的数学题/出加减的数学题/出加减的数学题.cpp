// 出加减的数学题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num1,num2,num3,ques,answer,i,count=0;
	char sign;
	
	do
	{
	printf("请输入您要出的题数（1—20）：");						//输入要的题数
	scanf("%d",&ques);
	}while(ques<1||ques>20);
	

	for(i=1;i<=ques;i++)
	{
		srand((unsigned)time(NULL));
		int num1=rand()%100;							//随机出题目
		int num2=rand()%100;
		int num3=rand();
		
		if(num3%2!=0&&num1>num2)
			sign='-';
		else 
			sign='+';
		
		printf("%d.   %d%c%d=",i,num1,sign,num2);
		scanf("%d",&answer);
	
		if(sign='-'&&answer==num1-num2)					//计算正确的题数
			count++;							
		else if(sign='+'&&answer==num1+num2) 
			count++;				
	}	

	
	printf("您一共答了%d道题，答对了%d道题，答错了%d道题。",ques,count,ques-count);



}

