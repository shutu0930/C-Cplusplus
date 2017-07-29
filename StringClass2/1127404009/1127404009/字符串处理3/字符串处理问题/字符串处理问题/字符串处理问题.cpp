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
		if(m_pbuff)
			return 0;
		else
		{
			for(int i=0;*(m_pbuff)!=0;i++)
				return i;
		
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
	
	void CCstring::operator=(CCstring &temp)
	{
		if (m_pbuff) delete []m_pbuff;
		
		int len=strlen(temp.m_pbuff);
		
		if (temp.m_pbuff)
		{
			m_pbuff=new char[len+1];
			strcpy(m_pbuff,temp.m_pbuff);
		
		
		}else
		  m_pbuff=0;


	}
	
	friend CCstring operator+(CCstring &temp1,CCstring &temp2);
	char &operator[](int index)
	{
		int len=strlen(m_pbuff);
		if(index>=0 && index<len)
		{
			return *(m_pbuff+index);
		
		}else
			cerr<<"对不起，越界了！"<<endl;
	
	
	}

};

CCstring operator+(CCstring &temp1,CCstring &temp2)
{
	CCstring buff;
	
	int len=strlen(temp1.m_pbuff)+strlen(temp2.m_pbuff);
	
	buff.m_pbuff=new char[len+1];
	strcpy(buff.m_pbuff,temp1.m_pbuff);
	strcat(buff.m_pbuff,temp2.m_pbuff);
		
	return buff;	


}
void main()
{
	CCstring str1("hello ");
	str1.show();
	CCstring str2(str1);
	str2.show();
	str2.strlink("World!");
	str2.show();
	CCstring str3("Everybody!");
	str2.strlink(str3);
	str2.Ucase();
	str2.show();
	
	CCstring str4;
	str4=str1+str3;
	str4.show();
	cout<<str4[6]<<endl;
	

}

