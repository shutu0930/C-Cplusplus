// ��Ӿ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>
using namespace std;
#define PI 3.14
#define PRICE1 35
#define PRICE2 20

class countc
{
	double rad1,rad2,area1,area2;
public:
	void sett();
	double count_perim();
	double count_area();

};
void countc::sett()
{
	cout<<"��������Ӿ�ذ뾶�����ף�";
	cin>>rad1;
	rad2=rad1+3;

}
double countc::count_perim()
{
	return 2*PI*rad2;

}
double countc::count_area()
{
	area1=PI*rad1*rad1;
	area2=PI*rad2*rad2;
	return (area2-area1);
}
void main()
{
	countc circle;
	double cost1,cost2;
	
	cout<<"һԲ����Ӿ����ͼ��ʾ��������������Χ��һԲ�͹���������������Χ��դ����դ���۸�Ϊ35Ԫ/�ף��������Ϊ20Ԫ/ƽ���ס��������Ϊ3�ס�"<<endl;
	
	circle.sett();
	cost1=PRICE1*circle.count_perim();
	cost2=PRICE2*circle.count_area();
	
	cout<<"���������Ϊ��\n"<<cost2<<"Ԫ"<<endl;
	cout<<"դ�������Ϊ��\n"<<cost1<<"Ԫ"<<endl;
}

