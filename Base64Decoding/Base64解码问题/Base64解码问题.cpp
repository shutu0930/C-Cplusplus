// Base64解码问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <string.h>
using namespace std;
void decodeBase64(char const* const Base64_Table,char *strout,int len);
int changec(char *strin,char *strout);
void main()
{

	char strin[76];
	char strout[76]="0";
	char *Base64_Table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int len;
	cout<<"请输入Base64码的字符串或数据："<<endl;
	cin.getline(strin,76);
	
	len=changec(strin,strout);
	cout<<"Base64解码："<<endl;
	decodeBase64(Base64_Table,strout,len);
	
	
}
void decodeBase64(char const* const Base64_Table,char *strout,int len)
{
	char cTemp[4]="0";
	int i;

	for(i=0;i<len;i+=4)
	{
		if('='==strout[i+2] && '='==strout[i+3])
	   {
		cTemp[0]=(strout[i]<<2) | (strout[i+1]>>4);
	   }
	   else if('='==strout[i+3])
	   {
		cTemp[0]=(strout[i]<<2) | (strout[i+1]>>4);
		cTemp[1]=(strout[i+1]<<4) | (strout[i+2]>>2);
	   }
	   else
	   {
		cTemp[0]=(strout[i]<<2) | (strout[i+1]>>4);
		cTemp[1]=(strout[i+1]<<4) | (strout[i+2]>>2);
		cTemp[2]=(strout[i+2]<<6) | strout[i+3];
	   
	   }
		
		cout<<cTemp;	
	  
	}

	cout<<"\n";


}
int changec(char *strin,char *strout)
{
	int len=strlen(strin);
	
	int i;
	for(i=0;i<len;i++)
	{
		if(strin[i]>='A'&& strin[i]<='Z')
		{
			strout[i]=strin[i]-65;
		
		}else if(strin[i]>='a'&& strin[i]<='z')
		{
			strout[i]=strin[i]-71;
		
		}else if(strin[i]>='0'&& strin[i]<='9')
		{
			strout[i]=strin[i]+4;
		
		}else if(strin[i]=='+')
		{
			strout[i]=43;
		}else if(strin[i]=='/')
		{
			strout[i]=47;
		}else
			continue;
			
			
		
		
		
		

	}

	return len;
}