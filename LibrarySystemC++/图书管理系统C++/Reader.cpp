#include "Reader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Book.h"
using namespace std;
Reader::Reader()
{
	tag=0;
}
Reader::Reader(std::string str)
{
	tag=0;
	int i;	
	int flag=0;
	int count=0;
	for(i=0;str[i];i++)
	{
		
		if(str[i]==' '&& flag==0)
		{
			no=atoi(str.substr(0,i).c_str());
			count=i;
			flag++;
		}else if(str[i]==' '&& flag==1)
		{
			name=str.substr(count+1,i-count-1);
			count=i;
			flag++;
		
		}else if(str[i]==' '&& flag==2)
		{
			xueli=str.substr(count+1,i-1-count);
			count=i;
			flag++;
		}else if(str[i]==' '&& flag==3)
		{
			borday1=atoi(str.substr(count+1,i-1-count).c_str());
			count=i;
			flag++;
		
		}else if(str[i]==' '&& flag==4)
		{
			bornum1=atoi(str.substr(count+1,i-1-count).c_str());
			count=i;
			flag++;
		
		
		}else if((str[i]==' '&& flag>=5))
		{
			borbook.push_back(atoi(str.substr(count+1,i-1-count).c_str()));
			count=i;
			flag++;
		
		}

		
	}
	
	
	if(count!=i&&flag==2)
	{
		xueli=str.substr(count+1,i-1-count);
		
	}else if(count!=i&&flag==3)
	{
		borday1=atoi(str.substr(count+1,i-1-count).c_str());
	
	}else if(count!=i&&flag==4)
	{
		bornum1=atoi(str.substr(count+1,i-1-count).c_str());
	
	}else
	{
		borbook.push_back(atoi(str.substr(count+1,i-1-count).c_str()));
	}


}
string Reader::getname() 
{				//��ȡ���� 
   return name;

} 
int Reader::gettag() 
{				//��ȡɾ����� 
   return tag; 
} 
int Reader::getno() 
{				//��ȡ���߱�� 
   return no; 
} 
string Reader::getxueli()
{
	return xueli;
}
void Reader::setname(string pname) 
{				//�������� 
   name=pname; 
}
int Reader::getbornum()
{
	if(xueli=="������")
	{
		bornum=4;
	}else if(xueli=="˶ʿ�о���")
	{
		bornum=8;
	}else
	{
		bornum=10;
	}

	return bornum;
}
int Reader::getbornum1()
{
	return bornum1;

}
int Reader::getborday()
{
	if(xueli=="������")
	{
		borday=60;
	}else if(xueli=="˶ʿ�о���")
	{
		borday=90;
	}else
	{
		borday=120;
	}

	return borday;
}
int Reader::getborday1()
{
	return borday1;
}
void Reader::delbook() 
{				//����ɾ����� 1:��ɾ 0:δɾ 
   tag=1; 
}   
void Reader::addreader(int n,string pname,string pxueli,int pborday1,int pbornum1) 
{				//���Ӷ��� 
	tag=0; 
	no=n; 
	name=pname; 
	xueli=pxueli;
	borday1=pborday1;
	bornum1=pbornum1;
   
	for(int i=0;i<getbornum1();i++) 
	{
		borbook.push_back(0);
	}
	
   
  
} 
void Reader::borrowbook(int bookid) 
{				//������� 
	
	for(int i=0;i<getbornum1();i++) 
	{ 
		if (borbook[i]==0) 
		{
			borbook[i]=bookid;
		} 
	} 
} 
int Reader::retbook(int bookid) 
{					//������� 
   for(int i=0;i<getbornum();i++) 
   { 
		if(borbook[i]==bookid) 
		{ 
			borbook[i]=0;
			cout<<"����ɹ�!"<<endl;
			return 1; 
		} 
   }
	cout<<"δ����飬����ʧ��!"<<endl;
   return 0; 
} 
void Reader::disp() 
{				//����������Ϣ
	/*int have=0;
	int bz=0;*/
	int flag=0;
	cout<<setfill(' ');
	cout<<setw(10)<<no<<setw(8)<<name<<setw(12)<<xueli<<'\t'<<"��������"<<getborday1()<<"\t"<<"�ѽ�"<<getbornum1()<<"����"<<'\t'<<"���ɽ�"<<getbornum()<<"����";
	
	cout<<"�ѽ���ı�ţ�";
	for(int i=0;i<getbornum1();i++)
	{
		if(borbook[i]!=0)
		{
			cout<<borbook[i];
			flag=1;
		}
		
	}
	if(flag==0)
	{
		cout<<"��δ���飡";
	
	}
	cout<<endl;		
	/*for(int i=0;i<getbornum();i++) 
	if(borbook[i]!=0)
	{ 
	 if(bz==0)
	 {
	  have=1;
	  cout<<"["<<borbook[i]<<"]\t\t"<<endl;            
	  bz++;
	 }
	 else
	 {
	  cout<<"\r\t\t\t\t\t""["<<borbook[i]<<"]\t\t"<<setw(15)<<endl; 
	 }
	}
	if(have==0)
	 cout<<"\t     ��δ����"<<endl;*/
}
ostream& operator<<(ostream& o,const Reader& r)
{
	o<<r.no<<' '<<r.name<<' '<<r.xueli<<' '<<r.borday1<<' '<<r.bornum1<<' ';
	for(int i=0;i<r.bornum1;i++)
	{
		if(r.borbook[i]!=0)
		{
			o<<r.borbook[i]<<' ';
		}
		
	}	
	return o;
}
Reader::~Reader(void)
{
}
