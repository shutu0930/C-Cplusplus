// ��ӡ���ƣ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int i,j,num;

	printf("��������Ҫ��ӡ��*����������");			//���û������ӡ������	
	scanf("%d",&num);

	for(i=1;i<=num;i++)							//i��ʾ������j��ʾ����
	{
		for(j=1;j<=i;j++)						//forѭ��Ƕ��
		{
			printf("* ");
		}
	printf("\n");								//����
	
	}


}

