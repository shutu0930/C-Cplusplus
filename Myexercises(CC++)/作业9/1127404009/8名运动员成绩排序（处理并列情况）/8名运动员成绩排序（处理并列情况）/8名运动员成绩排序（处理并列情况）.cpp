// 8���˶�Ա�ɼ����򣨴����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
void main()
{
	double grade[8][2];
	double temp1,temp2;
	int num[8];
	int i,j,temp;
	
	//srand((unsigned)time(NULL));
	printf("��8���˶�Ա��100���ܳɼ����򣬲����������\n���ÿո������\n��ţ�");				//���˶�Ա�������
	for(j=0;j<=7;j++)
	{
		grade[j][0]=(j+1)*1.0;
		printf("%.0lf    ",grade[j][0]);
		//scanf("%d ",&temp);
		//grade[j][0]=temp*1.0;
		
	}
	printf("\n�ɼ���");
	
	for(i=0;i<=7;i++)
	{
		
		//grade[i][1]=0.01*(rand()%700+700);		
		//printf("%-2.2lf ",grade[i][1]);
		scanf("%lf ",&grade[i][1]);
		
	}
	
	printf("\n\n������");
	
	for(j=0;j<7;j++)
	{
		for(i=j+1;i<8;i++)
		{
			if(grade[j][1]>grade[i][1])
			{
				temp1=grade[i][1];
				grade[i][1]=grade[j][1];		//���ɼ�����
				grade[j][1]=temp1;

				temp2=grade[i][0];				//�������ɼ���Ӧ���Ա����
				grade[i][0]=grade[j][0];
				grade[j][0]=temp2;
			}
		
		}
	}
	

		num[0]=1;
		for(i=1,j=1;j<8;i++,j++)				//���������
		{
			if(grade[j][1]!=grade[j-1][1])
			num[j]=i+1;
			else 
			num[j]=num[j-1];
				
				
		}

	
		
		for(i=0;i<8;i++)
		{
			printf("%-6d",num[i]);	
		}										//����˶�Ա����
	
	
	printf("\n��ţ�");
	
	for(j=0;j<=7;j++)
	{
		printf("%.0lf     ",grade[j][0]);			//�����������Ӧ���˶�Ա���
	
	}
	
	printf("\n�ɼ���");
	
	for(i=0;i<=7;i++)
	{
		printf("%-2.2lf ",grade[i][1]);	//����˶�Ա��Ӧ�ĳɼ�
	
	}
	printf("\n");


}



