// 输出（1-100）勾股数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>

void main()
{
	int num1,num2,zheng,count=0;
	double num3;
	
	for(num1=1;num1<=98;num1++)										//for循环让num1从1-98
	{
		for(num2=num1+1;num2<=99;num2++)
		{
			num3=sqrt(num1*num1*1.0+num2*num2*1.0);				//算两个数平方的平方根
			zheng=(int)num3;									//对其取整
			
			if(num3>1 && num3<=100 && (double)zheng==num3)		//判断num3是否符合要求
			{
				printf("%3d,%3d,%3d   ",num1,num2,zheng);		//输出勾股数组
				count++;
				if(count%5==0) printf("\n");					//每5组换行
			}
	
			else continue;										//continue语句
		}
	
	
	
	
	}








}

