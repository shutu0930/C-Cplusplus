// ��ӡ�������ͻ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int i,j,num;

	printf("��������Ҫ��ӡ��*����������");		//���û�����Ҫ��ӡ������
	scanf("%d",&num);

	for(i=1;i<=num;i++)							//i����������j��������
	{
		for(j=1;j<=(num-i);j++)					//for���ѭ��Ƕ��
		{
			printf(" ");						//1���ո�
		}
		for(j=1;j<=i;j++)
		{
			printf("* ");						//1��*��1���ո�
		}
		printf("\n");							//����
	
	}


}

