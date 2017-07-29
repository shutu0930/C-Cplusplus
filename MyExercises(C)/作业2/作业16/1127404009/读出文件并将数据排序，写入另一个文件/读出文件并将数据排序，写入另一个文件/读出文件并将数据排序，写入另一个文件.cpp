// 读出文件并将数据排序，写入另一个文件.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
#define M 10


int num[M];

void load()
{
	FILE *fp;
	int i;
	char filename1[N];
	printf("Please input the first filename :\n");
	gets(filename1);
	
	if((fp=fopen(filename1,"rb"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	
	for(i=0;i<M;i++)
	{
		fscanf(fp,"%d\n",&num[i]);
		/*if(fread(&num[i],sizeof(int),1,fp)!=1)
		{
			if(feof(fp))
			{
				fclose(fp);
				return;
			}
		printf("File read error!\n");
		}*/
	
	
	}
	
	fclose(fp);
}
void save()
{
	void sort(int *pnum,int n);
	FILE *fpout;
	int i;
	char filename2[N];
	printf("Please input the second filename :\n");
	gets(filename2);
	
	if((fpout=fopen(filename2,"wb"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	int *pnum=num;
	sort(pnum,M);
	for(i=0;i<M;i++)
	{
		printf("%d ",num[i]);
	}
	
	 for(i=0;i<M;i++)
	 {
		fprintf(fpout,"%d ",num[i]);
	 
	 }
 
	fclose(fpout);
 
 
	/*for(i=0;i<M;i++)
	{
		if(fwrite(&num[i],sizeof(int),1,fpout)!=1)
		{
			if(feof(fpout))
			{
				fclose(fpout);
				return;
			}
		printf("File write error!\n");
		}
	
	
	}
	for(i=0;i<M;i++)
	{
		fprintf(fpout,"%d ",num[i]);
		printf("%d ",num[i]);
	}

	fclose(fpout);*/






}
void sort(int *pnum,int n)
{
	int i,j,temp;
	
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(pnum+i)>*(pnum+j))
			{
				temp=*(pnum+i);
				*(pnum+i)=*(pnum+j);
				*(pnum+j)=temp;
			}
		
		}
	}

}

int main()
{
	load();
	save();
	return 0;
}

