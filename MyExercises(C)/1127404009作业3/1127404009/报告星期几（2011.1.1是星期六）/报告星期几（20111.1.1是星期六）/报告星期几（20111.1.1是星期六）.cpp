// �������ڼ���20111.1.1����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int month,day,days,remain;
	int dayth=365;
	
	printf("�������£��գ�");							//�����꣬��
	scanf("%d,%d",&month,&day);
	
	switch(month)										//������ÿ�����ж����죬�Ա��������ļ���
	{
		case(2):days=28;break;
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):days=31;break;
		default:days=30;
	}
	
	while(month<1||month>12||day>days)					//���û�������£��ղ��Ϸ������û�ѭ�����룬ֱ�����Ϊֹ
	{	
		printf("������������������£��գ�");
		scanf("%d,%d",&month,&day);
	}
	
		
	
	switch(month)
	{
		case(1):dayth-=31;
		case(2):dayth-=28;								//switch��䣬��дbreak�������������ʣ�������
		case(3):dayth-=31;
		case(4):dayth-=30;
		case(5):dayth-=31;
		case(6):dayth-=30;
		case(7):dayth-=31;
		case(8):dayth-=31;
		case(9):dayth-=30;
		case(10):dayth-=31;
		case(11):dayth-=30;
		case(12):dayth-=31;break;
	
	}
	
	
	dayth+=day;										//����ܹ�������
	
	
	remain=dayth%7;

	switch(remain)										//���ݸ�������7���µ������ж���Ϊ���ڼ�
	{
		case(0):printf("�����ǽ����������\n");break;
		case(1):printf("�����ǽ����������\n");break;
		case(2):printf("�����ǽ����������\n");break;
		case(3):printf("�����ǽ��������һ\n");break;
		case(4):printf("�����ǽ�������ڶ�\n");break;
		case(5):printf("�����ǽ����������\n");break;
		case(6):printf("�����ǽ����������\n");break;
		
	}

	
		
		

}