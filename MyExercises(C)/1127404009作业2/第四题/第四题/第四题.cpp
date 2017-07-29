// 第四题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int a,b,c;
	printf("请输入3个数：");
	scanf("%d,%d,%d",&a,&b,&c);

	if(a>b && a>c)
	printf("最大数为%d\n",a);		//若a最大
	
	if(b>a && b>c)
	printf("最大数为%d\n",b);		//若b最大
	
	if(c>b && c>a)
	printf("最大数为%d\n",c);		//若c最大

}

