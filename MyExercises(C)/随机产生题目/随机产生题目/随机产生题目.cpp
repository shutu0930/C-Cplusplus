// ���������Ŀ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num1,num2,ques,answer,i,count=0;
	printf("��������Ҫ����������");						//����Ҫ������
	scanf("%d",&ques);



	for(i=1;i<=ques;i++)
	{
		srand((unsigned)time(NULL));
		int num1=rand()%100;							//�������Ŀ
		int num2=rand()%100;
		printf("%d.   %d+%d=",num1,num2);
		scanf("%d",&answer);
		

		if(answer==num1+num2) 
			count++;								//������ȷ������
		
		
		
	
	
	
	}
	
	printf("��һ������%d���⣬�����%d���⣬�����%d���⡣",ques,count,ques-count);



}

