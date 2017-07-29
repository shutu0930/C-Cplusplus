// 2011��״���ҵ.cpp : �������̨Ӧ�ó������ڵ㡣
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
	char xh[12];	//ѧ��
	char xm[12];	//����
	int  sex;		//�Ա�0-��ʾŮ��1-��ʾ����
	int  dycj;		//�����ɼ�
	int  zycj;		//�����ɼ�
	int  tycj;		//�����ɼ�
	double zhcjpji; //�ۺϲ����ɼ�
};
void main()
{
	struct StudentInfo stdu1[N];
	struct StudentInfo *pstdu1=stdu1;			//�ṹ�����ָ��
	int count1,count2;

	
	count1=read(pstdu1,N,10);					//���ļ�
	printf("ѧ����������%d\n",count1);
	count2=deletestu(pstdu1,M,count1);			//ɾ�����׵�ѧ��
	printf("������ѧ��ѧ����������%d\n",count2);

	count(pstdu1,count2);						//����ѧ�����ۺϳɼ�
	sort(pstdu1,count2);						//���ۺϳɼ��Ӹߵ��͸�ѧ������
	output(pstdu1,10);							//������ļ�����ӡ����Ļ

}
//==================================================
//	���������ڶ�ȡ���ݲ���ŵ�������
//	����˵����struct StudentInfo *person,int n,int m
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
	printf("����ѧ����Ϣ��ǰ10λͬѧ����\n");
	while(fread(pper,LEN,1,fp)==1)
	{

		if(pper<person+m)
		{
			if(pper->sex==1)
		{
			strcpy(sex,"��");
		}else
		{
			strcpy(sex,"Ů");
		
		}
		printf("ѧ�ţ�%-12s������%-8s�Ա�%-4s�����ɼ���%-3d�����ɼ���%-3d�����ɼ���%-3d\n",pper->xh,pper->xm,sex,pper->dycj,pper->zycj,pper->tycj);
		
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
//	����������ɾ����������Ӧ������
//	����˵����struct StudentInfo *person,int n,int m
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
//	���������ڼ���ѧ�����ۺϳɼ�
//	����˵����struct StudentInfo *person,int n
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
//	���������ڰ��ۺϳɼ����ɻ�ý�ѧ���ѧ������
//	����˵����struct StudentInfo *person,int n
//==================================================
void sort(struct StudentInfo *person,int n)
{
	struct StudentInfo *pper=person;
	struct StudentInfo temp;
	int i,j;
	
	for(i=0;i<n-1;i++)						//ѡ������
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
//	���������ڽ��ɻ�ý�ѧ��ѧ��ǰ10������Ϣ������ļ�����ӡ
//	����˵����struct StudentInfo *person,int n
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
	printf("\n������ѧ��ѧ��������ǰ10������\n");
	for(;pper<person+n;pper++)
	{	

		fprintf(fpout,"ѧ�ţ�%-12s������%-12s�����ɼ���%4d�����ɼ���%4d�����ɼ���%4d�ۺϲ����ɼ���%.2lf\n",pper->xh,pper->xm,pper->dycj,pper->zycj,pper->tycj,pper->zhcjpji);
		printf("ѧ�ţ�%-12s������%-12s�����ɼ���%4d�����ɼ���%4d�����ɼ���%4d�ۺϲ����ɼ���%.2lf\n",pper->xh,pper->xm,pper->dycj,pper->zycj,pper->tycj,pper->zhcjpji);
	}

	fclose(fpout);


}