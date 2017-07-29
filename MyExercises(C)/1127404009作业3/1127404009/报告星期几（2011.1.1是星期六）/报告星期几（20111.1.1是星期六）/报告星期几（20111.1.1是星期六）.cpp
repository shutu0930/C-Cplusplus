// 报告星期几（20111.1.1是星期六）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int month,day,days,remain;
	int dayth=365;
	
	printf("请输入月，日：");							//输入年，月
	scanf("%d,%d",&month,&day);
	
	switch(month)										//用来算每个月有多少天，以便进行下面的检验
	{
		case(2):days=28;break;
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):days=31;break;
		default:days=30;
	}
	
	while(month<1||month>12||day>days)					//若用户输入的月，日不合法，让用户循环输入，直到输对为止
	{	
		printf("输入错误，请重新输入月，日：");
		scanf("%d,%d",&month,&day);
	}
	
		
	
	switch(month)
	{
		case(1):dayth-=31;
		case(2):dayth-=28;								//switch语句，不写break，算出除当月外剩余的天数
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
	
	
	dayth+=day;										//算出总共的天数
	
	
	remain=dayth%7;

	switch(remain)										//根据该天数除7余下的天数判断其为星期几
	{
		case(0):printf("这天是今年的星期五\n");break;
		case(1):printf("这天是今年的星期六\n");break;
		case(2):printf("这天是今年的星期日\n");break;
		case(3):printf("这天是今年的星期一\n");break;
		case(4):printf("这天是今年的星期二\n");break;
		case(5):printf("这天是今年的星期三\n");break;
		case(6):printf("这天是今年的星期四\n");break;
		
	}

	
		
		

}