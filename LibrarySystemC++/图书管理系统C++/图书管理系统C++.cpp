// ͼ�����ϵͳC++.cpp : �������̨Ӧ�ó������ڵ㡣
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

		Book pbook(str);			//�������
		bookData.addbook(pbook);
	}
	/*bookData.addbook(1111111111,"123","123","123","123-2335",1);
	cout<<setw(10)<<setfill(' ')<<"ͼ����"<<setw(20)<<setfill(' ')<<"ͼ������"<<setw(14)<<setfill(' ')<<"ͼ������"<<setw(10)<<setfill(' ')<<"������"<<setw(15)<<setfill(' ')<<"ISBN��"<<setw(10)<<setfill(' ')<<"������"<<endl;
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
	//Book *book=bookData.query1(2008063591);		//����Ų���ͼ��
	//cout<<setw(10)<<setfill(' ')<<"ͼ����"<<setw(20)<<setfill(' ')<<"ͼ������"<<setw(14)<<setfill(' ')<<"ͼ������"<<setw(10)<<setfill(' ')<<"������"<<setw(15)<<setfill(' ')<<"ISBN��"<<setw(10)<<setfill(' ')<<"������"<<endl;
	//book->disp();
	//
	//bookData.query2("SQL���ž���");			//����������ͼ��
	//
	//
	//bookData.query3("����");					//�����߲���ͼ��
	//bookData.query4("������������");			//�����������ͼ�� 
	//
	//Reader *reader=readerdata.queryid(1127402003);	//�����߱�Ų���		
	//reader->disp();	
	//
	//reader=readerdata.queryname("����");		//��������������
	//reader->disp();
	//
	//int num2;
	//cout<<"����������֤���ţ�"<<endl;
	//cin>>num2;
	//reader=readerdata.queryid(num2);
	//reader->disp();
	//int num3;
	//cout<<"��������Ҫ�����ı�ţ�"<<endl;
	//cin>>num3;
	//book=bookData.query1(num3);
	//book->disp();
	//book->borrowbook();				//�������
	//cout<<book->getonshelf();


	//cout<<"��������Ҫ������ı�ţ�"<<endl;
	//cin>>num3;
	//book=bookData.query1(num3);
	//book->disp();
	//book->retbook();			//�������
	//cout<<book->getonshelf();




	
	
	char select5='\n'; 
    int bookid,readerid; 
	Reader *r; 
	Book *b;
	cout<<"\t\t\t ��ӭʹ��ͼ��ݹ���ϵͳ!"<<endl;
	while(select5!='0') 
	{   
	   cout<<"\n\t\t\t�������� ͼ �� �� �� ϵ ͳ��������\n\n"; 
	   cout<<"\t\t\t���� 1.ͼ   ��   ��   Ϣ����"<<endl;
	   cout<<"\t\t\t���� 2.��   ��   ��   Ϣ ����"<<endl;
	   cout<<"\t\t\t���� 3.��   ��   ͼ   �� ����"<<endl;
	   cout<<"\t\t\t���� 4.��   ��   ͼ   �� ����"<<endl;
	   cout<<"\t\t\t���� 0.��             �� ����"<<endl; 
	   cout<<"\t\t\t ��ѡ��";
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
				cout<<"\t\t\t\t�������"<<endl;
				cout<<"�����������߱�ţ�"; 
				cin>>readerid;
				r=readerdata.queryid(readerid);           
				if(NULL==r)    
				{										//����Ų����Ƿ��иö��� 
				 cout<<"�����ڸö��ߣ����ܽ���!"<<endl;
				 break; 
				} 
				cout<<"������Ҫ��ͼ����:"; 
				cin>>bookid;   
				b=bookData.query1(bookid);              
				if(b==NULL)   
				{										//����Ų����Ƿ��и�ͼ�� 
					cout<<"�����ڸ�ͼ�飬���ܽ���!"<<endl;
					 break; 
				}     
				if(b->getonshelf()==0) 
				{ 
					cout<<"��ͼ���ѽ��꣬���ܽ���!"<<endl;
					break; 
				}
				cout<<"���߽���ɹ�!"<<endl;
				
				r->borrowbook(b->getno());
				   break;   
		   
		   case '4': 
				cout<<"\t\t\t\t�������"<<endl;
				cout<<"�����뻹����߱��:"; 
				cin>>readerid;
				r=readerdata.queryid(readerid);
				if(r==NULL) 
				{ 
					 cout<<"�����ڸö��ߣ����ܻ���"<<endl;
					 break; 
				} 
				cout<<"������Ҫ�黹ͼ����:"; 
				cin>>bookid; 
				b=bookData.query1(bookid); 
				if(b==NULL) 
				{
					 cout<<"�����ڸ�ͼ�飬���ܻ���"<<endl; 
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

