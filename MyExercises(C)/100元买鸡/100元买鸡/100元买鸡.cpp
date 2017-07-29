// 100元买鸡.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int gongji,muji,xiaoji;
	
	printf("所有可能情况：\n公鸡\t母鸡\t小鸡\n");


	for(gongji=1;gongji<20;gongji++)
	{
		for(muji=1;muji<34;muji++)
		{
			
			xiaoji=(100-gongji-muji);
			if(xiaoji%3==0&&100==5*gongji+3*muji+(xiaoji/3))
			{
				printf("%d\t%d\t%d\n",gongji,muji,xiaoji);
			
			}
		
		
		}
	
	}







}

