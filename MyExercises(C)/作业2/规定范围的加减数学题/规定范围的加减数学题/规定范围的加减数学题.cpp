// �涨��Χ�ļӼ���ѧ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num1,num2,num3,ques,answer,i,lim1,lim2,count=0;
	char sign;
	
	printf("���������涨�ļӼ������ֵķ�Χ��");
	scanf("%d-%d",&lim1,&lim2);

	do
	{
	printf("��������Ҫ����������1��20����");						//����Ҫ������
	scanf("%d",&ques);
	}while(ques<1||ques>20);
	

	for(i=1;i<=ques;i++)
	{
		srand((unsigned)time(NULL));
		int num1=rand();							//�������Ŀ
		int num2=rand();
		int num3=rand();
		
		do
		{
			if(num3%2!=0&&num1>num2)
				sign='-';
			else 
				sign='+';
			
			printf("%d.  %d%c%d=",i,num1,sign,num2);
			scanf("%d",&answer);
		
			if(sign='-'&&answer==num1-num2)					//������ȷ������
				count++;							
			else if(sign='+'&&answer==num1+num2) 
				count++;				
		}while(num1>=lim1 && num1<=lim2 && num2>=lim1 && num2<=lim2);
	}	

	
	printf("��һ������%d���⣬�����%d���⣬�����%d���⡣",ques,count,ques-count);



}

