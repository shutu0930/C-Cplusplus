// 对20个人信息的处理2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string.h>
#define N 20
#define LEN sizeof(struct Information)

void read(const struct Information *person);
void print(const struct Information *person);
void aver(const struct Information *person,double *paverf,double *paverm);
int deleteper(const struct Information *person);
void sort(const struct Information *person,int n);
void output(const struct Information *person,int n);
struct Information
{
	char name[12];
	int sex;
	char phoneNumber[12];
	int age;
};
void main()
{
	struct Information person[N];
	int count;
	double averf,averm;
	double *paverf=&averf,*paverm=&averm;
	
	read(person);
	print(person);
	aver(person,paverf,paverm);
	printf("\n女人的平均年龄：%.3lf\n男人的平均年龄：%.3lf\n",averf,averm);
	count=deleteper(person);
	sort(person,count);
	output(person,count);

}
void read(const struct Information *person)
{
	FILE *fp;
	struct Information *pper=person;
	fp=fopen("D:\\12月20日C作业数据文件.dat","rb");
	
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	
	for(;pper<person+N;pper++)
	{
		if(fread(pper,LEN,1,fp)!=1)
		{
			if(feof(fp))
			{
				fclose(fp);
				return;
			}
			printf("file read error!");
		}
		
				
	}
	
	fclose(fp);
	
}

void print(const struct Information *person)
{
	int i;
	char sex[3];

	/*if(n==-1)
	{
		printf("Cannot open the file!\n");
	
	}else if(n==0)
	{
		printf("file read error!");
	
	}else*/
	{struct Information *pper=person;
		for(;pper<person+N;pper++)
		{
			if(pper->sex==1)
			{
				strcpy(sex,"女");
			}else
			{
				strcpy(sex,"男");
			
			}
			printf("姓名：%-10s性别：%-5s联系号码：%-15s年龄：%3d\n",pper->name,sex,pper->phoneNumber,pper->age);	
			
		}
	
	}


}

void aver(const struct Information *person,double *paverf,double *paverm)
{
	int fnum=0,mnum=0,sumf=0,summ=0;

	struct Information *pper=person;
	for(;pper<person+N;pper++)
	{
		if(pper->sex==1)
		{
			fnum++;
			sumf+=pper->age;
		}else
		{
			mnum++;
			summ+=pper->age;
		}
	}
	
	*(paverf)=sumf/fnum*1.0;
	*(paverm)=summ/mnum*1.0;

}

int deleteper(const struct Information *person)
{
	int i,j;
	struct Information *pper=person;
	for(i=j=0;i<N;i++)
	{
		if((pper+i)->age>=18&&(pper+i)->age<=60&&i!=j)
		{
			*(pper+j)=*(pper+i);
			j++;
		
		}
	}

	return j;

}

void sort(const struct Information *person,int n)
{
	int i,j;
	struct Information *pper=person;
	struct Information temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((pper+i)->age<(pper+j)->age || ((pper+i)->age==(pper+j)->age && (pper+i)->sex<(pper+j)->sex))
			{
				temp=pper[i];
				pper[i]=pper[j];
				pper[j]=temp;
			
			}
		
		}

	}

}

void output(const struct Information *person,int n)
{
	FILE *fpout;
	char sex[3];
	fpout=fopen("D:\\output.txt","w");

	if(fpout==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	
	struct Information *pper=person;
		for(;pper<person+n;pper++)
		{
			if(pper->sex==1)
			{
				strcpy(sex,"女");
			}else
			{
				strcpy(sex,"男");
			
			}
			fprintf(fpout,"姓名：%-10s性别：%-5s联系号码：%-15s年龄：%3d\n",pper->name,sex,pper->phoneNumber,pper->age);	
			printf("姓名：%-10s性别：%-5s联系号码：%-15s年龄：%3d\n",pper->name,sex,pper->phoneNumber,pper->age);	
		}


}