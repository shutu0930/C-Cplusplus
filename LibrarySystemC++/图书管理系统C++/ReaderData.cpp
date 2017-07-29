#include "ReaderData.h"
ReaderData::ReaderData() 
{					//���캯������reader.txt����read[]�� 
	
	top=-1;    
   ifstream in("Reader.txt"); //��һ�������ļ�
   string str;
   while( getline(in,str) ) 
	{
		Reader s(str); 
		top++;
		reader.push_back(s);
	}
   
   in.close(); //�ر� reader.txt �ļ�
  
} 
void ReaderData::clear() 
{							//ɾ�����ж�����Ϣ 
   top=-1; 
} 
int ReaderData::addreader(int n,string pname,string pxueli,int pborday1,int pbornum1) 
{							//��Ӷ���ʱ�Ȳ����Ƿ���� 
   Reader *p=queryid(n); 
   if (p==NULL)
   {
    top++; 
	reader.resize(top+1);
    reader[top].addreader(n,pname,pxueli,pborday1,pbornum1); 
    return 1; 
   }
   else
    cout<<"�ñ���Ѿ�����!";
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
    cout<<"�ñ���Ѿ�����!";
   return 0; 


}
Reader *ReaderData::queryid(int readerid) 
{							//�����߱�Ų���
   for (int i=0;i<=top;i++) 
    if (reader[i].getno()==readerid&&reader[i].gettag()==0) 
    { 
     return &reader[i]; 
    } 
    return NULL;
}
Reader *ReaderData::queryname(string readername)                       
{							//��������������
   for (int i=0;i<=top;i++) 
    if (reader[i].getname()==readername && reader[i].gettag()==0) 
    { 
     return &reader[i]; 
    } 
    return NULL; 
}                                                             
void ReaderData::disp() 
{							//������ж�����Ϣ 
   for(int i=0;i<=top;i++)
    reader[i].disp(); 
} 
void ReaderData::readerdata() //���߿���Ϣ
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
	   cout<<"\n\t\t\t���� �� �� �� Ϣ �� �� ����\n"<<endl;
	   cout<<"\t\t\t���� 1.��         �� ����"<<endl;
	   cout<<"\t\t\t���� 2.��         �� ����"<<endl;
	   cout<<"\t\t\t���� 3.ɾ         �� ����"<<endl;
	   cout<<"\t\t\t���� 4.��         �� ����"<<endl;
	   cout<<"\t\t\t���� 5.��         ʾ ����"<<endl;
	   cout<<"\t\t\t���� 6.ȫ         ɾ ����"<<endl;
	   cout<<"\t\t\t���� 0.��         �� ����"<<endl; 
	   cout<<"\t\t\t ��ѡ��";
	   cin>>select1; 
	   switch(select1) 
	   { 
	   case '1': 
		cout<<"��������߱��:"; 
		cin>>readerid;
		cout<<"�������������:"; 
		cin>>readername;
		cout<<"���������ѧ��:"; 
		cin>>readerxueli;
		cout<<"��������߽�������:"; 
		cin>>pborday1;
		cout<<"��������߽��鱾��:"; 
		cin>>pbornum1;
		addreader(readerid,readername,readerxueli,pborday1,pbornum1);
		cout<<"��Ӷ��߳ɹ�!"<<endl;
		getchar();
		break;
	   
	   case '2': 
		cout<<"��������߱��:"; 
		cin>>readerid; 
		r=queryid(readerid); 
		if(r==NULL) 
		{ 
		 cout<<"�ö��߲�����! "<<endl; 
		 break; 
		} 
		cout<<"�������µ�����:"; 
		cin>>newname; 
		r->setname(newname); 
		cout<<"�޸Ķ��߳ɹ�!"<<endl;
		getchar();
		break;
	   
	   case '3': 
		cout<<"��������߱��:"; 
		cin>>readerid; 
		r=queryid(readerid); 
		if(r==NULL) 
		{ 
		 cout<<"�ö��߲�����!" << endl; 
		 break; 
		}        
		r->delbook();
		cout<<"ɾ���ɹ�!"<<endl;
		getchar();
		   break; 
	   
	   case '4':
		cout<<"\t\t\t���� 1.�����߱�Ų��� ����"<<endl;
		cout<<"\t\t\t���� 2.�������������� ����"<<endl;
		cout<<"\t\t\t���� 0.��          �� ����"<<endl;
		cout<<"\t\t\t ��ѡ��:"; 
		cin>>select2;
		switch(select2)
		{
		case 1: 
		 cout<<"��������߱��:"; 
		 cin>>readerid;
		 r=queryid(readerid); 
		 if(r==NULL) 
		 { 
		  cout<<"�ö��߲�����!"<< endl; 
		  break; 
		 }
		 //cout<<setw(10)<<"���߱��"<<setw(8)<<"��������"<<setw(20)<<"�ѽ�����"<<endl;
		  r->disp();
		  break;     
		
		case 2: 
		 cout<<"�������������:"; 
		  cin>>readername; 
		 r=queryname(readername); 
		 if(r==NULL) 
		 { 
		  cout<<"�ö��߲�����!"<<endl;
		  break; 
		 }
		 //cout<<setw(10)<<"���߱��"<<setw(17)<<"��������"<<setw(20)<<"�ѽ�����"<<endl;
		   r->disp();
		   break;
		 
		case 0: 
		  break;
		}
		 break;
	   
	   case '5':
		cout<<"\t\t\t���� 1.�� ʾ �� �� �� �� ����"<<endl;
		cout<<"\t\t\t���� 2.�� ʾ �� �� �� �� ����"<<endl;
		cout<<"\t\t\t���� 0.��          �� ����"<<endl;
		cout<<"\t\t\t ��ѡ��:"; 
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
			//cout<<setw(10)<<"���߱��"<<setw(17)<<"��������"<<setw(20)<<"�ѽ�����"<<endl;
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
{					//������������read[]д��reader.txt�ļ���
  
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