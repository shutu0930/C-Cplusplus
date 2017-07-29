// c1-3.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>


void main()
{
	float r,h,C,S1,S2,V1,V2;
	printf("r=");
	scanf("%f",&r);
	
	printf("h=");
	scanf("%f",&h);

	const float pi=3.14159;

	C=2*pi*r;
	S1=pi*r*r;
	S2=4*S1;
	V1=(4/3)*pi*r*r*r;
	V2=pi*r*r*h;
	
	printf("圆周长=%7.2f\n圆面积=%7.2f\n圆球表面积=%7.2f\n圆球体积=%7.2f\n圆柱体积=%7.2f\n",C,S1,S2,V1,V2);

}

