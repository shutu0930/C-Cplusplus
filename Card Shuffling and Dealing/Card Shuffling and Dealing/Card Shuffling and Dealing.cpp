// Card Shuffling and Dealing.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#define CARD_H
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
	friend Card operator+(const Card &faces,const Card &suits);
	int getFace() const;
	int getSuit() const;

};
const string Card::faces[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
const string Card::suits[4]={"Hearts(红桃)","Diamonds(方块)","Clubs(黑桃)","Spades(草花)"};
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
	/*cout<<suits[m_suit]+"of"+faces[m_face]<<endl;*/
	
	return suits[m_suit]+"of"+faces[m_face];
}
inline Card& Card::setFace(int face)
{
	m_face=(face>=0&&face<=12?face:0);
	return *this;
}
inline Card& Card::setSuit(int suit)
{
	m_suit=(suit>=0&&suit<=3?suit:0);
	return *this;
}
int Card::getFace() const
{
	return m_face;
}
int Card::getSuit() const
{
	return m_suit;
}

class DeckOfCard
{
	vector<Card> deck; //一副牌
	int currentCard;//当前的牌的序号

public:
	DeckOfCard();
	DeckOfCard& shuffle(); //洗牌
	Card& dealCard(); //下一张
	bool moreCards() const;  //还有牌要处理吗？
	
};

DeckOfCard::DeckOfCard()
{
	Card s;
	for(int i=0;i<52;i++)
		deck.push_back(s.setFace(i%13).setSuit(i/13));
		currentCard=0;
}
DeckOfCard& DeckOfCard::shuffle()
{
	srand((unsigned)time(0));
	for(int i=0;i<52;i++)
	{
		Card another=deck[rand()%52];
		Card temp;
		temp=deck[i];
		deck[i]=another;
		another=temp;
	}
	return *this;
}
bool DeckOfCard::moreCards() const
{
	return (currentCard<52?true:false);
}
Card& DeckOfCard::dealCard()
{
	return deck[currentCard++];
}


class Hand
{
	Card *hand;
	int faceCount[13];
	int m_totalOfCard;
public:
	Hand(DeckOfCard&,int=5);
	bool pair();			//一对
	bool twoPair();			//两队
	bool threeOfAKind();	//3张同号
	bool fourOfAKind();		//4张同号
	bool flush();			//5张花色相同
	bool straight();		//5张面值连续
    void print();
	~Hand();
	
};
Hand::Hand(DeckOfCard& deck,int totalOfCard)
{
	for(int i=0;i<13;i++)
		faceCount[i]=0;
	if(totalOfCard>52)
	{
		cout<<"一手牌不能超过52张！";
		return;
	}
	m_totalOfCard=totalOfCard;
	hand=new Card[totalOfCard];
	if(!hand)
	{
		cout<<"no space for Card!";
		return;
	}
	for(int i=0;i<totalOfCard;i++){
		if (deck.moreCards())
		{
			hand[i]=deck.dealCard();
			faceCount[hand[i].getFace()]++;
		}
	}


}
bool Hand::pair()
{//一对
	for(int i=0;i<13;i++)
		if (2==faceCount[i])
			return true;
	return false;
}
bool Hand::twoPair()
{//两队
	bool flag=false;
	for(int i=0;i<13;i++)
		if (2==faceCount[i])
		{
			flag=true;
			break;
		}
	for(int i=0;flag && i<13;i++)
		if (2==faceCount[i])
			return true;
	return false;
}
bool Hand::threeOfAKind()
{//3张同号
	for(int i=0;i<13;i++)
		if (3==faceCount[i])
			return true;
	return false;
}
bool Hand::fourOfAKind()
{//4张同号
	for(int i=0;i<13;i++)
		if (4==faceCount[i])
			return true;
	return false;
}
bool Hand::flush()
{//5张花色相同
	int suit=hand[0].getSuit();
	int i=1;
	while(hand[i].getSuit()==suit && i<m_totalOfCard) 
		i++;
	if(5==i)
		return true;
	else
		return false;	
}
bool Hand::straight()
{//5张面值连续
	int i=0;
	if(faceCount[0]==1)
	{
		i += 13;
		while(faceCount[(--i)%13]==1);
		i++;
	}
	else
		while (faceCount[++i]==0);
	int j=0;	
	while (faceCount[(i++)%13]==1)
		j++;
	if(j==5)
		return true;
	else
		return false;

}
Hand::~Hand()
{
	delete[] hand;
}
void Hand::print()
{
	for(int i=0;i<m_totalOfCard;i++)
	{
		cout<<hand[i].toString()<<endl;
	}
}
void main()
{
	DeckOfCard deck;
	deck.shuffle();
	Hand hand(deck,5);
	hand.print();
	if(hand.pair())
		cout<<"一对"<<endl;
	if(hand.twoPair())
		cout<<" 两对"<<endl;
	if(hand.threeOfAKind())
		cout<<"三个同号"<<endl;
	if(hand.fourOfAKind())
		cout<<"四个同号"<<endl;
	if(hand.straight())
		cout<<"通顺"<<endl;
}

