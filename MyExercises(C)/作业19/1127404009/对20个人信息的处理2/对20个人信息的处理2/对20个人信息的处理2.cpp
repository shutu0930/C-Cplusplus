// 对20个人信息的处理2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string.h>
#define N 20
#define LEN sizeof(struct Information)

int read(struct Information *person,int n);
void print(struct Information *person,int n);
void aver(struct Information *person,double *paverf,double *paverm,int n);
int deleteper(struct Information *person,int n);
void sort(struct Information *person,int n);
void output(struct Information *person,int n);
struct Information										
{
	char name[12];										//定义结构数组
	int sex;
	char phoneNumber[12];
	int age;
};
void main()
{
	struct Information person[N];
	int count,m;										//分别定义男女平均年龄值double型
	double averf,averm;
	double *paverf=&averf,*paverm=&averm;				//分别定义指针指向两个平均值
	
	m=read(person,N);										//调用函数读出文件中的数据并将其存放在结构数组中
	print(person,m);									//调用函数将结构数组中的数据打印到屏幕上
	aver(person,paverf,paverm,N);							//调用函数求结构数组中男女的平均年龄
	
	printf("\n女人的平均年龄：%.3lf\n男人的平均年龄：%.3lf\n",averf,averm);			//将结果显示到屏幕上
		
	count=deleteper(person,N);							//count为删除后数组中实际元素的个数
	sort(person,count);									//调用函数对数组中的数据按年龄由大到小排序
	output(person,count);								//将处理好的数组输出到另一个文件中并打印到屏幕上

}
//================================================
//本函数用于读出文件中的数据并将其存放在结构数组中
//参数值：const struct Information *person
//================================================
int read(struct Information *person,int n)
{
	FILE *fp;
	struct Information *pper=person;
	fp=fopen("D:\\12月20日C作业数据文件.dat","rb");
	
	if(fp==NULL)
	{
		return -1;
	}
	
	for(;pper<person+n;pper++)
	{
		if(fread(pper,LEN,1,fp)!=1)
		{
			if(feof(fp))
			{
				fclose(fp);
				return 0;
			}
			return 1;
		}
		
				
	}
	
	fclose(fp);
	
}
//================================================================
//本函数用于将结构数组中的数据打印到屏幕上
//参数值：const struct Information *person,int n(函数read的返回值)
//===============================================================
void print(struct Information *person,int n)
{
	int i;
	char sex[3];

	if(n==-1)
	{
		printf("Cannot open the file!\n");							//函数read的返回值若为-1，说明文件打开失败
	
	}
	else if(n==1)
	{
		printf("file read error!");									//若是1说明读文件时出现错误
	
	}
	else
	{struct Information *pper=person;								//若不是以上便说明读取数据成功，将其打印
		for(;pper<person+N;pper++)
		{
			if(pper->sex==1)
			{
				strcpy(sex,"女");
			}else
			{
				strcpy(sex,"男");
			
			}
			printf("姓名：%-10s性别：%-5s联系号码：%-12s年龄：%3d\n",pper->name,sex,pper->phoneNumber,pper->age);	
			
		}
	
	}


}
//================================================
//本函数用于求结构数组中男女的平均年龄
//参数值const struct Information *person
//double *paverf,double *paverm（指向平均数的指针）
//================================================
void aver(struct Information *person,double *paverf,double *paverm,int n)
{
	int fnum=0,mnum=0,sumf=0,summ=0;

	struct Information *pper=person;
	for(;pper<person+n;pper++)
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
//============================================
//本函数用于删除数组中年龄>60和<18的人的资料
//参数值：const struct Information *person
//返回值：return j（删除后数组中剩余元素的个数）
//============================================
int deleteper(struct Information *person,int n)
{
	int i,j;
	struct Information *pper=person;
	for(i=j=0;i<n;i++)
	{
		if((pper+i)->age>=18&&(pper+i)->age<=60&&i!=j)
		{
			*(pper+j)=*(pper+i);
			j++;
		
		}
	}

	return j;

}
//========================================
//本函数用于对数组中的数据按年龄由大到小排序
//参数值：const struct Information *person,int n
//（指向数组的指针，数组中实际元素的个数）
//========================================
void sort(struct Information *person,int n)
{
	int i,j;
	struct Information *pper=person;			
	struct Information temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)					//选择法排序
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
//========================================================
//本函数用于将处理好的数组输出到另一个文件中并打印到屏幕上
//参数值：const struct Information *person,int n
//（指向数组的指针，数组中实际元素的个数）
//========================================================
void output(struct Information *person,int n)
{
	FILE *fpout;
	char sex[3];
	fpout=fopen("D:\\out.txt","w");

	if(fpout==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	
	struct Information *pper=person;
	printf("\n年龄>=18且<=60的人：\n");
	for(;pper<person+n;pper++)
	{
		if(pper->sex==1)
		{
			strcpy(sex,"女");
		}else
		{
			strcpy(sex,"男");
		
		}
		fprintf(fpout,"姓名：%-10s性别：%-5s联系号码：%-12s年龄：%3d\n",pper->name,sex,pper->phoneNumber,pper->age);	
		printf("姓名：%-10s性别：%-5s联系号码：%-12s年龄：%3d\n",pper->name,sex,pper->phoneNumber,pper->age);	
	}


}