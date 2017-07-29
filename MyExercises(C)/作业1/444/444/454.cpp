// 444.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>


int main()
{
  int rule(int x,int y,int z);
  int a,b,c,d,f,g;
  scanf("%d,%d,%d",&a,&b,&c);
  (d,f,g)=rule(a,b,c);
  printf("rule=%d,%d,%d\n",d,f,g);
  return 0;
}

int rule(int x,int y,int z)
{
  
  if(x>y && y>z)
    printf("%d,%d,%d",x,y,z);
  if(x>z && z>y)
	printf("%d,%d,%d",x,z,y);
  if(z>x && x>y)
	printf("%d,%d,%d",z,x,y);
  if(y>x && x>z)
    printf("%d,%d,%d",y,x,z);
  if(y>z && z>x)
    printf("%d,%d,%d",y,z,x);
  if(z>y && y>x)
	printf("%d,%d,%d",z,y,x);

         
}




