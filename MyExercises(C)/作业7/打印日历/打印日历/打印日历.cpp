// ��ӡ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int month,day,dayth,week,lim,i,days=365;

	do
	{
		printf("��������Ҫ��2011����·ݣ�1��12����");			//�����·�
		scanf("%d",&month);
	
	}while(month<1||month>12);									//���벻��Ҫ��ʱѭ��ֱ������Ϸ�Ϊֹ

	printf(" �� һ �� �� �� �� ��\n");				

	switch(month)												//��������������������
	{
		case(1):days-=31;
		case(2):days-=28;
		case(3):days-=31;
		case(4):days-=30;
		case(5):days-=31;
		case(6):days-=30;
		case(7):days-=31;
		case(8):days-=31;
		case(9):days-=30;
		case(10):days-=31;
		case(11):days-=30;
		case(12):days-=31;break;
	
	}
	switch(month)												//ÿ���µ�����
	{
		case(2):day=28;break;
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):day=31;break;
		default:day=30;
	}
	
	
	week=(days+1)%7;

	switch(week)												//switch����֧������µ�1��Ϊ���ڼ�����������Ӧ�Ŀո�
	{
		case(0):lim=5;for(i=1;i<=lim;i++) printf("   ");break;
		case(1):lim=6;for(i=1;i<=lim;i++) printf("   ");break;
		case(2):lim=0;break;
		case(3):lim=1;printf("   ");break;
		case(4):lim=2;for(i=1;i<=lim;i++) printf("   ");break;
		case(5):lim=3;for(i=1;i<=lim;i++) printf("   ");break;
		case(6):lim=4;for(i=1;i<=lim;i++) printf("   ");break;
		
	
	}
	
	
	
	for(dayth=1;dayth<=day;dayth++)								//�������ڣ���ÿ7������
	{
		printf("%3d",dayth);
		lim++;
		if(lim%7==0) printf("\n");
	
	}

	printf("\n");

}

