// �����ļ���100�����ݣ��ҳ������������������һ�ļ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<math.h>
#include<string.h>
#define N 100

void read(int *num);
int prime(int *num1,int *num2);
void sort(int *num,int n);
void write_print(int *num,int n);
void main()
{
	int num1[N],num2[N],count;			//���������������飬һ�����ڴ�Ŷ��������ݣ�һ�����ڴ�����е���������
	
	read(num1);						//���ļ��ж�����
	count=prime(num1,num2);			//����������������
	sort(num2,count);					//��������������
	write_print(num2,count);			//�������һ�ļ���


}
//=======================================
//�����������ö����ƶ�ȡ�ļ��е�����
//����˵����int *numָ��
//=======================================
void read(int *num)
{
	FILE *fp;
	char filename1[N];
	printf("Please input the filename1 to read data :\n");
	gets(filename1);
	fp=fopen(filename1,"rb");
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	
	}
	int i;
	for(i=0;i<N;i++)
	{
		if(fread(num+i,sizeof(int),1,fp)!=1)
		{
			if(feof(fp))
			{
				fclose(fp);
				return;
			}
			printf("Cannot read the file!\n");
		}
	
	
	printf("%d\t",*(num+i));
	
	}
	fclose(fp);

}
//=======================================
//���������������������е�����
//����˵����int *numָ��
//����ֵ��int count �����ĸ���
//=======================================
int prime(int *num1,int *num2)
{
	int i,k,j,count=0;
	printf("\nThe prime number :\n");
	for(i=0;i<N;i++)
	{
		k=sqrt(*(num1+i)*1.0);
		for(j=2;j<=k;j++)
		{
			if(*(num1+i)%j==0)
				break;
		}
		if(j>k)
		{
			printf("%d\t",*(num1+i));
			*(num2+count)=*(num1+i);
			count++;
		}
	
	}
	printf("\n");
	return count;

}
//==========================================
//���������ڽ���������
//����˵����int *numָ�� int n������ʵ�ʸ���
//==========================================
void sort(int *num,int n)
{
	int temp,i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(num+i)>*(num+j))				//ѡ������
			{
				temp=*(num+i);
				*(num+i)=*(num+j);
				*(num+j)=temp;
			}
		}
	}
	printf("After being sorted :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",*(num+i));
	}

}
//=======================================
//���������ڽ�����õ������������һ���ļ�
//����˵����int *numָ�� int n
//=======================================
void write_print(int *num,int n)
{
	FILE *fpout;
	char filename2[N];
	printf("\nPlease input the filename2 to write data :\n");
	gets(filename2);
	fpout=fopen(filename2,"w");
	if(fpout==NULL)
	{
		printf("Cannot open the file!\n");
		return ;
	
	}
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",*(num+i));
		fprintf(fpout,"%d\n",*(num+i));

	}
	fclose(fpout);

}


