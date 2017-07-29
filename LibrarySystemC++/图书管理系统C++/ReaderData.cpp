#include "ReaderData.h"
ReaderData::ReaderData() 
{					//构造函数，将reader.txt读到read[]中 
	
	top=-1;    
   ifstream in("Reader.txt"); //打开一个输入文件
   string str;
   while( getline(in,str) ) 
	{
		Reader s(str); 
		top++;
		reader.push_back(s);
	}
   
   in.close(); //关闭 reader.txt 文件
  
} 
void ReaderData::clear() 
{							//删除所有读者信息 
   top=-1; 
} 
int ReaderData::addreader(int n,string pname,string pxueli,int pborday1,int pbornum1) 
{							//添加读者时先查找是否存在 
   Reader *p=queryid(n); 
   if (p==NULL)
   {
    top++; 
	reader.resize(top+1);
    reader[top].addreader(n,pname,pxueli,pborday1,pbornum1); 
    return 1; 
   }
   else
    cout<<"该编号已经存在!";
   return 0; 
}  
int ReaderData::addreader(Reader preader)
{
	Reader *p=queryid(preader.getno()); 
   if (p==NULL)
   {
    top++; 
    reader.push_back(preader); 
    return 1; 
   }
   else
    cout<<"该编号已经存在!";
   return 0; 


}
Reader *ReaderData::queryid(int readerid) 
{							//按读者编号查找
   for (int i=0;i<=top;i++) 
    if (reader[i].getno()==readerid&&reader[i].gettag()==0) 
    { 
     return &reader[i]; 
    } 
    return NULL;
}
Reader *ReaderData::queryname(string readername)                       
{							//按读者姓名查找
   for (int i=0;i<=top;i++) 
    if (reader[i].getname()==readername && reader[i].gettag()==0) 
    { 
     return &reader[i]; 
    } 
    return NULL; 
}                                                             
void ReaderData::disp() 
{							//输出所有读者信息 
   for(int i=0;i<=top;i++)
    reader[i].disp(); 
} 
void ReaderData::readerdata() //读者库信息
{
	char select1='\n'; 
	string readername; 
	int readerid;
	string readerxueli;
	string newname;
	int pborday1;
	int pbornum1;
	int select2;
	Reader *r; 
	int select7;
	while(select1!='0')
	{
	   cout<<"\n\t\t\t—— 读 者 信 息 管 理 ——\n"<<endl;
	   cout<<"\t\t\t—— 1.新         增 ——"<<endl;
	   cout<<"\t\t\t—— 2.更         改 ——"<<endl;
	   cout<<"\t\t\t—— 3.删         除 ——"<<endl;
	   cout<<"\t\t\t—— 4.查         找 ——"<<endl;
	   cout<<"\t\t\t—— 5.显         示 ——"<<endl;
	   cout<<"\t\t\t—— 6.全         删 ——"<<endl;
	   cout<<"\t\t\t—— 0.返         回 ——"<<endl; 
	   cout<<"\t\t\t 请选择：";
	   cin>>select1; 
	   switch(select1) 
	   { 
	   case '1': 
		cout<<"请输入读者编号:"; 
		cin>>readerid;
		cout<<"请输入读者姓名:"; 
		cin>>readername;
		cout<<"请输入读者学历:"; 
		cin>>readerxueli;
		cout<<"请输入读者借书天数:"; 
		cin>>pborday1;
		cout<<"请输入读者借书本数:"; 
		cin>>pbornum1;
		addreader(readerid,readername,readerxueli,pborday1,pbornum1);
		cout<<"添加读者成功!"<<endl;
		getchar();
		break;
	   
	   case '2': 
		cout<<"请输入读者编号:"; 
		cin>>readerid; 
		r=queryid(readerid); 
		if(r==NULL) 
		{ 
		 cout<<"该读者不存在! "<<endl; 
		 break; 
		} 
		cout<<"请输入新的姓名:"; 
		cin>>newname; 
		r->setname(newname); 
		cout<<"修改读者成功!"<<endl;
		getchar();
		break;
	   
	   case '3': 
		cout<<"请输入读者编号:"; 
		cin>>readerid; 
		r=queryid(readerid); 
		if(r==NULL) 
		{ 
		 cout<<"该读者不存在!" << endl; 
		 break; 
		}        
		r->delbook();
		cout<<"删除成功!"<<endl;
		getchar();
		   break; 
	   
	   case '4':
		cout<<"\t\t\t—— 1.按读者编号查找 ——"<<endl;
		cout<<"\t\t\t—— 2.按读者姓名查找 ——"<<endl;
		cout<<"\t\t\t—— 0.返          回 ——"<<endl;
		cout<<"\t\t\t 请选择:"; 
		cin>>select2;
		switch(select2)
		{
		case 1: 
		 cout<<"请输入读者编号:"; 
		 cin>>readerid;
		 r=queryid(readerid); 
		 if(r==NULL) 
		 { 
		  cout<<"该读者不存在!"<< endl; 
		  break; 
		 }
		 //cout<<setw(10)<<"读者编号"<<setw(8)<<"读者姓名"<<setw(20)<<"已借书编号"<<endl;
		  r->disp();
		  break;     
		
		case 2: 
		 cout<<"请输入读者姓名:"; 
		  cin>>readername; 
		 r=queryname(readername); 
		 if(r==NULL) 
		 { 
		  cout<<"该读者不存在!"<<endl;
		  break; 
		 }
		 //cout<<setw(10)<<"读者编号"<<setw(17)<<"读者姓名"<<setw(20)<<"已借书编号"<<endl;
		   r->disp();
		   break;
		 
		case 0: 
		  break;
		}
		 break;
	   
	   case '5':
		cout<<"\t\t\t—— 1.显 示 超 期 读 者 ——"<<endl;
		cout<<"\t\t\t—— 2.显 示 所 有 读 者 ——"<<endl;
		cout<<"\t\t\t—— 0.返          回 ——"<<endl;
		cout<<"\t\t\t 请选择:"; 
		cin>>select7;
		switch(select7)
		{
		case 1:
			for(int i=0;i<=top;i++)
			{
				if(reader[i].getborday1()>=reader[i].getborday())
				{
					reader[i].disp();
				}
			
			}
			break;

		case 2:
			//cout<<setw(10)<<"读者编号"<<setw(17)<<"读者姓名"<<setw(20)<<"已借书编号"<<endl;
			disp();
			break;

		case 0:
			getchar(); 
			break; 
		
		}
		
	   case '6': clear();break; 
		
	   default: break; 
		
	   } 
	} 
}
ReaderData::~ReaderData() 
{					//析构函数，将read[]写到reader.txt文件中
  
	ofstream fout("Totalreader.txt"); 

	for(int i=0;i<=top;i++) 
	{
		if(reader[i].gettag()==0)
		{
			
			fout<<reader[i]<<endl;
		}
	}
	
	fout.close(); 
} 