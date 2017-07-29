// 游泳池问题.cpp : 定义控制台应用程序的入口点。
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
	cout<<"请输入游泳池半径：（米）";
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
	
	cout<<"一圆型游泳池如图所示，现在需在其周围建一圆型过道，并在其四周围上栅栏。栅栏价格为35元/米，过道造价为20元/平方米。过道宽度为3米。"<<endl;
	
	circle.sett();
	cost1=PRICE1*circle.count_perim();
	cost2=PRICE2*circle.count_area();
	
	cout<<"过道的造价为：\n"<<cost2<<"元"<<endl;
	cout<<"栅栏的造价为：\n"<<cost1<<"元"<<endl;
}

