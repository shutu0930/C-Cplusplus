// ��ӡ���ƣ��ң�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int i,j,num;

	printf("��������Ҫ��ӡ��������");
	scanf("%d",&num);

	for(i=1;i<=num;i++)
	{
		for(j=num+1-i;j<=num;j++)
		{
			printf("* ");
		}
	printf("\n");
	
	}


}

