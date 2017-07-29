// 求最大公约数和最小公倍数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
int num4;
void main()
{
	extern int num1,num2;
	int STCD(int num1,int num2);
	int LCM(int num4);
	
	printf("请输入两个正整数：");
	scanf("%d,%d",&num1,&num2);

	while(num1<1||num2<1)
	{
		printf("请重新输入两个正整数：");
		scanf("%d,%d",&num1,&num2);
	}
	
	
	printf("两数的最大公约数为：%d\n",STCD(num1,num2));
	
	printf("两数的最小公倍数为：%d\n",LCM(num4));


}

int STCD(int num1,int num2)
{	
	int num3,temp;
	num4=num1*num2;
	if(num1<num2)
		{
			temp=num2;
			num2=num1;
			num1=temp;
		}
		
		do
		{
			num3=num1%num2;
			if(num3==0) break;
			num1=num2;
			num2=num3;

		}while(num3!=0);



	return num2;



}
int num1,num2;
int LCM(int num4)
{
	
	num4=num4/STCD(num1,num2);
		
	return num4;	







}