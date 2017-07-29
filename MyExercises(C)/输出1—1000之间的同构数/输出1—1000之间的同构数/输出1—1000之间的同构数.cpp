// 输出1—1000之间的同构数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
void main()
{
	int num;
	
	for(num=1;num<=1000;num++)
	{
		if(num<=9)
		{
			if(num*num%10==num)
				printf("%5d",num);
		
		}

		
		else if(num>=10 && num<=99)
		{
			if(num*num%100==num)
				printf("%5d",num);
		
		
		}
		
		else if(num>=100 && num<=999)
		{
			if(num*num%1000==num)
			{
			printf("%5d",num);
			
			}
		
		}
	
	}


	printf("\n");




}

