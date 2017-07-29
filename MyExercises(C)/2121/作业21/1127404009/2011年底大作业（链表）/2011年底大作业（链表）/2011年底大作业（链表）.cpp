// 2011年底大作业（链表）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string.h>
#include<stdlib.h>
#define M 100
#define LEN sizeof(struct StudentInfo)

struct StudentInfo *readData(int m,struct StudentInfo *head,int *count);
struct StudentInfo *addAnode(struct StudentInfo *head,struct StudentInfo temp);
struct StudentInfo *del(struct StudentInfo *head,int n,int m,int *count);				//函数声明
struct StudentInfo *deletestu(struct StudentInfo *head,char num[]);
void count(struct StudentInfo *head);
void sort(struct StudentInfo *head,int n);
void output(struct StudentInfo *head,int n);
void print(struct StudentInfo *head,int n);
struct StudentInfo
{
	char xh[12];	//学号
	char xm[12];	//姓名
	int  sex;		//性别0-表示女生1-表示男生
	int  dycj;		//德育成绩
	int  zycj;		//智育成绩
	int  tycj;		//体育成绩
	double zhcjpji; //综合测评成绩
	struct StudentInfo *next;
};
void main()
{
	struct StudentInfo *head=0;				//定义文件头指针
	int count1,count2;						//count1为总的学生人数，count2为删除后的学生人数
	

	
	head=readData(10,head,&count1);			//读文件并连接到动态链表中
	printf("学生的人数：%d\n",count1);
	head=del(head,count1,M,&count2);		//删除
	count(head);							//计算综合成绩
	sort(head,count2);						//排序
	printf("可评奖学金学生的人数：%d\n",count2);
	output(head,10);						//打印和输出

	

}
//==========================================================
//	本函数用于读取文件中的数据并附到链表中
//	参数说明：int m  打印到屏幕上的人数
//			struct StudentInfo *head  链表的头指针
//			int *count 	读取的信息的人数的指针
//	返回值：return head  链表的头指针
//========================================================
struct StudentInfo *readData(int m,struct StudentInfo *head,int *count)
{
	FILE *fp;
	struct StudentInfo temp;
	/*struct StudentInfo *pper=head;*/
	*count=0;
	fp=fopen("D:\\in.dat","rb");
	
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return head;
	}
	
	while(fread(&temp,LEN-8,1,fp)==1)
	{
		/*printf("%s%s\n",temp.xh,temp.xm);*/
		head=addAnode(head,temp);					//调用链表加结点的函数
		(*count)++;
	}
	/*
		if(feof(fp))
		{
			fclose(fp);
			return count;
		}
		printf("file read error!");*/
	printf("所有学生信息（前10位同学）：\n");
	print(head,10);									//调用print函数打印前10名学生的信息
	
	fclose(fp);
	return head;									//返回链表的头指针
	
}
//==========================================================
//	本函数用于数据附到链表中，并逐一增加链表的节点
//	参数说明：struct StudentInfo temp 要加到链表中的数据结构体
//			struct StudentInfo *head  链表的头指针
//	返回值：return head  链表的头指针
//========================================================
struct StudentInfo *addAnode(struct StudentInfo *head,struct StudentInfo temp)
{
	struct StudentInfo *ptemp=(struct StudentInfo *)malloc(LEN);

	if(ptemp==0)
	{
		return head;
	}
	*ptemp=temp;
	ptemp->next=0;
	if(head==0)
	{
		head=ptemp;
	}
	else
	{
		struct StudentInfo *p=head;
		while(p->next)
		{
			p=p->next;
		}
		p->next=ptemp;
		ptemp->next=0;
	}

	return head;

}
//==========================================================
//	本函数用于删除作弊的学生信息
//	参数说明：int n 总共的学生数  int m 文件中存储的学号个数
//			struct StudentInfo *head  链表的头指针
//			int *count 指向删除后剩余学生个数的指针
//	返回值：return head  链表的头指针
//========================================================
struct StudentInfo *del(struct StudentInfo *head,int n,int m,int *count)
{
	FILE *fp;
	struct StudentInfo *pper;
	int k;
	char stdu2[M][12];
	fp=fopen("D:\\filter.txt","r");
	*count=0;
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return head;
	}
	for(k=0;k<m;k++)
	{
		fscanf(fp,"%s",stdu2[k]);
		/*printf("%s",stdu2[k]);*/
		for(pper=head;pper!=0;pper=pper->next)
		{
			if(strcmp(pper->xh,stdu2[k])==0)
			{
				n--;
				head=deletestu(head,stdu2[k]);			//调用删除链表结点的函数
			}
		}
	
	}
	*count=n;											
	return head;


}
//==========================================================
//	本函数用于删除链表中某一相应的结点
//	参数说明：char num[]  要删除的学生的学号
//			struct StudentInfo *head  链表的头指针
//	返回值：return head  链表的头指针
//========================================================
struct StudentInfo *deletestu(struct StudentInfo *head,char num[])
{
	struct StudentInfo *p1,*p2;
	/*p=q=head;*/
	if(head==NULL)
	{
		return head;
	}
	p1=head;
	while(strcmp(num,p1->xh)!=0&&p1->next!=0)
	{
		p2=p1;
		p1=p1->next;
	}
	if(strcmp(num,p1->xh)==0)
	{
		if(p1==head)
		{
			head=p1->next;
			free(p1);
		}else
		{
			p2->next=p1->next;
			/*free(p1);*/
		
		}
	}
	else
	{
		
		printf("not found!\n");
		return head;
	
	}
	return head;
	
