// ��׳�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	unsigned int num,prod=1,i=1;
	printf("������1-20֮���һ��������");					//����
	scanf("%u",&num);

	while(num<1||num>20)
	{
		printf("�������ݴ�������������1~20֮���һ������");		//���벻�Ϸ�ʱ�������룬ֱ�����Ϊֹ
		scanf("%u",&num);
	
	}
	
	while(i<=num)											//while�������׳�
	{
		prod=prod*i;
		i++;
	
	}

	printf("�����Ľ׳�Ϊ%u\n",prod);						//���




}

