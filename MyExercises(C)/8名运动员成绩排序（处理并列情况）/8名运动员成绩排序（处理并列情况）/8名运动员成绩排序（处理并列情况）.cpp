// 8���˶�Ա�ɼ����򣨴����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	double num[3][8],temp1,temp2;
	int i,j,temp;

	printf("������8���˶�Ա��100�׳ɼ��ͱ�ţ�");
	
	printf("\n��ţ�");
	for(j=0;j<8;j++)
	{
		scanf("%d	",&temp);
		num[0][j]=temp*0.1;
		
	}
	printf("�ɼ���");
	for(j=0;j<8;j++)
	{
		scanf("%lf	",&num[1][j]);
	
	}
	
	for(i=0;i<8;i++)
	{
		for(j=i+1;j<9;j++)
		{
			if(num[1][i]>num[1][j])
			{
				temp1=num[1][j];
				num[1][j]=num[1][i];
				num[1][i]=temp;
				

				temp2=num[0][j];
				num[0][j]=num[0][i];
				num[0][i]=temp;
			}
			
		}
		
		for(i=0;i<8;)
		{
			num[2][i]=i+1;
			if(num[1][i]==num[1][i+1])
			{
				num[2][i]=num[2][i+1];
				i+=2;
			}
			i++;
		}

	}
		
	
		for(i=0;i<8;i++)
		{
			printf("%.0lf",num[2][i]);
		
		}
		for(i=0;i<8;i++)
		{
			printf("%lf",num[1][i]);
		
		}
		for(i=0;i<8;i++)
		{
			printf("%.0lf",num[0][i]);
		
		}




}

