#pragma once
#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
class BookData
{				//ͼ����࣬ʵ�ֶ�ͼ���ά�������ң�ɾ���� 
	int top;		//ͼ���¼ָ��
	vector<Book> book; //ͼ���¼
public: 
	BookData(); 
	void clear(); 
	int addbook(int n,string pname,string pauthor,string ppub,string pISBN,int oa);
	int addbook(Book pbook);
	Book *query1(int bookid); 
	Book *query2(string a); 
	Book *query3(string a); 
	Book *query4(string a); 
	void bookdata(); //ͼ�����Ϣ
	void disp(); 
	~BookData(); 
};