// ���Ƴ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int flag[52]={0},num[4][13];	//���������飨�ѳ�ʼ����Ϊ0�����������
	int i,j,n;
	
	srand((unsigned)time(NULL));		

	for(i=0;i<4;i++)
	{
		printf("%c�õ����ƣ�",65+i);		//A��B��C��D��������
		for(j=0;j<13;)
		{		
			n=num[i][j]=rand()%52+1;		//�������1-52��ֵ
			if(flag[n-1]!=1)				//�����ֵ��Ϊ1����˵����������ǰ���κ����ظ�
			{	
				flag[n-1]=1;				//ʹ���ֵΪ1
				printf("%3d,",num[i][j]);
				j++;						//j+1ʹѭ������
				
			}
			
		}	
		printf("\n");
	
	}


}

