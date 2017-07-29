// 第九题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>

void main()
{
	int num,place;
	printf("请输入一个不多于5位的正整数："); 
	scanf("%d",&num);

	while(num>99999||num<0)					//输入有误时，重新输入，直到数据正确
	{
	printf("输入数据错误，请重新输入：");
	scanf("%d",&num);
	}
	
	if(num>9999) place=5;					//求该数是几位数
	else if(num>999) place=4;
	else if(num>99) place=3;
	else if(num>9) place=2;
	else place=1;

	printf("它是%d位数\n",place);


	printf("每一位数字分别为：");			
	int ten_thousand,thousand,hundred,ten,indiv;

	ten_thousand=(int)(num/10000);
	thousand=(int)(num-10000*ten_thousand)/1000;
	hundred=(int)(num-10000*ten_thousand-1000*thousand)/100;											//求分别输出每一位数字
	ten=(int)(num-10000*ten_thousand-1000*thousand-100*hundred)/10;
	indiv=num-10000*ten_thousand-1000*thousand-100*hundred-10*ten;
																				
	
	switch(place)																						//选择分支																
	{
	case(5):printf("%d,%d,%d,%d,%d",ten_thousand,thousand,hundred,ten,indiv);
			printf("\n按逆序输出各位数字：%d%d%d%d%d",indiv,ten,hundred,thousand,ten_thousand);break;   //让该数按逆序输出
	
	case(4):printf("%d,%d,%d,%d",thousand,hundred,ten,indiv);
			printf("\n按逆序输出各位数字：%d%d%d%d",indiv,ten,hundred,thousand);break;
	
	case(3):printf("%d,%d,%d",hundred,ten,indiv);
			printf("\n按逆序输出各位数字：%d%d%d",indiv,ten,hundred);break;
	
	case(2):printf("%d,%d",ten,indiv);
			printf("\n按逆序输出各位数字：%d%d",ten,indiv);break;
	
	case(1):printf("%d",indiv);
			printf("\n按逆序输出各位数字：%d",indiv);break;
	
	
	}








}

