// 判断该天是那年的第多少天.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int year,month,day,days;
	int dayth=365;
	
	printf("请输入年，月，日：");
	scanf("%d,%d,%d",&year,&month,&day);
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
	
	while(month<1||month>12||day>days)
	{	
		printf("输入错误，请重新输入年，月，日：");
		scanf("%d,%d,%d",&year,&month,&day);
	}
	
		
	
	switch(month)
	{
		case(1):dayth-=31;
		case(2):dayth-=28;
		case(3):dayth-=31;
		case(4):dayth-=30;
		case(5):dayth-=31;
		case(6):dayth-=30;
		case(7):dayth-=31;
		case(8):dayth-=31;
		case(9):dayth-=30;
		case(10):dayth-=31;
		case(11):dayth-=30;
		case(12):dayth-=31;break;
	
	}
	
	
	if((year%4==0&&year%100!=0)||(year%400==0)) 
	{
		if(month>2) dayth+=(day+1);
		else dayth+=day;
	}

	else 
		dayth+=day;
	printf("该天是这年的第%d天\n",dayth);
		
		

}