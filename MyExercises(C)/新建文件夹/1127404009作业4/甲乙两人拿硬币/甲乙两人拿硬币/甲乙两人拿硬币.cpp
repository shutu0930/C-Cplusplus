// 甲乙两人拿硬币.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int jia_get,yi_get=0,remain=21,spare=21;

	printf("有21枚硬币，最后一枚硬币被谁拿走谁就输了，甲先拿\n");		
	
	do
	{
		printf("请输入甲同学您要拿的硬币数（每人每次只能拿1—4枚）：");															//输入甲拿的硬币数
		scanf("%d",&jia_get);

		while(jia_get<1||jia_get>4||jia_get>spare)
		{
			printf("输入错误，请重新输入：");																						//若输入值范围不合法，循环输入，直到输对为止
			scanf("%d",&jia_get);
		
		}
		remain-=(jia_get+yi_get);																									//求剩余的硬币数
		printf("(剩余硬币数：%d)\n",remain);	
		if(remain==0) break;
		
		printf("请输入乙同学您要拿的硬币数（每人每次只能拿1—4枚）：");															//输入乙拿的硬币数
		scanf("%d",&yi_get);
		
		while(yi_get<1||yi_get>4||yi_get>remain)
		{
			printf("输入错误，请重新输入：");																						//若输入值范围不合法，循环输入，直到输对为止
			scanf("%d",&yi_get);
		
		}
		spare-=(jia_get+yi_get);																								//求剩余的硬币数
		printf("(剩余硬币数：%d)\n",spare);																			
		if(spare==0) break;
		
	
	}while(remain!=0||spare!=0);
	
	if(remain==0) 
		printf("对不起，甲输了！\n");
	else if(spare==0)
		printf("对不起，乙输了！\n");

	



																						
}







