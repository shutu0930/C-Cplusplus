// �������Ŀ������FOR.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int num1,num2,ques,answer,i=1,count=0;
	printf("��������Ҫ����������");							//����Ҫ������
	scanf("%d",&ques);



	while(i<=ques)
	{
		srand((unsigned)time(NULL));						//�������Ŀ
		int num1=rand()%100;
		int num2=rand()%100;
		printf("%d.  %d+%d=",i,num1,num2);
		scanf("%d",&answer);
		i++;

		if(answer==num1+num2)								//������ȷ������
			count++;
	
	
	}
	
	
	printf("��һ������%d���⣬�����%d���⣬�����%d���⡣",ques,count,ques-count);



}

