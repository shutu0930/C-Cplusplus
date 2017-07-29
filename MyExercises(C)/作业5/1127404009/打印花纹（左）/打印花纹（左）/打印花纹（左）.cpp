// 打印花纹（左）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>

void main()
{
	int i,j,num;

	printf("请输入您要打印“*”的行数：");			//让用户输入打印的行数	
	scanf("%d",&num);

	for(i=1;i<=num;i++)							//i表示行数，j表示列数
	{
		for(j=1;j<=i;j++)						//for循环嵌套
		{
			printf("* ");
		}
	printf("\n");								//换行
	
	}


}

