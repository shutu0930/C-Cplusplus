// 图书管理系统C++.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Book.h"
#include "BookData.h"
#include "Reader.h"
#include "ReaderData.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

void main()
{
	BookData bookData;
	/*bookData.disp();*/
	ifstream in("newBook.txt");
    string str;      
	while( getline(in,str) ) 
	{

		Book pbook(str);			//新书入库
		bookData.addbook(pbook);
	}
	/*bookData.addbook(1111111111,"123","123","123","123-2335",1);
	cout<<setw(10)<<setfill(' ')<<"图书编号"<<setw(20)<<setfill(' ')<<"图书名称"<<setw(14)<<setfill(' ')<<"图书作者"<<setw(10)<<setfill(' ')<<"出版社"<<setw(15)<<setfill(' ')<<"ISBN号"<<setw(10)<<setfill(' ')<<"存余量"<<endl;
	bookData.disp();*/

	ReaderData readerdata;
	
	
	ifstream in1("newReader.txt");
    string strr;      
	while( getline(in1,strr) ) 
	{

		Reader reader(strr);			
		readerdata.addreader(reader);
	}
	/*readerdata.disp();*/

	//
	//
	//Book *book=bookData.query1(2008063591);		//按编号查找图书
	//cout<<setw(10)<<setfill(' ')<<"图书编号"<<setw(20)<<setfill(' ')<<"图书名称"<<setw(14)<<setfill(' ')<<"图书作者"<<setw(10)<<setfill(' ')<<"出版社"<<setw(15)<<setfill(' ')<<"ISBN号"<<setw(10)<<setfill(' ')<<"存余量"<<endl;
	//book->disp();
	//
	//bookData.query2("SQL入门经典");			//按书名查找图书
	//
	//
	//bookData.query3("林旺");					//按作者查找图书
	//bookData.query4("天津教育出版社");			//按出版社查找图书 
	//
	//Reader *reader=readerdata.queryid(1127402003);	//按读者编号查找		
	//reader->disp();	
	//
	//reader=readerdata.queryname("张三");		//按读者姓名查找
	//reader->disp();
	//
	//int num2;
	//cout<<"请输入您的证件号："<<endl;
	//cin>>num2;
	//reader=readerdata.queryid(num2);
	//reader->disp();
	//int num3;
	//cout<<"请输入您要借的书的编号："<<endl;
	//cin>>num3;
	//book=bookData.query1(num3);
	//book->disp();
	//book->borrowbook();				//借书操作
	//cout<<book->getonshelf();


	//cout<<"请输入您要还的书的编号："<<endl;
	//cin>>num3;
	//book=bookData.query1(num3);
	//book->disp();
	//book->retbook();			//借书操作
	//cout<<book->getonshelf();




	
	
	char select5='\n'; 
    int bookid,readerid; 
	Reader *r; 
	Book *b;
	cout<<"\t\t\t 欢迎使用图书馆管理系统!"<<endl;
	while(select5!='0') 
	{   
	   cout<<"\n\t\t\t———— 图 书 管 理 系 统————\n\n"; 
	   cout<<"\t\t\t—— 1.图   书   信   息——"<<endl;
	   cout<<"\t\t\t—— 2.读   者   信   息 ——"<<endl;
	   cout<<"\t\t\t—— 3.借   阅   图   书 ——"<<endl;
	   cout<<"\t\t\t—— 4.归   还   图   书 ——"<<endl;
	   cout<<"\t\t\t—— 0.退             出 ——"<<endl; 
	   cout<<"\t\t\t 请选择：";
	   cin>>select5; 
	   switch (select5) 
	   { 
		   case '1':   
					bookData.bookdata(); 
					break; 
		   
		   case '2': 
					readerdata.readerdata(); 
					break; 
		  
		   case '3':
				cout<<"\t\t\t\t借书操作"<<endl;
				cout<<"请输入借书读者编号："; 
				cin>>readerid;
				r=readerdata.queryid(readerid);           
				if(NULL==r)    
				{										//按编号查找是否有该读者 
				 cout<<"不存在该读者，不能借书!"<<endl;
				 break; 
				} 
				cout<<"请输入要借图书编号:"; 
				cin>>bookid;   
				b=bookData.query1(bookid);              
				if(b==NULL)   
				{										//按编号查找是否有该图书 
					cout<<"不存在该图书，不能借书!"<<endl;
					 break; 
				}     
				if(b->getonshelf()==0) 
				{ 
					cout<<"该图书已借完，不能借书!"<<endl;
					break; 
				}
				cout<<"读者借书成功!"<<endl;
				
				r->borrowbook(b->getno());
				   break;   
		   
		   case '4': 
				cout<<"\t\t\t\t还书操作"<<endl;
				cout<<"请输入还书读者编号:"; 
				cin>>readerid;
				r=readerdata.queryid(readerid);
				if(r==NULL) 
				{ 
					 cout<<"不存在该读者，不能还书"<<endl;
					 break; 
				} 
				cout<<"请输入要归还图书编号:"; 
				cin>>bookid; 
				b=bookData.query1(bookid); 
				if(b==NULL) 
				{
					 cout<<"不存在该图书，不能还书"<<endl; 
					 break; 
				}
				b->retbook(); 
				r->retbook(b->getno());
				break; 
		   
		   default: 
					break; 
	   } 
	} 
	in.close(); 
	in1.close();
}

