// ��ʮ������ת���ɶ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define N 8
int convert(int *pnum,int divid,int n);
void main()
{
	int num[N],i,num1,num2;
	int *pnum=num;
	printf("������һ��ʮ��������\n");
	scanf("%d",&num1);

	num2=convert(pnum,num1,N);
	printf("����ת���ɶ�����Ϊ��\n");

	if(num1<0)						//���������Ϊ��������ǰ����1��ʾ����
	{
		num[N-1]=1;
		num2=N-1;
	}
	for(i=num2;i>=0;i--)
	{
		
		printf("%d",num[i]);		//����������ʽ���
		
	}
	printf("\n");
}
//=====================================
//���������ڽ�һ��ʮ������ת��Ϊ��������ʽ
//����˵����int *pnum,int divid,int n
//����ֵ������������λ��
//=====================================
int convert(int *pnum,int divid,int n)		
{
	int i,remain,cons;
	if(divid<0)
	{
		divid=-1*divid;				//����Ϊ������ȡ�����ֵ
		for(i=0;i<n;i++)
		{
			*(pnum+i)=0;
		}
	}
	i=0;
	do
	{
		cons=divid/2;
		remain=divid%2;
		*(pnum+i)=remain;
		divid=cons;
		i++;

	}while(cons!=0);
	
	
	return i-1;


}