	/*while(p)
	{
		if(strcmp(p->xh,num)==0)
		{
			break;
		}
		q=p;
		p=p->next;
	}											//老师写的为毛运行不了？TT
	if(p==head)
	{
		head=head->next;
		free(p);
	}
	else 
		if(p)
		{
			q->next=p->next;
			free(p);
		}
	return head;*/
	
}
//==========================================================
//	本函数用于计算可获得奖学金学生的综合成绩
//	参数说明：struct StudentInfo *head  链表的头指针
//========================================================
void count(struct StudentInfo *head)
{
	struct StudentInfo *pper=head;

	if(head!=NULL)
	{
		do
		{
			pper->zhcjpji=pper->dycj*0.1+pper->zycj*0.7+pper->tycj*0.2;
			/*printf("%.2lf\n",pper->zhcjpji);*/
			pper=pper->next;
		}while(pper!=NULL);
		
	}
	

}
//==========================================================
//	本函数用于将奖学金学生按综合成绩进行排名
//	参数说明：struct StudentInfo *head  链表的头指针
//				int n  链表个数
//========================================================
void sort(struct StudentInfo *head,int n)
{
	struct StudentInfo *p,*q;
	struct StudentInfo temp;
	temp.next=0;
	int i,j;
	p=q=head;
	
	
	for(i=0;i<n-1;i++)
	{	
		q=p=head;
		
		if(head->next!=NULL)					//排序
		{
			p=p->next;
		}
		while(p)/*for(j=0;j<n-i;j++)*/
		{
			
			if((q->zhcjpji)<(p->zhcjpji))
			{
				temp=*q;
				*q=*p;
				*p=temp;
				
				p->next=q->next;
				q->next=p;
				
			}
			p=p->next;
			q=q->next;
		}
	
	}
	

}
//==========================================================
//	本函数用于输出可获得前10名奖学金学生到文件中
//	参数说明：struct StudentInfo *head  链表的头指针
//				int n 要打印的学生的个数
//========================================================
void output(struct StudentInfo *head,int n)
{
	FILE *fpout;
	struct StudentInfo *pper=head;
	fpout=fopen("D:\\out.txt","w");
	int i=0;
	if(fpout==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	printf("可评奖学金学生名单（前10名）：\n");
	if(head!=NULL)
	{	
		
		do
		{
			
			if(i<n)
			{
				fprintf(fpout,"学号：%-12s姓名：%-12s德育成绩：%4d智育成绩：%4d体育成绩：%4d综合测评成绩：%.2lf\n",pper->xh,pper->xm,pper->dycj,pper->zycj,pper->tycj,pper->zhcjpji);
				printf("学号：%-12s姓名：%-12s德育成绩：%4d智育成绩：%4d体育成绩：%4d综合测评成绩：%.2lf\n",pper->xh,pper->xm,pper->dycj,pper->zycj,pper->tycj,pper->zhcjpji);
				i++;
			}
			else break;
			pper=pper->next;
		}while(pper!=NULL);
		
	}

	fclose(fpout);


}
//==========================================================
//	本函数用于打印学生信息
//	参数说明：struct StudentInfo *head  链表的头指针
//				int n 要打印的学生的个数
//========================================================
void print(struct StudentInfo *head,int n)
{
	char sex[3];
	struct StudentInfo *p;
	p=head;
	int i=0;
	if(head!=NULL)
	{
		
			do
			{
				if(i<n)
				{
					if(p->sex==1)
					{
						strcpy(sex,"男");
					}else
					{
						strcpy(sex,"女");
					
					}
					printf("学号：%-12s姓名：%-8s性别：%-4s德育成绩：%-3d智育成绩：%-3d体育成绩：%-3d\n",p->xh,p->xm,sex,p->dycj,p->zycj,p->tycj);
					p=p->next;
				
					i++;
				}
				else break;
				
			
			}while(p!=NULL);

		
			

	}



}
