// 100-999֮���ˮ�ɻ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int num,num1,num2,num3;

	for(num=100;num<1000;num++)
	{
		num1=(int)(num/100);
		num2=((int)(num/10))-num1*10;
		num3=num%10;

		if(num==num1*num1*num1+num2*num2*num2+num3*num3*num3)
		{
			printf("%5d",num);
		}
	}
	printf("\n");
}	

