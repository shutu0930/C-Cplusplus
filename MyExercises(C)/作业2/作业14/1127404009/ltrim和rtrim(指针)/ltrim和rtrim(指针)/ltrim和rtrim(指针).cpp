// ltrim��rtrim(ָ��).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#define N 50
void main()
{
	char *trim(char *pstr,int *plen);
	char str[N],*pstr=str;				//����ָ���������ʼ��
	int len,*plen=&len;
	
	printf("Please input some words:\n");
	gets(str);

	len=(int)strlen(str);
	printf("Before trimmed the length is :%d\n",*plen);
	
	trim(pstr,plen);					//����trim����
	printf("After being trimmed the words are :\n%s\nThe length is :%d\n",trim(pstr,plen),*plen);

}

//===========================================
//����������ɾ���ַ������п�ͷ�ͽ�β�Ŀո��
//����˵����char *pstr,int *plen
//����ֵ��trim����ַ����׵�ַ
//===========================================
char *trim(char *pstr,int *plen)
{
	int i,j;
	
	for(i=0;i<*plen;i++)				//����ɾ���ַ�����ͷ�Ŀո��
	{
		if(*(pstr+i)!=' ')
		{
			strcpy(pstr,pstr+i);
			break;
		}
		
	}
	
	for(j=*plen-1-i;j>=0;j--)			//����ɾ���ַ�����β�Ŀո��
	{
		if(*(pstr+j)!=' ')
		{
			*(pstr+j+1)=0;
			break;
		}
	}
	*plen=(int)strlen(pstr);
	return pstr;						//����trim����ַ����׵�ַ


}