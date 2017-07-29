// 输出（1-100）勾股数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>

void main()
{
	int num1,num2,a,count=0;
	float b,num3;
	for(num1=1;num1<=100;num1++)
	{
		for(num2=1;num2<=100,num2>=num1;num2++)
		{
				num3=sqrt(num1*num1+num2*num2);
				
				(int)a=sqrt(num3);
				(float)b=sqrt(num3);
				if(num3>1 && num3<10000 &&(b-a==0.0))
				{
					printf("%d,%d,%d\t",num1,num2,a);
					count++;
					if(count%5==0) printf("\n");
				}
		
				else continue;
		}
	
	
	
	
	}








}

