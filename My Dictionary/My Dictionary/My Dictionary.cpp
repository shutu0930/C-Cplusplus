// My Dictionary.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class AWord
{
	string word;
	string explan;
	string usage;

public:

	AWord()
	{
		word="\0";explan="\0";usage="\0";
	
	}
	void ApartWords(const string str);
	int SearchWord(const string str,string words);
	string &SearchExplan(const string str);
	string &SearchUsage(const string str);
	~AWord()
	{
		word.clear();
		explan.clear();
		usage.clear();
	
	}

};

void AWord::ApartWords(const string str)
{
	
	
	int i,j,k;

	for(i=0;str[i];i++)
	{
		if(str[i]!='[')
		{
			word.append(1,str[i]);
		}else
		{
			break;
		}

	}
	
		/*cout<<word<<endl;*/
		
		explan.append(1,str[i+6]);
		
		for(j=1,i=i+7;str[i];j++,i++)
		{
			if(str[i]!='[')
			{
				explan.append(1,str[i]);
			}else
			{
				break;
			}
			
		}
		/*cout<<explan<<endl;*/
		for( k=0,i=i+3;str[i];k++,i++)
		{
			usage.append(1,str[i]);
		
		}
		/*cout<<usage<<endl;*/
}

int AWord::SearchWord(const string str,string words)
{
	
	int count;
	for(count=0;words[count];count++)
	{
		
	}
	int i=0;
	while(str[i]!='\0'&&str[i]!='[')
	{
		if(words[i]==str[i])
		{
			i++;
		
		}else
		{
			break;
		}
	}
	if(i==count)
		return 1;
	else
		return 0;


}
string & AWord::SearchExplan(const string str)
{
	if(word==str)
	{
		return explan;
	
	}

}
string & AWord::SearchUsage(const string str)
{
	if(word==str)
	{
		if(usage=="\0")
		{
			cerr<<"Not have found the example！"<<endl;
		
		}else
		{
			return usage;
		
		}
	
	
	}
}

void main()
{
	AWord aword;
	string words;
	cout<<"Welcome to use my dictionary！\n"<<endl;
	
	cout<<"Please input words to search :"<<endl;
	getline(cin,words);
	
	ifstream in("in-ch dictionary.txt");   
	string str;
	
	while(getline(in,str))
	{
		
		/*cout<<str<<endl;*/
		
		if(aword.SearchWord(str,words)==1)
		{
			aword.ApartWords(str);
			cout<<"【解释】  "<<aword.SearchExplan(words)<<endl;
			cout<<"【例句】  "<<aword.SearchUsage(words)<<endl;
			break;
		
		}
	
	}
	
	if(aword.SearchWord(str,words)!=1)
		cout<<"Sorry,not have found the words you want！"<<endl;

}

