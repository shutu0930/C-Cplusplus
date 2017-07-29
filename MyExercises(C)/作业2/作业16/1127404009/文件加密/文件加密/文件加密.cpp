// 文件加密.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

void encrypt(char *f1,char *pwd,char *f2)
{
	int i=0;
	FILE *fp1,*fp2;						//fp1为需要加密的文件，fp2为保存加密后的文件
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
	ch=fgetc(fp1);					//文件中读取一个字符
	
	while(!feof(fp1))				//判断文件是否读完
	{
		ch=ch^*(pwd+i);				//对读取的一个字符，进行异或
		i++;
		fputc(ch,fp2);				//把处理后的字符写入另外一个文件
		ch=fgetc(fp1);				//然后再从要加密的文件中读取下一个字符
		if(i>9)
		{
			i=0;
		}
	}
	fclose(fp1);							//关闭文件
	fclose(fp2);
}

void main()
{
	char f1[N];
	char f2[N];
	char pwd[N];
	printf("sourcefile:");
	scanf("%s",f1);							//输入要加密文件的路径
	printf("password:");
	scanf("%s",pwd);						//密码主要用于字符的加密
	printf("destinationfile:");
	scanf("%s",f2);							//保存加密文件的路径
	encrypt(f1,pwd,f2);						
}