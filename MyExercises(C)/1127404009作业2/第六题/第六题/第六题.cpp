// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	float x,y;
	printf("Please input x=");
	scanf("%f",&x);

	if(x<10)		
	{
	if(x<1)	//��x<1
	{y=x;printf("When x=%7.5f,y=x=%f\n",x,y);}
	else	//��1<=x<=10
	{y=2*x-1;printf("When x=%7.5f,y=2x-1=%f\n",x,y);}
		
	}
	else	//��x>=10
	{y=3*x-11;printf("When x=%f,y=3x-11=%7.5f\n",x,y);}
	

	


}

