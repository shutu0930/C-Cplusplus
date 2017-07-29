// 验证哥德巴赫猜想.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
void main()
{
	int oushu,jizhishu1,jizhishu2,n,i;
	
	do
	{
	printf("请输入一个不小于6的偶数：");
	scanf("%d",&oushu);
	}while(oushu<6||oushu%2!=0);

	
	for(jizhishu1=1;jizhishu1<oushu;jizhishu1+=2)
	{
		n=(int)sqrt(jizhishu1*1.0);
		
	
		for(i=2;i<=n;i++)
		{
			if(jizhishu1%i==0) break;
		}
	
		
		if(i>=n+1)
		{	
			jizhishu2=oushu-jizhishu1;
			
			if(jizhishu2>jizhishu1)
			{
			n=(int)sqrt(jizhishu2*1.0);
		
			
			for(i=2;i<=n;i++)	
			{
				if(jizhishu2%i==0) break;
			}
			if(i>=n+1) 
				printf("%d可以由%d和%d组成，因此哥德巴赫猜想第一条成立。\n",oushu,jizhishu1,jizhishu2);
		
			}
		}
		

	}

	
	int jishu,zhishu1,zhishu2,zhishu3,k,j;
	
	do
	{
	printf("请输入一个不小于9的奇数：");
	scanf("%d",&jishu);
	}while(jishu<9||jishu%2==0);



	
	for(zhishu1=1;zhishu1<jishu;zhishu1+=2)
	{
		k=(int)sqrt(zhishu1*1.0);
		
	
		for(j=2;j<=k;j++)
		{
			if(zhishu1%j==0) break;
		}
		if(j>=k+1)
		{
					
			for(zhishu2=zhishu1+1;zhishu2<jishu;zhishu2++)
			{
				k=(int)sqrt(zhishu2*1.0);
				
			
				for(j=2;j<=k;j++)
				{
					if(zhishu2%j==0) break;
				}
				
				if(j>=k+1)
				{
					zhishu3=jishu-zhishu1-zhishu2;
					
					if(zhishu3>=zhishu2)
					{
					k=(int)sqrt(zhishu3*1.0);
				
					
					for(j=2;j<=k;j++)	
					{
						if(zhishu3%j==0) break;
					}
					if(j>=k+1) 
						printf("%d可以由%d，%d和%d组成，因此哥德巴赫猜想第二条成立。\n",jishu,zhishu1,zhishu2,zhishu3);
				
				
					}
		
				}
			}
		}
	}
	
		
}

