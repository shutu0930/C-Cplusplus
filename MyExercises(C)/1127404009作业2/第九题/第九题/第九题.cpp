// �ھ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>

void main()
{
	int num,place;
	printf("������һ��������5λ����������"); 
	scanf("%d",&num);

	while(num>99999||num<0)					//��������ʱ���������룬ֱ��������ȷ
	{
	printf("�������ݴ������������룺");
	scanf("%d",&num);
	}
	
	if(num>9999) place=5;					//������Ǽ�λ��
	else if(num>999) place=4;
	else if(num>99) place=3;
	else if(num>9) place=2;
	else place=1;

	printf("����%dλ��\n",place);


	printf("ÿһλ���ֱַ�Ϊ��");			
	int ten_thousand,thousand,hundred,ten,indiv;

	ten_thousand=(int)(num/10000);
	thousand=(int)(num-10000*ten_thousand)/1000;
	hundred=(int)(num-10000*ten_thousand-1000*thousand)/100;											//��ֱ����ÿһλ����
	ten=(int)(num-10000*ten_thousand-1000*thousand-100*hundred)/10;
	indiv=num-10000*ten_thousand-1000*thousand-100*hundred-10*ten;
																				
	
	switch(place)																						//ѡ���֧																
	{
	case(5):printf("%d,%d,%d,%d,%d",ten_thousand,thousand,hundred,ten,indiv);
			printf("\n�����������λ���֣�%d%d%d%d%d",indiv,ten,hundred,thousand,ten_thousand);break;   //�ø������������
	
	case(4):printf("%d,%d,%d,%d",thousand,hundred,ten,indiv);
			printf("\n�����������λ���֣�%d%d%d%d",indiv,ten,hundred,thousand);break;
	
	case(3):printf("%d,%d,%d",hundred,ten,indiv);
			printf("\n�����������λ���֣�%d%d%d",indiv,ten,hundred);break;
	
	case(2):printf("%d,%d",ten,indiv);
			printf("\n�����������λ���֣�%d%d",ten,indiv);break;
	
	case(1):printf("%d",indiv);
			printf("\n�����������λ���֣�%d",indiv);break;
	
	
	}








}

