// ����������Ӳ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int jia_get,yi_get=0,remain=21,spare=21;

	printf("��21öӲ�ң����һöӲ�ұ�˭����˭�����ˣ�������\n");		
	
	do
	{
		printf("�������ͬѧ��Ҫ�õ�Ӳ������ÿ��ÿ��ֻ����1��4ö����");															//������õ�Ӳ����
		scanf("%d",&jia_get);

		while(jia_get<1||jia_get>4||jia_get>spare)
		{
			printf("����������������룺");																						//������ֵ��Χ���Ϸ���ѭ�����룬ֱ�����Ϊֹ
			scanf("%d",&jia_get);
		
		}
		remain-=(jia_get+yi_get);																									//��ʣ���Ӳ����
		printf("(ʣ��Ӳ������%d)\n",remain);	
		if(remain==0) break;
		
		printf("��������ͬѧ��Ҫ�õ�Ӳ������ÿ��ÿ��ֻ����1��4ö����");															//�������õ�Ӳ����
		scanf("%d",&yi_get);
		
		while(yi_get<1||yi_get>4||yi_get>remain)
		{
			printf("����������������룺");																						//������ֵ��Χ���Ϸ���ѭ�����룬ֱ�����Ϊֹ
			scanf("%d",&yi_get);
		
		}
		spare-=(jia_get+yi_get);																								//��ʣ���Ӳ����
		printf("(ʣ��Ӳ������%d)\n",spare);																			
		if(spare==0) break;
		
	
	}while(remain!=0||spare!=0);
	
	if(remain==0) 
		printf("�Բ��𣬼����ˣ�\n");
	else if(spare==0)
		printf("�Բ��������ˣ�\n");

	



																						
}







