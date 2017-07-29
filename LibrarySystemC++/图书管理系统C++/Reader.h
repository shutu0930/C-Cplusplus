#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Book.h"
using namespace std;

class Reader
{	//���ߵ���Ϣ���� 

	int tag; //ɾ����� 1��ʾ��ɾ 0��ʾδɾ 
	int no; //���߱��
	string xueli;//���ߵ�ѧ�������������о�������ʿ������ʦ
	string name; //�������� 
	int bornum;	//���ɽ���ı���
	int bornum1;//�ѽ�ı���
	int borday;	//���ɽ������
	int borday1;//�ѽ�����
	vector<int> borbook;//�����ı��
public: 
	Reader();
	Reader(string str);
	string getname();
	int gettag();
	int getno(); 
	string getxueli();
	void setname(string pname); 
	int getbornum();
	int getbornum1();
	int getborday();
	int getborday1();
	void delbook(); 
	void addreader(int n,string pname,string pxueli,int pborday1,int pbornum1); 
	void borrowbook(int bookid); 
	int retbook(int bookid); 
	void disp(); 

	friend ostream& operator<<(ostream& o,const Reader& r);
	~Reader();
};