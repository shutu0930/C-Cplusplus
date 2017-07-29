// ��20������Ϣ�Ĵ���2.cpp : �������̨Ӧ�ó������ڵ㡣
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
	char name[12];										//����ṹ����
	int sex;
	char phoneNumber[12];
	int age;
};
void main()
{
	struct Information person[N];
	int count,m;										//�ֱ�����Ůƽ������ֵdouble��
	double averf,averm;
	double *paverf=&averf,*paverm=&averm;				//�ֱ���ָ��ָ������ƽ��ֵ
	
	m=read(person,N);										//���ú��������ļ��е����ݲ��������ڽṹ������
	print(person,m);									//���ú������ṹ�����е����ݴ�ӡ����Ļ��
	aver(person,paverf,paverm,N);							//���ú�����ṹ��������Ů��ƽ������
	
	printf("\nŮ�˵�ƽ�����䣺%.3lf\n���˵�ƽ�����䣺%.3lf\n",averf,averm);			//�������ʾ����Ļ��
		
	count=deleteper(person,N);							//countΪɾ����������ʵ��Ԫ�صĸ���
	sort(person,count);									//���ú����������е����ݰ������ɴ�С����
	output(person,count);								//������õ������������һ���ļ��в���ӡ����Ļ��

}
//================================================
//���������ڶ����ļ��е����ݲ��������ڽṹ������
//����ֵ��const struct Information *person
//================================================
int read(struct Information *person,int n)
{
	FILE *fp;
	struct Information *pper=person;
	fp=fopen("D:\\12��20��C��ҵ�����ļ�.dat","rb");
	
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
//���������ڽ��ṹ�����е����ݴ�ӡ����Ļ��
//����ֵ��const struct Information *person,int n(����read�ķ���ֵ)
//===============================================================
void print(struct Information *person,int n)
{
	int i;
	char sex[3];

	if(n==-1)
	{
		printf("Cannot open the file!\n");							//����read�ķ���ֵ��Ϊ-1��˵���ļ���ʧ��
	
	}
	else if(n==1)
	{
		printf("file read error!");									//����1˵�����ļ�ʱ���ִ���
	
	}
	else
	{struct Information *pper=person;								//���������ϱ�˵����ȡ���ݳɹ��������ӡ
		for(;pper<person+N;pper++)
		{
			if(pper->sex==1)
			{
				strcpy(sex,"Ů");
			}else
			{
				strcpy(sex,"��");
			
			}
			printf("������%-10s�Ա�%-5s��ϵ���룺%-12s���䣺%3d\n",pper->name,sex,pper->phoneNumber,pper->age);	
			
		}
	
	}


}
//================================================
//������������ṹ��������Ů��ƽ������
//����ֵconst struct Information *person
//double *paverf,double *paverm��ָ��ƽ������ָ�룩
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
//����������ɾ������������>60��<18���˵�����
//����ֵ��const struct Information *person
//����ֵ��return j��ɾ����������ʣ��Ԫ�صĸ�����
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
//���������ڶ������е����ݰ������ɴ�С����
//����ֵ��const struct Information *person,int n
//��ָ�������ָ�룬������ʵ��Ԫ�صĸ�����
//========================================
void sort(struct Information *person,int n)
{
	int i,j;
	struct Information *pper=person;			
	struct Information temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)					//ѡ������
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
//���������ڽ�����õ������������һ���ļ��в���ӡ����Ļ��
//����ֵ��const struct Information *person,int n
//��ָ�������ָ�룬������ʵ��Ԫ�صĸ�����
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
	printf("\n����>=18��<=60���ˣ�\n");
	for(;pper<person+n;pper++)
	{
		if(pper->sex==1)
		{
			strcpy(sex,"Ů");
		}else
		{
			strcpy(sex,"��");
		
		}
		fprintf(fpout,"������%-10s�Ա�%-5s��ϵ���룺%-12s���䣺%3d\n",pper->name,sex,pper->phoneNumber,pper->age);	
		printf("������%-10s�Ա�%-5s��ϵ���룺%-12s���䣺%3d\n",pper->name,sex,pper->phoneNumber,pper->age);	
	}


}