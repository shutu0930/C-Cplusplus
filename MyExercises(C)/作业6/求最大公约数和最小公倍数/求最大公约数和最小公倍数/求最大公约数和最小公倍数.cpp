// �����Լ������С������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
int num4;
void main()
{
	extern int num1,num2;
	int STCD(int num1,int num2);
	int LCM(int num4);
	
	printf("������������������");
	scanf("%d,%d",&num1,&num2);

	while(num1<1||num2<1)
	{
		printf("����������������������");
		scanf("%d,%d",&num1,&num2);
	}
	
	
	printf("���������Լ��Ϊ��%d\n",STCD(num1,num2));
	
	printf("��������С������Ϊ��%d\n",LCM(num4));


}

int STCD(int num1,int num2)
{	
	int num3,temp;
	num4=num1*num2;
	if(num1<num2)
		{
			temp=num2;
			num2=num1;
			num1=temp;
		}
		
		do
		{
			num3=num1%num2;
			if(num3==0) break;
			num1=num2;
			num2=num3;

		}while(num3!=0);



	return num2;



}
int num1,num2;
int LCM(int num4)
{
	
	num4=num4/STCD(num1,num2);
		
	return num4;	







}