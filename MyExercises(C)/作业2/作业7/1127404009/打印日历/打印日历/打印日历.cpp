// 打印日历.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int month,day,dayth,week,lim,i,days=365;

	do
	{
		printf("请输入您要的2011年的月份（1—12）：");			//输入月份
		scanf("%d",&month);
	
	}while(month<1||month>12);									//输入不合要求时循环直到输入合法为止

	printf(" 日 一 二 三 四 五 六\n");				

	switch(month)												//计算除当月以外的总天数
	{
		case(1):days-=31;
		case(2):days-=28;
		case(3):days-=31;
		case(4):days-=30;
		case(5):days-=31;
		case(6):days-=30;
		case(7):days-=31;
		case(8):days-=31;
		case(9):days-=30;
		case(10):days-=31;
		case(11):days-=30;
		case(12):days-=31;break;
	
	}
	switch(month)												//每个月的天数
	{
		case(2):day=28;break;
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):day=31;break;
		default:day=30;
	}
	
	
	week=(days+1)%7;

	switch(week)												//switch语句分支求出该月的1号为星期几，并输入相应的空格
	{
		case(0):lim=5;for(i=1;i<=lim;i++) printf("   ");break;
		case(1):lim=6;for(i=1;i<=lim;i++) printf("   ");break;
		case(2):lim=0;break;
		case(3):lim=1;printf("   ");break;
		case(4):lim=2;for(i=1;i<=lim;i++) printf("   ");break;
		case(5):lim=3;for(i=1;i<=lim;i++) printf("   ");break;
		case(6):lim=4;for(i=1;i<=lim;i++) printf("   ");break;
		
	
	}
	
	
	
	for(dayth=1;dayth<=day;dayth++)								//输入日期，并每7个换行
	{
		printf("%3d",dayth);
		lim++;
		if(lim%7==0) printf("\n");
	
	}

	printf("\n");

}

