// 第四题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#define N 50
void read(char *str);
void sort(char *str,int n);
void merge(char *str1,char *str2,char *str3,int n);
void output(char *str);
void main()
{
	char str1[N],str2[N],str3[2*N];
	char *pstr1=str1,*pstr2=str2,*pstr3=str3;
	int num1,num2,num;
	num1=read(str1);
	num2=read(str2);
	num=num1>num2?num2:num1;
	merge(str1,str2,str3,num);
	output(str);
}
//========================================
//	
//	 
//	
//========================================
int read(char *str)
{
	FILE *fp;
	char filename[N];
	printf("Please enter the first filename :\n");
	gets(filename);

	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	for(i=0;!feof(fp);i++)
	{
		*(str+i)=fgetc(fp);
		putchar(*(str+i));
	}
	return i;
	sort(str,i);



}
//================================
//	
//	
//================================

void sort(char *str,int n)
{
	int i,j;
	char temp;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(str[i]>str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
	
	puts(str);
	
}
//==========================================
//	
//
//	
//==========================================
void merge(char *str1,char *str2,char *str3,int n)
{
	int i,j,k;
	i=j=k=0;
	
	while(i<n&&j<n)
	{
		if(str1[i]<str2[j])
		{
			str3[k]=str1[i];
			i++;
		}
		else if(str1[i]>str2[j])
		{
			str3[k]=str2[j];
			j++;
		}
		else
		{
			str3[k]=str1[i];
				j++;
				i++;
		}
		k++;
	}
	
	while(i<n)
	{
		str3[k]=str1[i];
			i++;
			k++;
	
	}
	while(j<N)
	{
		str3[k]=str2[j];
			j++;
			k++;
	
	}
	str3[k]=0;
	puts(str3);
	
		
}
void output(char *str)
{
	FILE *fp;
	char filename[N];
	printf("Please enter the first filename :\n");
	gets(filename);

	fp=fopen(filename,"w");
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}

	fputs(str,fp);


}




