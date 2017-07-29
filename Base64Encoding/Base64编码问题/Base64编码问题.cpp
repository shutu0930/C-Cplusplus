// Base64编码问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <string>
using namespace std;
void EncodeBase64(char const* const Base64_Table,char *strin);

void main()
{

	char strin[76];
	
	char *Base64_Table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	cout<<"将输入的字符串或数据："<<endl;
	cin.getline(strin,76);
	EncodeBase64(Base64_Table,strin);

	
}
void EncodeBase64(char const* const Base64_Table,char *strin)
{
	int len=strlen(strin);
	char cTemp[5]="0";
	int num;
	int i;
	
	
	for(i=0;i<len;i+=3)
	{
		if((len-i)<3&&(len-i)>0)
			break;
		
		num=(strin[i]>>2)&0x3f;
		cTemp[0]=Base64_Table[num];
		
		num=((strin[i]<<4)|(strin[i+1]>>4))&0x3f;
		cTemp[1]=Base64_Table[num];
		
		num=((strin[i+1]<<2)|(strin[i+2]>>6))&0x3f;
		cTemp[2]=Base64_Table[num];
		
		num=strin[i+2]&0x3f;
		cTemp[3]=Base64_Table[num];
	
		cout<<cTemp;
		
		
	}
		
		
	if(len%3==1)
	{
		num=(strin[i]>>2)&0x3f;
		cTemp[0]=Base64_Table[num];
		
		num=(strin[i]<<4)&0x3f;
		cTemp[1]=Base64_Table[num];

		cTemp[2]='=';
		cTemp[3]='=';
		cout<<cTemp;
	
	}
	
	else if(len%3==2)
	{
		num=(strin[i]>>2)&0x3f;
		cTemp[0]=Base64_Table[num];
		
		num=((strin[i]<<4)|(strin[i+1]>>4))&0x3f;
		cTemp[1]=Base64_Table[num];
		
		num=(strin[i+1]<<2)&0x3f;
		cTemp[2]=Base64_Table[num];

		cTemp[3]='=';
	
		cout<<cTemp;
	}

}