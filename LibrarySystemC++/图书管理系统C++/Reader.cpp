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
{				//获取姓名 
   return name;

} 
int Reader::gettag() 
{				//获取删除标记 
   return tag; 
} 
int Reader::getno() 
{				//获取读者编号 
   return no; 
} 
string Reader::getxueli()
{
	return xueli;
}
void Reader::setname(string pname) 
{				//设置姓名 
   name=pname; 
}
int Reader::getbornum()
{
	if(xueli=="本科生")
	{
		bornum=4;
	}else if(xueli=="硕士研究生")
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
	if(xueli=="本科生")
	{
		borday=60;
	}else if(xueli=="硕士研究生")
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
{				//设置删除标记 1:已删 0:未删 
   tag=1; 
}   
void Reader::addreader(int n,string pname,string pxueli,int pborday1,int pbornum1) 
{				//增加读者 
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
{				//借书操作 
	
	for(int i=0;i<getbornum1();i++) 
	{ 
		if (borbook[i]==0) 
		{
			borbook[i]=bookid;
		} 
	} 
} 
int Reader::retbook(int bookid) 
{					//还书操作 
   for(int i=0;i<getbornum();i++) 
   { 
		if(borbook[i]==bookid) 
		{ 
			borbook[i]=0;
			cout<<"还书成功!"<<endl;
			return 1; 
		} 
   }
	cout<<"未借该书，还书失败!"<<endl;
   return 0; 
} 
void Reader::disp() 
{				//读出读者信息
	/*int have=0;
	int bz=0;*/
	int flag=0;
	cout<<setfill(' ');
	cout<<setw(10)<<no<<setw(8)<<name<<setw(12)<<xueli<<'\t'<<"借书天数"<<getborday1()<<"\t"<<"已借"<<getbornum1()<<"本书"<<'\t'<<"最多可借"<<getbornum()<<"本书";
	
	cout<<"已借书的编号：";
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
		cout<<"还未借书！";
	
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
	 cout<<"\t     还未借书"<<endl;*/
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
