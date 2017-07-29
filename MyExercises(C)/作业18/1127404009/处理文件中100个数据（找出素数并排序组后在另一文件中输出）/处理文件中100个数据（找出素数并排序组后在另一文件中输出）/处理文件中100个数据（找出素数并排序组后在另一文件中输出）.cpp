// 处理文件中100个数据（找出素数并排序组后在另一文件中输出）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<math.h>
#include<string.h>
#define N 100

void read(int *num);
int prime(int *num1,int *num2);
void sort(int *num,int n);
void write_print(int *num,int n);
void main()
{
	int num1[N],num2[N],count;			//定义两个整形数组，一个用于存放读出的数据，一个用于存放其中的所有质数
	
	read(num1);						//从文件中读数据
	count=prime(num1,num2);			//求数据中所有质数
	sort(num2,count);					//将所有质数排序
	write_print(num2,count);			//输出到另一文件中


}
//=======================================
//本函数用于用二进制读取文件中的数据
//参数说明：int *num指针
//=======================================
void read(int *num)
{
	FILE *fp;
	char filename1[N];
	printf("Please input the filename1 to read data :\n");
	gets(filename1);
	fp=fopen(filename1,"rb");
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	
	}
	int i;
	for(i=0;i<N;i++)
	{
		if(fread(num+i,sizeof(int),1,fp)!=1)
		{
			if(feof(fp))
			{
				fclose(fp);
				return;
			}
			printf("Cannot read the file!\n");
		}
	
	
	printf("%d\t",*(num+i));
	
	}
	fclose(fp);

}
//=======================================
//本函数用于求数组中所有的质数
//参数说明：int *num指针
//返回值：int count 质数的个数
//=======================================
int prime(int *num1,int *num2)
{
	int i,k,j,count=0;
	printf("\nThe prime number :\n");
	for(i=0;i<N;i++)
	{
		k=sqrt(*(num1+i)*1.0);
		for(j=2;j<=k;j++)
		{
			if(*(num1+i)%j==0)
				break;
		}
		if(j>k)
		{
			printf("%d\t",*(num1+i));
			*(num2+count)=*(num1+i);
			count++;
		}
	
	}
	printf("\n");
	return count;

}
//==========================================
//本函数用于将数组排序
//参数说明：int *num指针 int n数组中实际个数
//==========================================
void sort(int *num,int n)
{
	int temp,i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(num+i)>*(num+j))				//选择法排序
			{
				temp=*(num+i);
				*(num+i)=*(num+j);
				*(num+j)=temp;
			}
		}
	}
	printf("After being sorted :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",*(num+i));
	}

}
//=======================================
//本函数用于将处理好的数据输出到另一个文件
//参数说明：int *num指针 int n
//=======================================
void write_print(int *num,int n)
{
	FILE *fpout;
	char filename2[N];
	printf("\nPlease input the filename2 to write data :\n");
	gets(filename2);
	fpout=fopen(filename2,"w");
	if(fpout==NULL)
	{
		printf("Cannot open the file!\n");
		return ;
	
	}
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",*(num+i));
		fprintf(fpout,"%d\n",*(num+i));

	}
	fclose(fpout);

}


