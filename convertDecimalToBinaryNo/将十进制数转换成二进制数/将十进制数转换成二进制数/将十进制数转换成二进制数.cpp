// 将十进制数转换成二进制数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define N 8
int convert(int *pnum,int divid,int n);
void main()
{
	int num[N],i,num1,num2;
	int *pnum=num;
	printf("请输入一个十进制数：\n");
	scanf("%d",&num1);

	num2=convert(pnum,num1,N);
	printf("该数转换成二进制为：\n");

	if(num1<0)						//若输入的数为负数，最前面是1表示负号
	{
		num[N-1]=1;
		num2=N-1;
	}
	for(i=num2;i>=0;i--)
	{
		
		printf("%d",num[i]);		//将二进制形式输出
		
	}
	printf("\n");
}
//=====================================
//本函数用于将一个十进制数转换为二进制形式
//参数说明：int *pnum,int divid,int n
//返回值：二进制数的位数
//=====================================
int convert(int *pnum,int divid,int n)		
{
	int i,remain,cons;
	if(divid<0)
	{
		divid=-1*divid;				//若数为负数先取其绝对值
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