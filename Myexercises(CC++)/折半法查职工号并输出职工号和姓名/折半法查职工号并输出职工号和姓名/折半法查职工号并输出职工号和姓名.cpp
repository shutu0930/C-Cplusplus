// 折半法查职工号并输出职工号和姓名.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#define N 10
#include<string.h>
void main()
{
	void input(int num[],char name[][8]);
	void sort(int num[],char name[][8]);
	void search(int num1,int num[],char name[][8]);

	int num[N],num1;
	char name[N][8];

	input(num,name);
	sort(num,name);
	
	printf("Please input a number to look for :\n");
	scanf("%d",&num1);
	search(num1,num,name);






}
void input(int num[],char name[][8])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("NO.:");
		scanf("%d",&num[i]);
		printf("Name:");
		getchar();
		gets(name[i]);
	
	}





}
void sort(int num[],char name[][8])
{
	int i,j,temp1;
	char temp2[8];

	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(num[i]>num[j])
			{
				temp1=num[i];
				num[i]=num[j];
				num[j]=temp1;


				strcpy(temp2,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp2);
			}
		}
	}
	printf("After being sorted :\nNO.\tName\n");
	for(i=0;i<N;i++)
	{
		printf("%d\t%s\n",num[i],name[i]);
	
	}


}
void search(int num1,int num[],char name[][8])
{
	int top,bott,mid,loca,sign;

	top=0;bott=N-1;loca=0;sign=1;

	if((num1<num[0])||(num1>num[N-1]))
		loca=-1;
	while((sign==1)&&(top<=bott))
	{
		mid=(top+bott)/2;
		if(num1==num[mid])
		{
			loca=mid;
			printf("NO.%d,his/her name is :%s.\n",num1,name[loca]);
			sign=-1;
		
		
		}
		else if(num1<num[mid])
			bott=mid-1;
		else
			top=mid+1;
	}
	
	if(sign==1||loca==-1)
		printf("%d not been found.\n",num1);





}



