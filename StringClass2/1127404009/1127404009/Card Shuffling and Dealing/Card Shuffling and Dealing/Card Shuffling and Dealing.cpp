// Card Shuffling and Dealing.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Card
{
	int m_face,m_suit;
	const static string faces[13];
	const static string suits[4];
public:
	Card();
	Card(int,int);
	string toString() const;
	Card& setFace(int);
	Card& setSuit(int);

};
const string Card::faces[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const string Card::suits[4]={"红桃","方块","黑桃","草花"};
Card::Card()
{
	setFace(0).setSuit(0);
}
Card::Card(int face,int suit)
{
	setFace(face).setSuit(suit);
}
string Card::toString() const
{
	return suits[m_suit]+"  "+faces[m_face];
}
inline Card& Card::setFace(int face)
{
	if(face>=0 && face<=12)
	{
		m_face=face;
	
	}else
		m_face=0;
	
	return *this;
}
inline Card& Card::setSuit(int suit)
{
	if(suit>=0 && suit<=3)
	{
		m_suit=suit;
	}else
		m_suit=0;
	
		
	return *this;
}

class DeckOfCard
{
	vector<Card> deck; //一副牌
	int currentCard;//当前的牌的序号

public:
	DeckOfCard();
	void shuffle(); //洗牌
	Card& dealCard(); //下一张
	bool moreCards() const;  //还有牌要处理吗？
	void show()const;
	
};


DeckOfCard::DeckOfCard()
{
	Card s;
	for(int i=0;i<52;i++)
	{
		deck.push_back(s.setFace(i%13).setSuit(i/13));	
	}
		
		currentCard=0;
}

void DeckOfCard::shuffle()
{
	srand((unsigned)time(NULL));
	
	for(int i=0;i<52;i++)
	{
		int j=rand()%52;
		Card temp;
		temp=deck[i];
		deck[i]=deck[j];
		deck[j]=temp;
	}
	
}
bool DeckOfCard::moreCards() const
{
	return (currentCard<52?true:false);
}
Card& DeckOfCard::dealCard()
{
	return deck[currentCard++];
}

void DeckOfCard ::show()const
{
	for(int i=0;i<52;i++)
	{
		cout<<deck[i].toString()<<endl;
	
	}
	
} 



void main()
{
	DeckOfCard deck;
	deck.shuffle();
	deck.show();
	
	
	
	
}

