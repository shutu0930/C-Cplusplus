// ��Ӳ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int peo_get,com_get=0,remain=21,spare=21;

	printf("��21öӲ�ң����һöӲ�ұ�˭����˭�����ˣ��û����ã���������Ҫ�õ�Ӳ������ÿ��ÿ��ֻ����1��4ö����");					//�����û��õ�Ӳ����
	scanf("%d",&peo_get);

	while(peo_get<1||peo_get>4)
	{
		printf("����������������룺");																						//������ֵ��Χ���Ϸ���ѭ�����룬ֱ�����Ϊֹ
		scanf("%d",&peo_get);
	
	}

	remain-=(com_get+peo_get);													
	do
	{
		
		com_get=5-peo_get;
		spare-=(com_get+peo_get);																								//��ʣ���Ӳ����

		printf("��������ߵ�Ӳ������%d\n(ʣ��Ӳ������%d)\n���������ߵ�Ӳ������",com_get,spare);									//��������ߵ�Ӳ�����������û�ʣ�����Ӳ�ң������û�������Ӳ��
		scanf("%d",&peo_get);

		while(peo_get<1||peo_get>4||peo_get>spare)																				//���û���ֵ��Χ���Ϸ���ѭ�����룬ֱ�����Ϊֹ
			{
				printf("����������������룺");
				scanf("%d",&peo_get);
			
			}
		remain-=(com_get+peo_get);																								//��ǰʣ���Ӳ����
	
	}while(remain!=0);
	
	printf("�Բ��������ˣ�����һ�֣�\n");																						//�û���������Ӳ�ң��������Ӯ��









}

