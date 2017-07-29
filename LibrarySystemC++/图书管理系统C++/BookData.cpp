#include "BookData.h"
#include<sstream>
BookData:: BookData() 
{				//构造函数，将book.txt读到book[]中 
   
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
{				//全删 
   top=-1; 
} 
int BookData::addbook(int n,string pname,string pauthor,string ppub,string pISBN,int oa) 
{				//增加图书 
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
{				//按编号查找图书 
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
{				//按书名查找图书
   /*Book *e;*/
   int r=0;
   for(int i=0;i<=top;i++)
   {
		
		if(book[i].getname()==a && book[i].gettag()==0) 
		{ 
		 if(r==0)
		 {
			cout<<setfill(' ');
			 //cout<<setw(10)<<setfill(' ')<<"图书编号"<<setw(20)<<setfill(' ')<<"图书名称"<<setw(14)<<setfill(' ')<<"图书作者"<<setw(10)<<setfill(' ')<<"出版社"<<setw(15)<<setfill(' ')<<"ISBN号"<<setw(10)<<setfill(' ')<<"存余量"<<endl;
		 }
	      
		 /*e=&book[i];
		 e->disp();*/
		 book[i].disp();
		 r++; 
		} 
   
   
   }
    if(r==0)
     cout<<"找不到该书!"<<endl;
     return 0; 
} 
Book *BookData::query3(string a) 
{				//按作者查找图书 
   Book *e;
   int r=0;
   for(int i=0;i<=top;i++) 
    if(book[i].getauthorname()==a && book[i].gettag()==0) 
    { 
     if(r==0)
	 {
		 cout<<setfill(' ');
		 //cout<<setw(10)<<setfill(' ')<<"图书编号"<<setw(20)<<setfill(' ')<<"图书名称"<<setw(14)<<setfill(' ')<<"图书作者"<<setw(10)<<setfill(' ')<<"出版社"<<setw(15)<<setfill(' ')<<"ISBN号"<<setw(10)<<setfill(' ')<<"存余量"<<endl;
	 }
     
        e=&book[i];
      e->disp();
      r++; 
    } 
    if(r==0)
      cout<<"找不到该书!"<<endl;
     return 0; 
}
Book *BookData::query4(string a) 
{				//按出版社查找图书 
   Book *e;
   int r=0;
   for (int i=0;i<=top;i++)
    if (book[i].getcbsname()==a && book[i].gettag()==0) 
    { 
     if(r==0)
	 {
		cout<<setfill(' ');
		//cout<<setw(10)<<setfill(' ')<<"图书编号"<<setw(20)<<setfill(' ')<<"图书名称"<<setw(14)<<setfill(' ')<<"图书作者"<<setw(10)<<setfill(' ')<<"出版社"<<setw(15)<<setfill(' ')<<"ISBN号"<<setw(10)<<setfill(' ')<<"存余量"<<endl;
	 }
		
     e=&book[i];
     e->disp();
     r++; 
    }
    if(r==0)
      cout<<"找不到该书!"<<endl;
     return 0; 
}     
void BookData::bookdata() //图书库信息
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
	   cout<<"\n\t\t\t——图 书 信 息 管 理——\n"<<endl; 
	   cout<<"\t\t\t—— 1.新       增 ——"<<endl;
	   cout<<"\t\t\t—— 2.更       改 ——"<<endl;
	   cout<<"\t\t\t—— 3.删       除 ——"<<endl;
	   cout<<"\t\t\t—— 4.查       找 ——"<<endl;
	   cout<<"\t\t\t—— 5.显       示 ——"<<endl;
	   cout<<"\t\t\t—— 6.全       删 ——"<<endl;
	   cout<<"\t\t\t—— 0.返       回——"<<endl; 
	   cout<<"\t\t\t 请选择：";
	   cin>>select; 
	   switch(select) 
	   { 
		case '1'://新增图书
			cout<<"请输入新书编号："; 
			cin>>bookid;
			b=query1(bookid); 
			if(b!=NULL) 
			{ 
			 cout<<"该编号已经存在，不能添加!"<<endl;
			 break; 
			}
			cout<<"请输入新书书名："; 
			cin>>bookname;
			cout<<"请输入新书作者名："; 
			cin>>authorname;
			cout<<"请输入新书出版社："; 
			cin>>cbcname;
			cout<<"请输入新书ISBN号："; 
			cin>>pISBN;
			cout<<"请输入新书数量："; 
			cin>>bookod;
			if(addbook(bookid,bookname,authorname,cbcname,pISBN,bookod)==1)
			{
				cout<<"添加图书成功！";
			}else
			{
				cout<<"添加图书失败！";
			}
			
			getchar(); 
			break; 
	   
		case '2': //更改图书
			cout<<"请输入图书编号:"; 
			cin>>bookid; 
			b=query1(bookid); 
			if(b==NULL) 
			{ 
			 cout<<"该图书不存在! "<<endl;
			 break; 
			}
			cout<<"该图书的信息是："<<endl;
			cout<<setw(10)<<setfill(' ')<<"图书编号"<<setw(20)<<setfill(' ')<<"图书名称"<<setw(14)<<setfill(' ')<<"图书作者"<<setw(10)<<setfill(' ')<<"出版社"<<setw(15)<<setfill(' ')<<"ISBN号"<<setw(10)<<setfill(' ')<<"存余量"<<endl;
			b->disp();
			cout<<"是否修改?( y/n ):";
			cin>>ch;
			if(ch=='y')
			{
			 cout<<"请输入新的书名:"; 
			 cin>>bookname;
			 cout<<"请输入新的作者:";
			 cin>>authorname;
			 cout<<"请输入新书出版社:";
			 cin>>cbcname;
			 cout<<"请输入新书ISBN号："; 
			 cin>>pISBN;
			 cout<<"请输入新的存量:"; 
			 cin>>bookod;
			 b->setname(bookname);		//更改图书名称
			 b->setonshelf(bookod);		//更改图书存余量
			 cout<<"修改图书成功!";
			}
			getchar(); 
			  break;
	  
		case '3': //删除图书
			cout<<"请输入图书编号:"; 
			cin>>bookid; 
			b=query1(bookid); 
			if(b==NULL) 
			{ 
			 cout<<"该图书不存在，无法删除!"<<endl;
			 break; 
			} 
			b->delbook();
			cout<<"删除成功!";
			getchar();
			break; 
	   
		case '4': //查找图书  
			cout<<"\t\t\t—— 1.按图书编号查找 ——"<<endl;
			cout<<"\t\t\t—— 2.按图书书名查找 ——"<<endl;
			cout<<"\t\t\t—— 3.按图书作者查找 ——"<<endl;
			cout<<"\t\t\t—— 4.按图书出版社查找——"<<endl;
			cout<<"\t\t\t—— 0.返          回 ——"<<endl;
			cout<<"\t\t\t 请选择："; 
			cin>>select4;
			switch(select4)
			{
				case 1: 
				 cout<<"请输入图书编号:"; 
				 cin>>bookid;
				 b=query1(bookid);
				 if(b==NULL) 
				 { 
				  cout<<"该图书不存在!";
				  break; 
				 }
				 cout<<setw(10)<<setfill(' ')<<"图书编号"<<setw(20)<<setfill(' ')<<"图书名称"<<setw(14)<<setfill(' ')<<"图书作者"<<setw(10)<<setfill(' ')<<"出版社"<<setw(15)<<setfill(' ')<<"ISBN号"<<setw(10)<<setfill(' ')<<"存余量"<<endl;
				 b->disp(); 
				 break;     
				
				case 2: 
				 cout<<"请输入图书书名:"; 
				 cin>>bookname;
				 b=query2(bookname);
				 break;
				
				case 3: 
				 cout<<"请输入图书作者:"; 
				 cin>>authorname;
				 b=query3(authorname);
				 break;
			
				case 4: 
				 cout<<"请输入图书出版社:"; 
				 cin>>cbcname;
				 b=query4(cbcname);
				 break;
			
				case 0: 
				 break;
			}
			break;
		
		case '5': //显示图书信息
			 cout<<setw(10)<<setfill(' ')<<"图书编号"<<setw(20)<<setfill(' ')<<"图书名称"<<setw(14)<<setfill(' ')<<"图书作者"<<setw(10)<<setfill(' ')<<"出版社"<<setw(15)<<setfill(' ')<<"ISBN号"<<setw(10)<<setfill(' ')<<"存余量"<<endl;
			 disp();
			 getchar(); 
			 break; 
		
		case '6': //全部删除图书
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
{//析构函数，将book[]写到book.txt文件中 
	
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


