// 第一题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>


void main()
{
	int num1,num2,temp,res;
	int fac(int num);
	printf("Please input m and n :\n");
	scanf("%d,%d",&num1,&num2);
	
	if(num1<num2)
	{
		temp=num1;
		num1=num2;
		num2=temp;
	
	}

	res=fac(num1)/(fac(num2)*fac(num1-num2));

	printf("m!/[n!×(m－n)!]=%d\n",res);






}
int fac(int num)
{
	int i,num1=1;
	for(i=1;i<=num;i++)
	{
		num1*=i;
	}

	return num1;

}


