#include "Book.h"
Book::Book()
{
	tag=0;
}
Book::Book(std::string str)
{
	tag=0;
	int i;	
	int flag=0;
	int count=0;
	for(i=0;str[i];i++)
	{
		
		if((str[i]==' '&& flag==0))
		{
			no=atoi(str.substr(0,i).c_str());
			count=i;
			flag++;
		}else if((str[i]==' '&& flag==1))
		{
			name=str.substr(count+1,i-count-1);
			count=i;
			flag++;
		
		}else if((str[i]==' '&& flag==2))
		{
			author=str.substr(count+1,i-1-count);
			count=i;
			flag++;
		
		}else if((str[i]==' '&& flag==3))
		{
			cbs=str.substr(count+1,i-1-count);
			count=i;
			flag++;
		}else if((str[i]==' '&& flag==4))
		{
			ISBN=str.substr(count+1,i-1-count);
			count=i;
			flag++;
		}else
			continue;

		
	}
	onshelf=atoi(str.substr(count+1,i-1-count).c_str());

}
string Book::getname()
{			//��ȡ����
return name; 
} 
string Book::getauthorname() 
{			//��ȡ������
   return author;
} 
string Book::getcbsname()
{			//��ȡ�������� 
   return cbs; 
} 
int Book::getno()
{			//��ȡͼ����
   return no; 
}
int Book::gettag()
{			//��ȡɾ����� 
   return tag; 
}
string Book::getISBN()
{
	return ISBN;//��ȡISBN��
}
int Book::getonshelf()
{
	return onshelf;//��ȡ�ϼܱ��
}
void Book::setname(string pname) 
{			//��������
   name=pname; 
} 
void Book::setonshelf(int oa) 
{			//���ô�����
   onshelf=oa;
} 
void Book::delbook()
{			//ɾ��ͼ�� 
   tag=1;
} 
void Book::addbook(int n,string pname,string pauthor,string ppub,string pISBN,int oa) 
{			//����ͼ�� 
   tag=0; 
   no=n; 
   name=pname;
   author=pauthor;
   cbs=ppub;
   ISBN=pISBN;
   onshelf=oa; 
} 
void Book::addbook(Book pbook)
{			//����ͼ�� 
	tag=0;
	no=pbook.getno();
	name=pbook.getname();
	author=pbook.getauthorname();
	cbs=pbook.getcbsname();
	ISBN=pbook.getISBN();
    onshelf=pbook.getonshelf();

}
int Book::borrowbook() 
{			//������� 
   if (onshelf>0) 
   { 
	onshelf--;
	return 1; 
   } 
   return 0; 
} 
void Book::retbook()
{			//�������
   onshelf++; 
} 
void Book::disp() 
{			//���ͼ�� 
	cout<<setw(10)<<setfill('0')<<no<<setw(24)<<setfill(' ')<<name<<setw(10)<<setfill(' ')<<author<<setw(15)<<setfill(' ')<<cbs<<setw(18)<<setfill(' ')<<ISBN<<setw(2)<<setfill(' ')<<onshelf<<endl; 
} 
ostream& operator<<(ostream& o,const Book& p)
{
	o<<p.no<<' '<<p.name<<' '<<p.author<<' '<<p.cbs<<' '<<p.ISBN<<' '<<p.onshelf; 
	return o;
}
Book::~Book(void)
{
}
