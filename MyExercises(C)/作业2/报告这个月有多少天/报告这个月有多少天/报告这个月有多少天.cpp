// 报告这个月有多少天.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int year,month,days;
	printf("请输入年，月：");
	scanf("%d,%d",&year,&month);

	while(month<1||month>12)
	{	
		printf("输入错误，请重新输入年，月：");
		scanf("%d,%d",&year,&month);
	
	}
	
	switch(month)
	{
		case(2):
				if((year%4==0&&year%100!=0)||(year%400==0)) 
					days=29;
				else 
					days=28;
				break;
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):days=31;break;
		default:days=30;
	}


		printf("这个月有%d天\n",days);


}