// ��8���˶�Ա�ɼ���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	double grade[8];
	double temp1;
	int num[8];
	int i,j,temp2;
	
	srand((unsigned)time(NULL));
	printf("��8���˶�Ա��100���ܳɼ����򣬲����������\n��ţ�");				//���˶�Ա���1-8
	for(j=0;j<=7;j++)
	{
		num[j]=j+1;
		printf("%-6d",num[j]);
		
	}
	printf("\n�ɼ���");
	
	for(i=0;i<=7;i++)
	{
		
		grade[i]=0.01*(rand()%700+700);		//�������7.00-14.00���˶�Ա�ɼ�
		printf("%-2.2lf ",grade[i]);
		
	}
	printf("\n\n������");
	
	for(j=0;j<7;j++)
	{
		for(i=0;i<7-j;i++)
		{
			if(grade[i+1]<grade[i])
			{
				temp1=grade[i];
				grade[i]=grade[i+1];		//ð�ݷ����ɼ�����
				grade[i+1]=temp1;

				temp2=num[i];				//�������ɼ���Ӧ���Ա����
				num[i]=num[i+1];
				num[i+1]=temp2;
			}
		
		}
	}
	

	for(i=0;i<=7;i++)
	{
		printf("%-6d",i+1);				//����˶�Ա����
	
	
	}
	printf("\n��ţ�");
	
	for(j=0;j<=7;j++)
	{
		printf("%-6d",num[j]);			//�����������Ӧ���˶�Ա���
	
	}
	
	printf("\n�ɼ���");
	for(i=0;i<=7;i++)
	{
		printf("%-2.2lf ",grade[i]);	//����˶�Ա��Ӧ�ĳɼ�
	
	}
	printf("\n");


}

