// �ļ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

void encrypt(char *f1,char *pwd,char *f2)
{
	int i=0;
	FILE *fp1,*fp2;						//fp1Ϊ��Ҫ���ܵ��ļ���fp2Ϊ������ܺ���ļ�
	 char ch;
	fp1=fopen(f1,"rb"); 
	if(fp1==NULL)
	{
		printf("can't open the file!\n");
		return;
	}
	if((fp2=fopen(f2,"wb"))==NULL)
	{
		printf("can't open the file!\n");
		return;
	}
	ch=fgetc(fp1);					//�ļ��ж�ȡһ���ַ�
	
	while(!feof(fp1))				//�ж��ļ��Ƿ����
	{
		ch=ch^*(pwd+i);				//�Զ�ȡ��һ���ַ����������
		i++;
		fputc(ch,fp2);				//�Ѵ������ַ�д������һ���ļ�
		ch=fgetc(fp1);				//Ȼ���ٴ�Ҫ���ܵ��ļ��ж�ȡ��һ���ַ�
		if(i>9)
		{
			i=0;
		}
	}
	fclose(fp1);							//�ر��ļ�
	fclose(fp2);
}

void main()
{
	char f1[N];
	char f2[N];
	char pwd[N];
	printf("sourcefile:");
	scanf("%s",f1);							//����Ҫ�����ļ���·��
	printf("password:");
	scanf("%s",pwd);						//������Ҫ�����ַ��ļ���
	printf("destinationfile:");
	scanf("%s",f2);							//��������ļ���·��
	encrypt(f1,pwd,f2);						
}