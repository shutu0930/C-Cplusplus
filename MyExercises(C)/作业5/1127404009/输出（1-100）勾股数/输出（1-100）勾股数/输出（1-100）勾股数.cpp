// �����1-100��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>

void main()
{
	int num1,num2,zheng,count=0;
	double num3;
	
	for(num1=1;num1<=98;num1++)										//forѭ����num1��1-98
	{
		for(num2=num1+1;num2<=99;num2++)
		{
			num3=sqrt(num1*num1*1.0+num2*num2*1.0);				//��������ƽ����ƽ����
			zheng=(int)num3;									//����ȡ��
			
			if(num3>1 && num3<=100 && (double)zheng==num3)		//�ж�num3�Ƿ����Ҫ��
			{
				printf("%3d,%3d,%3d   ",num1,num2,zheng);		//�����������
				count++;
				if(count%5==0) printf("\n");					//ÿ5�黻��
			}
	
			else continue;										//continue���
		}
	
	
	
	
	}








}

