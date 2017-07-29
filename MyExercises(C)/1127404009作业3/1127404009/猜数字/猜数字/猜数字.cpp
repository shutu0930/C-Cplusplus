// 猜数字.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdlib.h>
void main()
{
	int num2,count=1;
	int num1=rand();									//随机获取一个数

	printf("计算机随机产生一个数，请猜猜该数为多少：");	//输入一次
	scanf("%d",&num2);

	while(num2!=num1)									//猜错时
	{
		if(num2>num1)
		{
			printf("您猜的数偏大，请再猜一次：");		//提示猜的数偏大，并累计猜的次数
			scanf("%d",&num2);
			count++;
		}
		else 
		{
			printf("您猜的数偏小，请再猜一次：");		//提示猜的数偏小，并累计猜的次数
			scanf("%d",&num2);
			count++;
		}
	
	}


	printf("恭喜您猜对了！您总共猜了%d次！\n",count);	//输出共猜的次数



}

