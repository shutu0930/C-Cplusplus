// c1-3.cpp : �������̨Ӧ�ó������ڵ㡣
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
	
	printf("Բ�ܳ�=%7.2f\nԲ���=%7.2f\nԲ������=%7.2f\nԲ�����=%7.2f\nԲ�����=%7.2f\n",C,S1,S2,V1,V2);

}

