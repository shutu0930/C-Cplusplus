#include "BookData.h"
#include<sstream>
BookData:: BookData() 
{				//���캯������book.txt����book[]�� 
   
   top=-1; 
   ifstream in("book.txt"); 
    string str;      
	while( getline(in,str) ) 
	{

		Book b(str); 
		top++;
		book.push_back(b);
	}
   
   in.close(); 
} 
void BookData::clear() 
{				//ȫɾ 
   top=-1; 
} 
int BookData::addbook(int n,string pname,string pauthor,string ppub,string pISBN,int oa) 
{				//����ͼ�� 
   Book *p=query1(n); 
   if (NULL==p) 
   { 
	top++; 
	book.resize(top+1);
	book[top].addbook(n,pname,pauthor,ppub,pISBN,oa); 
    return 1; 
   } 
   return 0; 
} 
int BookData::addbook(Book pbook)
{
	Book *p=query1(pbook.getno()); 
   if (NULL==p) 
   { 
    top++; 
    book.push_back(pbook); 
    return 1; 
   } 
   return 0; 

}
Book *BookData::query1(int bookid) 
{				//����Ų���ͼ�� 
   for(int i=0;i<=top;i++) 
   {
		if(book[i].getno()==bookid && book[i].gettag()==0) 
		{ 
		 return &book[i]; 
		}  
   }
    return 0; 
}
Book *BookData::query2(string a) 
{				//����������ͼ��
   /*Book *e;*/
   int r=0;
   for(int i=0;i<=top;i++)
   {
		
		if(book[i].getname()==a && book[i].gettag()==0) 
		{ 
		 if(r==0)
		 {
			cout<<setfill(' ');
			 //cout<<setw(10)<<setfill(' ')<<"ͼ����"<<setw(20)<<setfill(' ')<<"ͼ������"<<setw(14)<<setfill(' ')<<"ͼ������"<<setw(10)<<setfill(' ')<<"������"<<setw(15)<<setfill(' ')<<"ISBN��"<<setw(10)<<setfill(' ')<<"������"<<endl;
		 }
	      
		 /*e=&book[i];
		 e->disp();*/
		 book[i].disp();
		 r++; 
		} 
   
   
   }
    if(r==0)
     cout<<"�Ҳ�������!"<<endl;
     return 0; 
} 
Book *BookData::query3(string a) 
{				//�����߲���ͼ�� 
   Book *e;
   int r=0;
   for(int i=0;i<=top;i++) 
    if(book[i].getauthorname()==a && book[i].gettag()==0) 
    { 
     if(r==0)
	 {
		 cout<<setfill(' ');
		 //cout<<setw(10)<<setfill(' ')<<"ͼ����"<<setw(20)<<setfill(' ')<<"ͼ������"<<setw(14)<<setfill(' ')<<"ͼ������"<<setw(10)<<setfill(' ')<<"������"<<setw(15)<<setfill(' ')<<"ISBN��"<<setw(10)<<setfill(' ')<<"������"<<endl;
	 }
     
        e=&book[i];
      e->disp();
      r++; 
    } 
    if(r==0)
      cout<<"�Ҳ�������!"<<endl;
     return 0; 
}
Book *BookData::query4(string a) 
{				//�����������ͼ�� 
   Book *e;
   int r=0;
   for (int i=0;i<=top;i++)
    if (book[i].getcbsname()==a && book[i].gettag()==0) 
    { 
     if(r==0)
	 {
		cout<<setfill(' ');
		//cout<<setw(10)<<setfill(' ')<<"ͼ����"<<setw(20)<<setfill(' ')<<"ͼ������"<<setw(14)<<setfill(' ')<<"ͼ������"<<setw(10)<<setfill(' ')<<"������"<<setw(15)<<setfill(' ')<<"ISBN��"<<setw(10)<<setfill(' ')<<"������"<<endl;
	 }
		
     e=&book[i];
     e->disp();
     r++; 
    }
    if(r==0)
      cout<<"�Ҳ�������!"<<endl;
     return 0; 
}     
void BookData::bookdata() //ͼ�����Ϣ
{ 
	char select='\n'; 
	string bookname;
	string authorname;
	string cbcname;
	string pISBN;
	char ch;
	int select4;
	int bookid;
	int bookod;
	Book *b; 
	while (select!=0) 
	{ 
	   cout<<"\n\t\t\t����ͼ �� �� Ϣ �� ����\n"<<endl; 
	   cout<<"\t\t\t���� 1.��       �� ����"<<endl;
	   cout<<"\t\t\t���� 2.��       �� ����"<<endl;
	   cout<<"\t\t\t���� 3.ɾ       �� ����"<<endl;
	   cout<<"\t\t\t���� 4.��       �� ����"<<endl;
	   cout<<"\t\t\t���� 5.��       ʾ ����"<<endl;
	   cout<<"\t\t\t���� 6.ȫ       ɾ ����"<<endl;
	   cout<<"\t\t\t���� 0.��       �ء���"<<endl; 
	   cout<<"\t\t\t ��ѡ��";
	   cin>>select; 
	   switch(select) 
	   { 
		case '1'://����ͼ��
			cout<<"�����������ţ�"; 
			cin>>bookid;
			b=query1(bookid); 
			if(b!=NULL) 
			{ 
			 cout<<"�ñ���Ѿ����ڣ��������!"<<endl;
			 break; 
			}
			cout<<"����������������"; 
			cin>>bookname;
			cout<<"������������������"; 
			cin>>authorname;
			cout<<"��������������磺"; 
			cin>>cbcname;
			cout<<"����������ISBN�ţ�"; 
			cin>>pISBN;
			cout<<"����������������"; 
			cin>>bookod;
			if(addbook(bookid,bookname,authorname,cbcname,pISBN,bookod)==1)
			{
				cout<<"���ͼ��ɹ���";
			}else
			{
				cout<<"���ͼ��ʧ�ܣ�";
			}
			
			getchar(); 
			break; 
	   
		case '2': //����ͼ��
			cout<<"������ͼ����:"; 
			cin>>bookid; 
			b=query1(bookid); 
			if(b==NULL) 
			{ 
			 cout<<"��ͼ�鲻����! "<<endl;
			 break; 
			}
			cout<<"��ͼ�����Ϣ�ǣ�"<<endl;
			cout<<setw(10)<<setfill(' ')<<"ͼ����"<<setw(20)<<setfill(' ')<<"ͼ������"<<setw(14)<<setfill(' ')<<"ͼ������"<<setw(10)<<setfill(' ')<<"������"<<setw(15)<<setfill(' ')<<"ISBN��"<<setw(10)<<setfill(' ')<<"������"<<endl;
			b->disp();
			cout<<"�Ƿ��޸�?( y/n ):";
			cin>>ch;
			if(ch=='y')
			{
			 cout<<"�������µ�����:"; 
			 cin>>bookname;
			 cout<<"�������µ�����:";
			 cin>>authorname;
			 cout<<"���������������:";
			 cin>>cbcname;
			 cout<<"����������ISBN�ţ�"; 
			 cin>>pISBN;
			 cout<<"�������µĴ���:"; 
			 cin>>bookod;
			 b->setname(bookname);		//����ͼ������
			 b->setonshelf(bookod);		//����ͼ�������
			 cout<<"�޸�ͼ��ɹ�!";
			}
			getchar(); 
			  break;
	  
		case '3': //ɾ��ͼ��
			cout<<"������ͼ����:"; 
			cin>>bookid; 
			b=query1(bookid); 
			if(b==NULL) 
			{ 
			 cout<<"��ͼ�鲻���ڣ��޷�ɾ��!"<<endl;
			 break; 
			} 
			b->delbook();
			cout<<"ɾ���ɹ�!";
			getchar();
			break; 
	   
		case '4': //����ͼ��  
			cout<<"\t\t\t���� 1.��ͼ���Ų��� ����"<<endl;
			cout<<"\t\t\t���� 2.��ͼ���������� ����"<<endl;
			cout<<"\t\t\t���� 3.��ͼ�����߲��� ����"<<endl;
			cout<<"\t\t\t���� 4.��ͼ���������ҡ���"<<endl;
			cout<<"\t\t\t���� 0.��          �� ����"<<endl;
			cout<<"\t\t\t ��ѡ��"; 
			cin>>select4;
			switch(select4)
			{
				case 1: 
				 cout<<"������ͼ����:"; 
				 cin>>bookid;
				 b=query1(bookid);
				 if(b==NULL) 
				 { 
				  cout<<"��ͼ�鲻����!";
				  break; 
				 }
				 cout<<setw(10)<<setfill(' ')<<"ͼ����"<<setw(20)<<setfill(' ')<<"ͼ������"<<setw(14)<<setfill(' ')<<"ͼ������"<<setw(10)<<setfill(' ')<<"������"<<setw(15)<<setfill(' ')<<"ISBN��"<<setw(10)<<setfill(' ')<<"������"<<endl;
				 b->disp(); 
				 break;     
				
				case 2: 
				 cout<<"������ͼ������:"; 
				 cin>>bookname;
				 b=query2(bookname);
				 break;
				
				case 3: 
				 cout<<"������ͼ������:"; 
				 cin>>authorname;
				 b=query3(authorname);
				 break;
			
				case 4: 
				 cout<<"������ͼ�������:"; 
				 cin>>cbcname;
				 b=query4(cbcname);
				 break;
			
				case 0: 
				 break;
			}
			break;
		
		case '5': //��ʾͼ����Ϣ
			 cout<<setw(10)<<setfill(' ')<<"ͼ����"<<setw(20)<<setfill(' ')<<"ͼ������"<<setw(14)<<setfill(' ')<<"ͼ������"<<setw(10)<<setfill(' ')<<"������"<<setw(15)<<setfill(' ')<<"ISBN��"<<setw(10)<<setfill(' ')<<"������"<<endl;
			 disp();
			 getchar(); 
			 break; 
		
		case '6': //ȫ��ɾ��ͼ��
			 clear(); 
			 break; 
		
		default: 
			break; 
	   }	
	} 
}
void BookData::disp() 
{ 
	for(int i=0;i<=top;i++)
	{
		 if(book[i].gettag()==0)
		{
			book[i].disp(); 
		}


	}
   
    
} 
BookData::~BookData() 
{//������������book[]д��book.txt�ļ��� 
	
	ofstream fout("Total.txt"); 

	for(int i=0;i<=top;i++) 
	{
		if(book[i].gettag()==0)
		{
			
			fout<<book[i]<<endl;
		}
	}
	
	fout.close(); 
} 


