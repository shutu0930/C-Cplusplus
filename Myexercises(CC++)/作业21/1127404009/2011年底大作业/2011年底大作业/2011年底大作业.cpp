// 2011年底大作业.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<string.h>
#define N 500
#define M 100
#define LEN sizeof(struct StudentInfo)

int read(struct StudentInfo *person,int n,int m);
int deletestu(struct StudentInfo *person,int m,int n);
void count(struct StudentInfo *person,int n);
void sort(struct StudentInfo *person,int n);
void output(struct StudentInfo *person,int n);
struct StudentInfo
{
	char xh[12];	//学号
	char xm[12];	//姓名
	int  sex;		//性别0-表示女生1-表示男生
	int  dycj;		//德育成绩
	int  zycj;		//智育成绩
	int  tycj;		//体育成绩
	double zhcjpji; //综合测评成绩
};
void main()
{
	struct StudentInfo stdu1[N];
	struct StudentInfo *pstdu1=stdu1;			//结构数组的指针
	int count1,count2;

	
	count1=read(pstdu1,N,10);					//读文件
	printf("学生的人数：%d\n",count1);
	count2=deletestu(pstdu1,M,count1);			//删除作弊的学生
	printf("可评奖学金学生的人数：%d\n",count2);

	count(pstdu1,count2);						//计算学生的综合成绩
	sort(pstdu1,count2);						//按综合成绩从高到低给学生排名
	output(pstdu1,10);							//输出到文件，打印到屏幕

}
//==================================================
//	本函数用于读取数据并存放到数组中
//	参数说明：struct StudentInfo *person,int n,int m
//==================================================
int read(struct StudentInfo *person,int n,int m)
{
	FILE *fp;
	char sex[3];
	struct StudentInfo *pper=person;
	int count=0;
	fp=fopen("D:\\in.dat","rb");
	
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return -1;
	}
	printf("所有学生信息（前10位同学）：\n");
	while(fread(pper,LEN,1,fp)==1)
	{

		if(pper<person+m)
		{
			if(pper->sex==1)
		{
			strcpy(sex,"男");
		}else
		{
			strcpy(sex,"女");
		
		}
		printf("学号：%-12s姓名：%-8s性别：%-4s德育成绩：%-3d智育成绩：%-3d体育成绩：%-3d\n",pper->xh,pper->xm,sex,pper->dycj,pper->zycj,pper->tycj);
		
		}
		count++;
		pper++;
		
	}
	/*
		if(feof(fp))
		{
			fclose(fp);
			return count;
		}
		printf("file read error!");*/
	
	
		
	
	fclose(fp);
	return count;
	
}
//==================================================
//	本函数用于删除数组中相应的数据
//	参数说明：struct StudentInfo *person,int n,int m
//==================================================
int deletestu(struct StudentInfo *person,int m,int n)
{
	FILE *fp;
	struct StudentInfo *pper=person;
	int i,j,k,p;
	char stdu2[M][12];
	fp=fopen("D:\\filter.txt","r");
	
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return -1;
	}
	for(k=0;k<m;k++)
	{		
		fscanf(fp,"%s\n",stdu2[k]);
		/*printf("%s\n",stdu2[k]);*/
		for(p=0;p<59;p++)
		{
			if(strcmp((pper+p)->xh,stdu2[k])==0)
			{
				/*printf("%s\n",stdu2[k]);*/
				n--;
				for(i=j=0;i<n;i++)
				{
					if(strcmp((pper+i)->xh,stdu2[k])!=0)
					{
						if(i!=j)
						{
							*(pper+j)=*(pper+i);
						}
						j++;
					}
				}
			}
			
		}	
	}
	
	return n;
}
//==================================================
//	本函数用于计算学生的综合成绩
//	参数说明：struct StudentInfo *person,int n
//==================================================
void count(struct StudentInfo *person,int n)
{
	struct StudentInfo *pper=person;

	for(;pper<person+n;pper++)
	{
		pper->zhcjpji=pper->dycj*0.1+pper->zycj*0.7+pper->tycj*0.2;
	}
	

}
//==================================================
//	本函数用于按综合成绩将可获得奖学金的学生排名
//	参数说明：struct StudentInfo *person,int n
//==================================================
void sort(struct StudentInfo *person,int n)
{
	struct StudentInfo *pper=person;
	struct StudentInfo temp;
	int i,j;
	
	for(i=0;i<n-1;i++)						//选择排序法
	{
		for(j=i+1;j<n;j++)
		{
			if((pper+i)->zhcjpji<(pper+j)->zhcjpji)
			{
				temp=*(pper+i);
				*(pper+i)=*(pper+j);
				*(pper+j)=temp;
			
			}
			
		
		}
	
	}


}
//===========================================================
//	本函数用于将可获得奖学金学生前10名的信息输出到文件并打印
//	参数说明：struct StudentInfo *person,int n
//===========================================================
void output(struct StudentInfo *person,int n)
{
	FILE *fpout;
	struct StudentInfo *pper=person;
	fpout=fopen("D:\\out.txt","w");

	if(fpout==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	printf("\n可评奖学金学生名单（前10名）：\n");
	for(;pper<person+n;pper++)
	{	

		fprintf(fpout,"学号：%-12s姓名：%-12s德育成绩：%4d智育成绩：%4d体育成绩：%4d综合测评成绩：%.2lf\n",pper->xh,pper->xm,pper->dycj,pper->zycj,pper->tycj,pper->zhcjpji);
		printf("学号：%-12s姓名：%-12s德育成绩：%4d智育成绩：%4d体育成绩：%4d综合测评成绩：%.2lf\n",pper->xh,pper->xm,pper->dycj,pper->zycj,pper->tycj,pper->zhcjpji);
	}

	fclose(fpout);


}