// �жϸ���������ĵڶ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int year,month,day,days;
	int dayth=365;
	
	printf("�������꣬�£��գ�");
	scanf("%d,%d,%d",&year,&month,&day);						//�����꣬�£���
	
	switch(month)												//switch�ṹ�ж�
	{
		case(2):
				if((year%4==0&&year%100!=0)||(year%400==0))		//�ж��Ƿ�Ϊ���� 
					days=29;
				else 
					days=28;
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
	
	while(month<1||month>12||day>days)							//�ж��û�������£����Ƿ���ȷ�����Ϸ�ʱѭ������ֱ�����Ϊֹ
	{	
		printf("������������������꣬�£��գ�");
		scanf("%d,%d,%d",&year,&month,&day);
	}
	
		
	
	switch(month)												//switch�ṹ������break������˵�������������
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
	
	
	if((year%4==0&&year%100!=0)||(year%400==0))					//�ж��Ƿ�Ϊ���겢���࣬�������·ݴ���2��С�ڵ���2�������ͬ
	{
		if(month>2) dayth+=(day+1);
		else dayth+=day;
	}

	else 
		dayth+=day;
	
	printf("����������ĵ�%d��\n",dayth);						//���
		
		

}