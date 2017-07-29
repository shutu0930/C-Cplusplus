#pragma once
#include "Reader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class ReaderData 
{					//读者类库，实现建立读者的个人资料 
	int top;		//读者记录指针 
    vector<Reader> reader; //读者记录 
public: 
	ReaderData();
	void clear(); 
	int addreader(int n,string pname,string pxueli,int pborday1,int pbornum1); 
	int addreader(Reader preader);
	Reader *queryid(int readerid); 
	Reader *queryname(string readername);                                                                         
	void disp();
	void readerdata(); //读者库信息
	~ReaderData(); 
};
