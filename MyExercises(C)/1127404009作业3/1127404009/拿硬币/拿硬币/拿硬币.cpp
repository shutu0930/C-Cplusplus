// 拿硬币.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int peo_get,com_get=0,remain=21,spare=21;

	printf("有21枚硬币，最后一枚硬币被谁拿走谁就输了，用户先拿，请输入您要拿的硬币数（每人每次只能拿1—4枚）：");					//输入用户拿的硬币数
	scanf("%d",&peo_get);

	while(peo_get<1||peo_get>4)
	{
		printf("输入错误，请重新输入：");																						//若输入值范围不合法，循环输入，直到输对为止
		scanf("%d",&peo_get);
	
	}

	remain-=(com_get+peo_get);													
	do
	{
		
		com_get=5-peo_get;
		spare-=(com_get+peo_get);																								//求剩余的硬币数

		printf("计算机拿走的硬币数：%d\n(剩余硬币数：%d)\n您继续拿走的硬币数：",com_get,spare);									//计算机拿走的硬币数，告诉用户剩余多少硬币，再让用户继续拿硬币
		scanf("%d",&peo_get);

		while(peo_get<1||peo_get>4||peo_get>spare)																				//若用户入值范围不合法，循环输入，直到输对为止
			{
				printf("输入错误，请重新输入：");
				scanf("%d",&peo_get);
			
			}
		remain-=(com_get+peo_get);																								//当前剩余的硬币数
	
	}while(remain!=0);
	
	printf("对不起，您输了！再来一局？\n");																						//用户拿完最后的硬币，计算机就赢了









}

