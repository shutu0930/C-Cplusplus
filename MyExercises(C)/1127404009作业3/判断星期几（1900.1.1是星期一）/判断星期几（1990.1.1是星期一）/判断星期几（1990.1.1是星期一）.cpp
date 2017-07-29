// 判断星期几（1990.1.1是星期一）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int year,month,day,days;
	int dayth=365;
	
	printf("请输入年，月，日：");
	scanf("%d,%d,%d",&year,&month,&day);								//输入年，月，日
	switch(month)
	{
		case(2):
				if((year%4==0&&year%100!=0)||(year%400==0)) 
					days=29;
				else 
					days=28;											//判断该年的天数，以便下面的报错
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
	
	while(month<1||month>12||day>days)									//若用户输入月，日不合法，循环输入，直到输入合法
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
	
	
	if((year%4==0&&year%100!=0)||(year%400==0))							//判断是否为闰年，并分情况求的输入的日期为当年的第几天
	{
		if(month>2) dayth+=(day+1);
		else dayth+=day;
	}

	else 
		dayth+=day;
	
	int count=0,alldays,remain;
	
	while((year%4==0&&year%100!=0)||(year%400==0)&&(year>1900))						//求之间有多少闰年
	{
		count++;
		year--;
		continue;
	
	}

	alldays=(year-1900-count)*365+count*366+dayth;					//求出距离1900年1月1日有多少天
	
	
	remain=alldays%7;

	switch(remain)
	{
	case(0):printf("这天是那年的星期日\n");break;						//根据总天数除7的余数算出其是星期几
	case(1):printf("这天是那年的星期一\n");break;
	case(2):printf("这天是那年的星期二\n");break;
	case(3):printf("这天是那年的星期三\n");break;
	case(4):printf("这天是那年的星期四\n");break;
	case(5):printf("这天是那年的星期五\n");break;
	case(6):printf("这天是那年的星期六\n");break;
	
	}

	
		
		

}