// 验证哥德巴赫猜想.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
void main()
{
	int oushu,jishu,jizhishu1,jizhishu2,n,i;
	

	for(oushu=6;;oushu+=2)
	{	
		for(jizhishu1=1;jizhishu1<oushu;jizhishu1+=2)
		{
			n=(int)sqrt(jizhishu1);
			
		}
		for(i=1;i<=n;i+=2)
		{
			if(jizhishu1%i==0) break;
		
		}
		
		if(i>=n+1)
		{	
			jizhishu2=oushu-jizhishu1;
			
			n=(int)sqrt(jizhishu2);
		
			
			for(i=1;i<=n;i+=2)
			{
				if(jizhishu2%i==0) break;
			
			}

			if(i>=n+1) printf("%d=%d+%d\n",oushu,jizhishu1,jizhishu2);
			
		}







	}




}

