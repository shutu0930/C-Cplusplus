// ���1��1000֮���ͬ����.cpp : �������̨Ӧ�ó������ڵ㡣
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

