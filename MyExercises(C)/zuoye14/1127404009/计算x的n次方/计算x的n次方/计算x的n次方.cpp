// 计算x的n次方.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	double num;
	int pow;
	double mathpow(double num,int pow);

	printf("求x的n次方，请输入x和n：\n");
	scanf("%lf,%d",&num,&pow);

	printf("其结果为：%.3lf\n",mathpow(num,pow));

}
double mathpow(double num,int pow)
{
	int i,sign=0;
	double res=1.0;

	if(pow<0)
	{
		pow=-pow;
		sign=1;
	}		
	for(i=1;i<=pow;i++)
	{
		res*=num;
	}
	if(sign==1)
		res=1.0/res;

	return res;

}

