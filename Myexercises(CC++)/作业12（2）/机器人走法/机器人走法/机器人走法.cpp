// �������߷�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int way(int n);

	int meter;

	printf("�������û������ߵ�·�̣�m����");
	scanf("%dm",&meter);

	printf("һ����%d���߷�\n",way(meter));
}

int way(int n)
{
	int measures;

	if(n==1)
		measures=1;
	else if(n==2)
		measures=2;
	else if(n>=3)
		measures=way(n-1)+way(n-2);
	return measures;

}