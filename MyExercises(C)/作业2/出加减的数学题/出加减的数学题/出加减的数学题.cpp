// ���Ӽ�����ѧ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num1,num2,num3,ques,answer,i,count=0;
	char sign;
	
	do
	{
	printf("��������Ҫ����������1��20����");						//����Ҫ������
	scanf("%d",&ques);
	}while(ques<1||ques>20);
	

	for(i=1;i<=ques;i++)
	{
		srand((unsigned)time(NULL));
		int num1=rand()%100;							//�������Ŀ
		int num2=rand()%100;
		int num3=rand();
		
		if(num3%2!=0&&num1>num2)
			sign='-';
		else 
			sign='+';
		
		printf("%d.   %d%c%d=",i,num1,sign,num2);
		scanf("%d",&answer);
	
		if(sign='-'&&answer==num1-num2)					//������ȷ������
			count++;							
		else if(sign='+'&&answer==num1+num2) 
			count++;				
	}	

	
	printf("��һ������%d���⣬�����%d���⣬�����%d���⡣",ques,count,ques-count);



}

