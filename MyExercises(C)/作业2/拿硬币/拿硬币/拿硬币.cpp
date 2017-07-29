// 拿硬币.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int peo_get,com_get=0,remain=21,spare=21;

	printf("请输入您要拿的硬币数（每人每次只能拿1—4枚）：");
	scanf("%d",&peo_get);

	while(peo_get<1||peo_get>4)
	{
		printf("输入错误，请重新输入：");
		scanf("%d",&peo_get);
	
	}

	remain-=(com_get+peo_get);
	do
	{
		
		com_get=5-peo_get;
		spare-=(com_get+peo_get);

		printf("计算机拿走的硬币数：%d\n剩余硬币数：%d\n您继续拿走的硬币数：",com_get,spare);
		scanf("%d",&peo_get);

		while(peo_get<1||peo_get>4||peo_get>spare)
			{
				printf("输入错误，请重新输入：");
				scanf("%d",&peo_get);
			
			}
		remain-=(com_get+peo_get);
	}
	while(remain!=0);
	
	printf("对不起，您输了！再来一局？\n");









}

