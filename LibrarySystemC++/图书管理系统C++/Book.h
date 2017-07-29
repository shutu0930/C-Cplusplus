#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Book //图书类，实现对图书的描述，图书的编号，书名，借出，还入等功能 
{			
	int tag; //删除标记 1:已删 0:未删
	int no; //图书编号
	string name; //书名         
	string author;//作者
	string cbs; //出版社
	string ISBN;//ISBN号
	int onshelf; //是否再架 1:再架 2:已借 
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