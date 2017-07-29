#pragma once
#include "Reader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class ReaderData 
{					//������⣬ʵ�ֽ������ߵĸ������� 
	int top;		//���߼�¼ָ�� 
    vector<Reader> reader; //���߼�¼ 
public: 
	ReaderData();
	void clear(); 
	int addreader(int n,string pname,string pxueli,int pborday1,int pbornum1); 
	int addreader(Reader preader);
	Reader *queryid(int readerid); 
	Reader *queryname(string readername);                                                                         
	void disp();
	void readerdata(); //���߿���Ϣ
	~ReaderData(); 
};
