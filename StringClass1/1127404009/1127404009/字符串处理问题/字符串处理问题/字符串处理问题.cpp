// 字符串处理问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class CCstring
{
	char *m_pbuff;
public:
	CCstring()
	{
		m_pbuff=0;
	
	}
	CCstring(char *ptemp)
	{
		if(ptemp==0)
			m_pbuff=0;
		else
		{
			int len=strlen(ptemp);

			m_pbuff=new char[len+1];
			strcpy(m_pbuff,ptemp);
		
		}
		
	}
	CCstring(CCstring &temp)
	{
		if(temp.m_pbuff==0)
			m_pbuff=0;
		else
		{
			int len=strlen(temp.m_pbuff);

			m_pbuff=new char[len+1];
			strcpy(m_pbuff,temp.m_pbuff);
		}
	
	}
	
	~CCstring()
	{
		if(m_pbuff)
			delete[] m_pbuff;
	}

	
	void Setstring(char *ptemp)
	{
		if(m_pbuff)
			delete[] m_pbuff;
		
		int len=strlen(ptemp);

		m_pbuff=new char[len+1];
		strcpy(m_pbuff,ptemp);
	
	}

	int Getlength()
	{
		int i;
		if(m_pbuff)	
		{
			for(i=0;*(m_pbuff+i)!=0;i++){}
			return i;
		}
				
		else
		{
			return 0;
		
		}
	}

	void strlink(char *ptemp)
	{
		if(ptemp)
		{
			int len=strlen(ptemp)+strlen(m_pbuff);
			char *pptemp=m_pbuff;
			m_pbuff=new char[len+1];
			strcpy(m_pbuff,pptemp);
			strcat(m_pbuff,ptemp);
			delete[] pptemp;
		}
	
	}
	void strlink(CCstring &temp)
	{
		if(temp.m_pbuff)
		{
			int len=strlen(temp.m_pbuff)+strlen(m_pbuff);
			char *pptemp=m_pbuff;
			m_pbuff=new char[len+1];
			strcpy(m_pbuff,pptemp);
			strcat(m_pbuff,temp.m_pbuff);
			delete[] pptemp;
		
		}
	
	}

	void Ucase()
	{
		int len=strlen(m_pbuff);
		for(int i=0;i<len;i++)
		{
			if(*(m_pbuff+i)>='a' && *(m_pbuff+i)<='z')
			{
				*(m_pbuff+i)-=32;
			
			}
		
		}
	
	}

	void show()
	{
		if(m_pbuff)
		{
			cout<<m_pbuff<<endl;
		
		}
	
	}
	
	
	
};
void main()
{
	CCstring str1("hello ");
	str1.show();
	
	CCstring str2(str1);
	str2.show();
	
	str2.strlink("World!");
	str2.show();
	
	CCstring str3("everybody!");
	str2.Setstring("hello ");
	str2.strlink(str3);
	str2.show();
	
	str2.Ucase();
	cout<<str2.Getlength()<<endl;
	str2.show();
	

	

}

