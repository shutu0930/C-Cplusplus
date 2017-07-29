// 实验.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"

void main()
{
  int i,j;
  for(i=0;i<8;i++)
  {
    for(j=0;j<8;j++)
      if((i+j)%2==0)
        printf("%c%c",219,219);
      else
        printf("  ");
    printf("\n");
  }
  getchar(); 
}

