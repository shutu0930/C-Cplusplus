// 验证哥德巴赫猜想（改进）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>

int qiuzhi(int x)		//验证一个数是否为质数的函数，以便后面调用
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
		
	return(d);				//返回d的值，若d为非0，说明该数为质数
	
}

void main()					//主函数
{
	int oushu,jizhishu1,jizhishu2;
	
	do
	{
	printf("请输入一个不小于6的偶数：");		//让用户输入以便验证哥德巴赫猜想第一条
	scanf("%d",&oushu);
	}while(oushu<6||oushu%2!=0);

	
	for(jizhishu1=1;jizhishu1<oushu;jizhishu1+=2)
	{
		jizhishu2=oushu-jizhishu1;				//求另一个奇质数
		
		if(qiuzhi(jizhishu1)!=0 && qiuzhi(jizhishu2)!=0 && jizhishu2>jizhishu1)	//调用验证质数的函数，验证两个数是否均为奇质数
				printf("%d可以由%d和%d组成，因此哥德巴赫猜想第一条成立。\n",oushu,jizhishu1,jizhishu2);	//验证符合要求即输出
		
			
	}
		

	
	int jishu,zhishu1,zhishu2,zhishu3;
	
	do
	{
	printf("请输入一个不小于9的奇数：");		//让用户输入以便验证哥德巴赫猜想第二条
	scanf("%d",&jishu);
	}while(jishu<9||jishu%2==0);



	
	for(zhishu1=1;zhishu1<jishu;zhishu1+=2)
	{
		
		if(qiuzhi(zhishu1)!=0)					//验证奇质数1是否符合要求
		{
					
			for(zhishu2=zhishu1+1;zhishu2<jishu;zhishu2++)
			{
				
				
				if(qiuzhi(zhishu2)!=0)			//奇质数2符合
				{
					zhishu3=jishu-zhishu1-zhishu2;
					
					if(zhishu3>=zhishu2 && qiuzhi(zhishu3)!=0)	//验证奇质数3是否符合要求
					{
						printf("%d可以由%d，%d和%d组成，因此哥德巴赫猜想第二条成立。\n",jishu,zhishu1,zhishu2,zhishu3);	//符合要求就输出
				
					}
		
				}
			}
	
		}
	}





}