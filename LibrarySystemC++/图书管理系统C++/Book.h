#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Book //ͼ���࣬ʵ�ֶ�ͼ���������ͼ��ı�ţ����������������ȹ��� 
{			
	int tag; //ɾ����� 1:��ɾ 0:δɾ
	int no; //ͼ����
	string name; //����         
	string author;//����
	string cbs; //������
	string ISBN;//ISBN��
	int onshelf; //�Ƿ��ټ� 1:�ټ� 2:�ѽ� 
public: 
	Book();
	Book(string str);
	string getname();
	string getauthorname();
	string getcbsname();
	int getno();
	int gettag();
	string getISBN();
	int getonshelf();
	void setname(string pname);
	void setonshelf(int oa); 
	void delbook();
	void addbook(int n,string pnama,string pauthor,string ppub,string pISBN,int oa); 
	void addbook(Book pbook);
	int borrowbook(); 
	void retbook();
	void disp(); 
	
	friend ostream& operator<<(ostream& o,const Book& b);
	~Book();
}; 