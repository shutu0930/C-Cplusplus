#pragma once
#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
class BookData
{				//图书库类，实现对图书的维护，查找，删除等 
	int top;		//图书记录指针
	vector<Book> book; //图书记录
public: 
	BookData(); 
	void clear(); 
	int addbook(int n,string pname,string pauthor,string ppub,string pISBN,int oa);
	int addbook(Book pbook);
	Book *query1(int bookid); 
	Book *query2(string a); 
	Book *query3(string a); 
	Book *query4(string a); 
	void bookdata(); //图书库信息
	void disp(); 
	~BookData(); 
};