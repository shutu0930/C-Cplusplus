// �ж����ڼ���1990.1.1������һ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int year,month,day,days;
	int dayth=365;
	
	printf("�������꣬�£��գ�");
	scanf("%d,%d,%d",&year,&month,&day);								//�����꣬�£���
	switch(month)
	{
		case(2):
				if((year%4==0&&year%100!=0)||(year%400==0)) 
					days=29;
				else 
					days=28;											//�жϸ�����������Ա�����ı���
				break;
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):days=31;break;
		default:days=30;
	}
	
	while(month<1||month>12||day>days)									//���û������£��ղ��Ϸ���ѭ�����룬ֱ������Ϸ�
	{	
		printf("������������������꣬�£��գ�");
		scanf("%d,%d,%d",&year,&month,&day);
	}
	
		
	
	switch(month)														
	{
		case(1):dayth-=31;
		case(2):dayth-=28;
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
	
	
	if((year%4==0&&year%100!=0)||(year%400==0))							//�ж��Ƿ�Ϊ���꣬�������������������Ϊ����ĵڼ���
	{
		if(month>2) dayth+=(day+1);
		else dayth+=day;
	}

	else 
		dayth+=day;
	
	int count=0,alldays,remain;
	
	while((year%4==0&&year%100!=0)||(year%400==0)&&(year>1900))						//��֮���ж�������
	{
		count++;
		year--;
		continue;
	
	}

	alldays=(year-1900-count)*365+count*366+dayth;					//�������1900��1��1���ж�����
	
	
	remain=alldays%7;

	switch(remain)
	{
	case(0):printf("�����������������\n");break;						//������������7����������������ڼ�
	case(1):printf("���������������һ\n");break;
	case(2):printf("��������������ڶ�\n");break;
	case(3):printf("�����������������\n");break;
	case(4):printf("�����������������\n");break;
	case(5):printf("�����������������\n");break;
	case(6):printf("�����������������\n");break;
	
	}

	
		
		

}