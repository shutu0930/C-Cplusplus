// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int a,b,c;
	printf("������3������");
	scanf("%d,%d,%d",&a,&b,&c);

	if(a>b && a>c)
	printf("�����Ϊ%d\n",a);		//��a���
	
	if(b>a && b>c)
	printf("�����Ϊ%d\n",b);		//��b���
	
	if(c>b && c>a)
	printf("�����Ϊ%d\n",c);		//��c���

}

