// 查字典.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void ApartWords(const string str,string &word,string &explan,string &usage);
//int SearchWord(const string str,const string word);
//string & SearchExplan(const string str,,const string word,const string explan);
//string & SearchUsage(const string str,const string word,const string usage);


void ApartWords(const string str,string &word,string &explan,string &usage)
{
	int i,j,k;

	for(i=0;str[i];i++)
	{
		if(str[i]!='[')
		{
			word[i]=str[i];
			cout<<word[i];
		}else
		{
			break;
		}

	}
		explan[0]=str[i+6];
		cout<<explan[0];
		for(j=1,i=i+7;str[i];j++,i++)
		{
			if(str[i]!='[')
			{
				explan[j]=str[i];
				cout<<str[i];
			}else
			{
				break;
			}
			
		}
		/*for( k=0,j=j+3;str[j];k++,j++)
		{
			usage[k]=str[j];
		
		}*/
		/*usage=str3;*/
}

//int SearchWord(const string str,const string word)
//{
//	if(word==str)
//		return 1;
//	else
//		return 0;
//
//
//}
//string & SearchExplan(const string str,,const string word,const string explan)
//{
//	if(word==str)
//	{
//		return explan;
//	
//	}
//
//}
//string & SearchUsage(const string str,const string word,const string usage)
//{
//	if(word==str)
//	{
//		if(usage=="\0")
//		{
//			cerr<<"Not have found the example！"<<endl;
//		
//		}else
//		{
//			return usage;
//		
//		}
//	
//	
//	}
//}

void main()
{
	
	string word;
	string explan;
	string usage;

	string words;

	cout<<"Please input words to search :"<<endl;
	getline(cin,words);
	
	ifstream in("in-ch dictionary.txt");   
	string str;
	while(getline(in,str))
	{
		cout<<str<<endl;
		
		ApartWords(str,word,explan,usage);
		cout<<"!";
	
		/*	if(aword.SearchWord(words)==1)
		{
			cout<<aword.SearchExplan(words)<<endl;
			cout<<aword.SearchUsage(words)<<endl;
			break;
		
		}else
		{
			cout<<"Sorry,not have found the word！"<<endl;
		
		}*/
	
	}
	

}
