// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<stdlib.h>
void main()
{
	int num2,count=1;
	int num1=rand();									//�����ȡһ����

	printf("������������һ��������²¸���Ϊ���٣�");	//����һ��
	scanf("%d",&num2);

	while(num2!=num1)									//�´�ʱ
	{
		if(num2>num1)
		{
			printf("���µ���ƫ�����ٲ�һ�Σ�");		//��ʾ�µ���ƫ�󣬲��ۼƲµĴ���
			scanf("%d",&num2);
			count++;
		}
		else 
		{
			printf("���µ���ƫС�����ٲ�һ�Σ�");		//��ʾ�µ���ƫС�����ۼƲµĴ���
			scanf("%d",&num2);
			count++;
		}
	
	}


	printf("��ϲ���¶��ˣ����ܹ�����%d�Σ�\n",count);	//������µĴ���



}

