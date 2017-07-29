// 括号匹配问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
#define SIZE 100
using namespace std;

class cstack
{
	char m_buff[SIZE];
	int m_top;
public:
	cstack()
	{
		m_top=-1;
		for(int i=0;i<SIZE;i++)
		{
			m_buff[i]=0;
		}

	}
	void push(char ch)
	{
		if(ch=='('|| ch=='{')
		{
			m_top++;
			m_buff[m_top]=ch;
		
		}else if((ch==')' && m_buff[m_top]=='(') || (ch=='}' && m_buff[m_top]=='{'))
		{
			
			m_buff[m_top]=0;
			m_top--;
		}else if((ch==')' && m_buff[m_top]!='(') || (ch=='}' && m_buff[m_top]!='{'))
		{
			m_top++;
			m_buff[m_top]=ch;
		}
		
		
	}
	int pop()
	{
		return strlen(m_buff);
	}
	

};
void main()
{
	cstack kuohao;
	char strin[SIZE];

	cout<<"请输入字符串："<<endl;
	cin.getline(strin,SIZE);
	int len;
	len=strlen(strin);

	for(int i=0;i<len;i++)
	{
		kuohao.push(strin[i]);
	
	}

	if(kuohao.pop()==0 )
	{
		cout<<"括号匹配！"<<endl;
	}else 
		cout<<"括号不匹配！"<<endl;

}

