// ��Ӳ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int peo_get,com_get=0,remain=21,spare=21;

	printf("��������Ҫ�õ�Ӳ������ÿ��ÿ��ֻ����1��4ö����");
	scanf("%d",&peo_get);

	while(peo_get<1||peo_get>4)
	{
		printf("����������������룺");
		scanf("%d",&peo_get);
	
	}

	remain-=(com_get+peo_get);
	do
	{
		
		com_get=5-peo_get;
		spare-=(com_get+peo_get);

		printf("��������ߵ�Ӳ������%d\nʣ��Ӳ������%d\n���������ߵ�Ӳ������",com_get,spare);
		scanf("%d",&peo_get);

		while(peo_get<1||peo_get>4||peo_get>spare)
			{
				printf("����������������룺");
				scanf("%d",&peo_get);
			
			}
		remain-=(com_get+peo_get);
	}
	while(remain!=0);
	
	printf("�Բ��������ˣ�����һ�֣�\n");









}

