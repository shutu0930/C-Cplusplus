// c1-1.cpp : 定义控制台应用程序的入口点。
//

#include<stdio.h>
#include<math.h>


void main()
{
	float d,p,r,m;
	
	d=300000.0;
	p=6000.0;
	r=0.01;
	
	m=log10(p/(p-d*r))/log10(1+r);
	
	printf("m=%7.1f\n",m);

}

