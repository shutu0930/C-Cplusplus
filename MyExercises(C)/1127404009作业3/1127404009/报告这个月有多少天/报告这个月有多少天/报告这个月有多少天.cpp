// ����������ж�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int year,month,days;
	printf("�������꣬�£�");								//�����꣬��
	scanf("%d,%d",&year,&month);

	while(month<1||month>12)								//���������ݲ��Ϸ���ѭ���������룬ֱ�����Ϊֹ
	{	
		printf("������������������꣬�£�");
		scanf("%d,%d",&year,&month);
	
	}
	
	switch(month)
	{
		case(2):
				if((year%4==0&&year%100!=0)||(year%400==0))		//�ж��Ƿ�Ϊ����
					days=29;
				else 
					days=28;
				break;
		case(1):												//��дbreak�ó��򰤸�ִ��
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):days=31;break;
		default:days=30;
	}


	printf("�������%d��\n",days);							//������������


}