// wowowowo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct StudentInfo)
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
	FILE *fp;
	struct StudentInfo temp;

	int count=0;
	fp=fopen("D:\\in.dat","rb");
	
	if(fp==NULL)
	{
		printf("Cannot open the file!\n");
		return;
	}
	
	while(fread(&temp,LEN-8,1,fp)==1)
	{
		printf("%s%s\n",temp.xh,temp.xm);
		count++;
		
	}
	fclose(fp);
}

