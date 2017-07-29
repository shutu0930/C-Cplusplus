// 2011��״���ҵ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string.h>
#include<stdlib.h>
#define M 100
#define LEN sizeof(struct StudentInfo)

struct StudentInfo *readData(int m,struct StudentInfo *head,int *count);
struct StudentInfo *addAnode(struct StudentInfo *head,struct StudentInfo temp);
struct StudentInfo *del(struct StudentInfo *head,int n,int m,int *count);				//��������
struct StudentInfo *deletestu(struct StudentInfo *head,char num[]);
void count(struct StudentInfo *head);
void sort(struct StudentInfo *head,int n);
void output(struct StudentInfo *head,int n);
void print(struct StudentInfo *head,int n);
struct StudentInfo
{
	char xh[12];	//ѧ��
	char xm[12];	//����
	int  sex;		//�Ա�0-��ʾŮ��1-��ʾ����
	int  dycj;		//�����ɼ�
	int  zycj;		//�����ɼ�
	int  tycj;		//�����ɼ�
	double zhcjpji; //�ۺϲ����ɼ�
	struct StudentInfo *next;
};
void main()
{
	struct StudentInfo *head=0;				//�����ļ�ͷָ��
	int count1,count2;						//count1Ϊ�ܵ�ѧ��������count2Ϊɾ�����ѧ������
	

	
	head=readData(10,head,&count1);			//���ļ������ӵ���̬������
	printf("ѧ����������%d\n",count1);
	head=del(head,count1,M,&count2);		//ɾ��
	count(head);							//�����ۺϳɼ�
	sort(head,count2);						//����
	printf("������ѧ��ѧ����������%d\n",count2);
	output(head,10);						//��ӡ�����

	

}
//==========================================================
//	���������ڶ�ȡ�ļ��е����ݲ�����������
//	����˵����int m  ��ӡ����Ļ�ϵ�����
//			struct StudentInfo *head  �����ͷָ��
//			int *count 	��ȡ����Ϣ��������ָ��
//	����ֵ��return head  �����ͷָ��
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
		head=addAnode(head,temp);					//��������ӽ��ĺ���
		(*count)++;
	}
	/*
		if(feof(fp))
		{
			fclose(fp);
			return count;
		}
		printf("file read error!");*/
	printf("����ѧ����Ϣ��ǰ10λͬѧ����\n");
	print(head,10);									//����print������ӡǰ10��ѧ������Ϣ
	
	fclose(fp);
	return head;									//���������ͷָ��
	
}
//==========================================================
//	�������������ݸ��������У�����һ��������Ľڵ�
//	����˵����struct StudentInfo temp Ҫ�ӵ������е����ݽṹ��
//			struct StudentInfo *head  �����ͷָ��
//	����ֵ��return head  �����ͷָ��
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
//	����������ɾ�����׵�ѧ����Ϣ
//	����˵����int n �ܹ���ѧ����  int m �ļ��д洢��ѧ�Ÿ���
//			struct StudentInfo *head  �����ͷָ��
//			int *count ָ��ɾ����ʣ��ѧ��������ָ��
//	����ֵ��return head  �����ͷָ��
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
				head=deletestu(head,stdu2[k]);			//����ɾ��������ĺ���
			}
		}
	
	}
	*count=n;											
	return head;


}
//==========================================================
//	����������ɾ��������ĳһ��Ӧ�Ľ��
//	����˵����char num[]  Ҫɾ����ѧ����ѧ��
//			struct StudentInfo *head  �����ͷָ��
//	����ֵ��return head  �����ͷָ��
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
	}											//��ʦд��Ϊë���в��ˣ�TT
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
//	���������ڼ���ɻ�ý�ѧ��ѧ�����ۺϳɼ�
//	����˵����struct StudentInfo *head  �����ͷָ��
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
//	���������ڽ���ѧ��ѧ�����ۺϳɼ���������
//	����˵����struct StudentInfo *head  �����ͷָ��
//				int n  �������
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
		
		if(head->next!=NULL)					//����
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
//	��������������ɻ��ǰ10����ѧ��ѧ�����ļ���
//	����˵����struct StudentInfo *head  �����ͷָ��
//				int n Ҫ��ӡ��ѧ���ĸ���
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
	printf("������ѧ��ѧ��������ǰ10������\n");
	if(head!=NULL)
	{	
		
		do
		{
			
			if(i<n)
			{
				fprintf(fpout,"ѧ�ţ�%-12s������%-12s�����ɼ���%4d�����ɼ���%4d�����ɼ���%4d�ۺϲ����ɼ���%.2lf\n",pper->xh,pper->xm,pper->dycj,pper->zycj,pper->tycj,pper->zhcjpji);
				printf("ѧ�ţ�%-12s������%-12s�����ɼ���%4d�����ɼ���%4d�����ɼ���%4d�ۺϲ����ɼ���%.2lf\n",pper->xh,pper->xm,pper->dycj,pper->zycj,pper->tycj,pper->zhcjpji);
				i++;
			}
			else break;
			pper=pper->next;
		}while(pper!=NULL);
		
	}

	fclose(fpout);


}
//==========================================================
//	���������ڴ�ӡѧ����Ϣ
//	����˵����struct StudentInfo *head  �����ͷָ��
//				int n Ҫ��ӡ��ѧ���ĸ���
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
						strcpy(sex,"��");
					}else
					{
						strcpy(sex,"Ů");
					
					}
					printf("ѧ�ţ�%-12s������%-8s�Ա�%-4s�����ɼ���%-3d�����ɼ���%-3d�����ɼ���%-3d\n",p->xh,p->xm,sex,p->dycj,p->zycj,p->tycj);
					p=p->next;
				
					i++;
				}
				else break;
				
			
			}while(p!=NULL);

		
			

	}



}
