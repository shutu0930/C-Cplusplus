#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Book.h"
using namespace std;

class Reader
{	//读者的信息描述 

	int tag; //删除标记 1表示已删 0表示未删 
	int no; //读者编号
	string xueli;//读者的学历：本科生、研究生、博士生、教师
	string name; //读者姓名 
	int bornum;	//最多可借书的本数
	int bornum1;//已借的本书
	int borday;	//最多可借的天数
	int borday1;//已借天数
	vector<int> borbook;//借的书的编号
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