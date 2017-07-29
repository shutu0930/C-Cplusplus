// 计算出该凸五边形的面积.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
void main()
{
	double place[10];
	int i;
	double area(double place[10]);
	
	printf("请输入凸五边形五个顶点的坐标：\n");
	for(i=0;i<10;i+=2)
	{
			printf("第%d个顶点：",i/2+1);
			scanf("%lf,%lf",&place[i],&place[i+1]);
	}
	
	
	printf("这个凸五边形的面积为：\n%.3lf\n",area(place));

}

double area(double place[])
{
	double S1,S2,S3,S;
	double lenth(double n1,double n2,double n3,double n4);
	double areas(double len1,double len2,double len3);
	double len1,len2,len3,len4,len5,len6,len7;
	
	len1=lenth(place[0],place[1],place[2],place[3]);
	len2=lenth(place[2],place[3],place[4],place[5]);
	len3=lenth(place[4],place[5],place[6],place[7]);
	len4=lenth(place[6],place[7],place[8],place[9]);
	len5=lenth(place[8],place[9],place[0],place[1]);
	len6=lenth(place[2],place[4],place[8],place[9]);
	len7=lenth(place[4],place[5],place[8],place[9]);
	
	S1=areas(len1,len2,len6);
	S2=areas(len3,len6,len7);
	S3=areas(len4,len5,len7);
	
	S=S1+S2+S3;

	return S;
}

double lenth(double n1,double n2,double n3,double n4)
{
	double len,res;
	res=(n1-n3)*(n1-n3)+(n2-n4)*(n2-n4);
	len=sqrt(1.0*res);
	
	return len;
}

double areas(double len1,double len2,double len3)
{
	double s,S;
	s=(len1+len2+len3)/2.0;
	S=sqrt(1.0*s*(s-len1)*(s-len2)*(s-len3));
	return S;

}

