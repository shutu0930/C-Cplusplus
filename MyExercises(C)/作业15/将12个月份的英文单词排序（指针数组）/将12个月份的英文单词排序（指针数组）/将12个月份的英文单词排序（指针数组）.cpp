// ��12���·ݵ�Ӣ�ĵ�������ָ�����飩.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include"stdafx.h"
#include<stdio.h>
#include<string.h>

void sort(char *month[]);
void main()
{
	char *month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int i;											//����ָ������
	
	for(i=0;i<12;i++)
	{
		puts(month[i]);								//���12���·ݵĵ���
	
	}
	
	
	
	
	printf("\n�����ʳ��ȴӴ�С����\n");

	sort(month);									//���ú�����ָ�����鴦��

	for(i=0;i<12;i++)
	{
		puts(month[i]);								//����ź����12���·ݵĵ���
	
	}

	
}

//===========================================
//���������ڽ�12���µĵ��ʰ����ȴӴ�С����
//����˵����char *month[]ָ������
//===========================================
void sort(char *month[])
{
	int num[12],i,j,temp1;
	char *temp2;

	for(i=0;i<12;i++)
		{
			num[i]=(int)strlen(month[i]);
		}


		for(j=0;j<11;j++)
		{
			for(i=j+1;i<12;i++)					
			{
				if(num[i]<num[j])
				{
					temp1=num[i];
					num[i]=num[j];
					num[j]=temp1;
					
					temp2=month[i];
					month[i]=month[j];
					month[j]=temp2;
				}
			}
		}

}


