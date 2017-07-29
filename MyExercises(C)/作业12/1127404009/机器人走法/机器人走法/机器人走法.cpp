// 机器人走法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int way(int n);

	int meter;

	printf("请输入让机器人走的路程（m）：");
	scanf("%dm",&meter);

	printf("一共有%d种走法\n",way(meter));
}

//========================================
//	本函数用于计算出机器人的走法（递归法）
//	参数说明：int n传入要走的路程
//========================================
int way(int n)
{
	int measures;

	if(n==1)
		measures=1;
	else if(n==2)
		measures=2;
	else if(n>=3)
		measures=way(n-1)+way(n-2);
	return measures;

}