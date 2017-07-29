// zuoye5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
float bianch(float num1,float num2,float num3,float num4)
{
   float cheji,lenth;
   cheji=(num1-num3)*(num1-num3)+(num2-num4)*(num2-num4);
   lenth=sqrt(cheji);
   return(lenth);
}
float area(float lenth1,float lenth2,float lenth3)
{
	float s,area;
	s=(lenth1+lenth2+lenth3)/2;
	area=sqrt(s*(s-lenth1)*(s-lenth2)*(s-lenth3));
	return(area);
}
int main()
{
	float n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,lenth1,lenth2,lenth3,lenth4,lenth5,lenth6,lenth7,area1,area2,area3,Area;
	printf("请输入凸五边形各点坐标（）（）（）（）（）\n");
	scanf("(%f,%f)(%f,%f)(%f,%f)(%f,%f)(%f,%f)",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8,&n9,&n10);
	lenth1=bianch(n1,n2,n3,n4);
	lenth2=bianch(n3,n4,n5,n6);
	lenth3=bianch(n5,n6,n7,n8);
	lenth4=bianch(n7,n8,n9,n10);
	lenth5=bianch(n9,n10,n1,n2);
	lenth6=bianch(n3,n4,n9,n10);
	lenth7=bianch(n5,n6,n9,n10);
	area1=area(lenth1,lenth2,lenth6);
	area2=area(lenth3,lenth6,lenth7);
	area3=area(lenth4,lenth5,lenth7);
	Area=area1+area2+area3;
	printf("该凸五边形面积为：%f",Area);
	return 0;


}

