// ��֤��°ͺղ��루�Ľ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>

int qiuzhi(int x)		//��֤һ�����Ƿ�Ϊ�����ĺ������Ա�������
{
	int b,c,d;						
	c=(int)sqrt(x*1.0);
	for(b=2;b<=c;b++)
	{	
		if(x%b==0) 
		{	
			d=0;break;
		}
	}
	if(b>=c+1) d=1;
		
	return(d);				//����d��ֵ����dΪ��0��˵������Ϊ����
	
}

void main()					//������
{
	int oushu,jizhishu1,jizhishu2;
	
	do
	{
	printf("������һ����С��6��ż����");		//���û������Ա���֤��°ͺղ����һ��
	scanf("%d",&oushu);
	}while(oushu<6||oushu%2!=0);

	
	for(jizhishu1=1;jizhishu1<oushu;jizhishu1+=2)
	{
		jizhishu2=oushu-jizhishu1;				//����һ��������
		
		if(qiuzhi(jizhishu1)!=0 && qiuzhi(jizhishu2)!=0 && jizhishu2>jizhishu1)	//������֤�����ĺ�������֤�������Ƿ��Ϊ������
				printf("%d������%d��%d��ɣ���˸�°ͺղ����һ��������\n",oushu,jizhishu1,jizhishu2);	//��֤����Ҫ�����
		
			
	}
		

	
	int jishu,zhishu1,zhishu2,zhishu3;
	
	do
	{
	printf("������һ����С��9��������");		//���û������Ա���֤��°ͺղ���ڶ���
	scanf("%d",&jishu);
	}while(jishu<9||jishu%2==0);



	
	for(zhishu1=1;zhishu1<jishu;zhishu1+=2)
	{
		
		if(qiuzhi(zhishu1)!=0)					//��֤������1�Ƿ����Ҫ��
		{
					
			for(zhishu2=zhishu1+1;zhishu2<jishu;zhishu2++)
			{
				
				
				if(qiuzhi(zhishu2)!=0)			//������2����
				{
					zhishu3=jishu-zhishu1-zhishu2;
					
					if(zhishu3>=zhishu2 && qiuzhi(zhishu3)!=0)	//��֤������3�Ƿ����Ҫ��
					{
						printf("%d������%d��%d��%d��ɣ���˸�°ͺղ���ڶ���������\n",jishu,zhishu1,zhishu2,zhishu3);	//����Ҫ������
				
					}
		
				}
			}
	
		}
	}





}