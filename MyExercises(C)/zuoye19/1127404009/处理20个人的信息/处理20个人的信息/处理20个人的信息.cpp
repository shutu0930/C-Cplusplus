// 处理20个人的信息.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string.h>
#define N 20
#define LEN sizeof(struct Information)

int read_write();
void print(int n);
struct Information
{
	char name[12];
	int sex;
	char phoneNumber[12];
	int age;
}person[N];
void main()
{
	
	print(read_write());
}
int read_write()
{
	FILE *fp;
	FILE *fpout;
	int i;
	char sex[3];
	fp=fopen("D:\\信息1.txt","r");
	fpout=fopen("D:\\信息2.txt","w");
	if(fp==NULL||fpout==NULL)
	{
		return -1;
	}
	
	for(i=0;i<N;i++)
	{
		if(fread(&person[i],LEN,1,fp)==1)
		{
			if(person[i].age>=18 && person[i].age<=60)
			{
				if(person[i].sex==1)
				{
					strcpy(sex,"女");
				}else
				{
					strcpy(sex,"男");
				
				}
				fprintf(fpout,"姓名：%-10s性别：%-5s联系号码：%-15s年龄：%3d\n",person[i].name,sex,person[i].phoneNumber,person[i].age);	
			
			}
			
		}
		else 
		{
			if(feof(fp))
			{
				fclose(fp);
				return 1;
			}
			return 0;
		}
	}
	
	fclose(fp);
	fclose(fpout);

}

void print(int n)
{
	int i;
	char sex[3];

	if(n==-1)
	{
		printf("Cannot open the file!\n");
	
	}
	else if(n==0)
	{
		printf("file read error!");
	
	}
	else
	{
		for(i=0;i<N;i++)
		{
			if(person[i].sex==1)
			{
				strcpy(sex,"女");
			}else
			{
				strcpy(sex,"男");
			
			}
			printf("姓名：%-10s性别：%-5s联系号码：%-15s年龄：%3d\n",person[i].name,sex,person[i].phoneNumber,person[i].age);	
			
		}
	
	}




}
