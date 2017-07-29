// 搬砖头问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


void main()
{
	int man,woman,child;
	
	printf("有36块砖头，请36个人来搬，其中男人每次只能搬4块，女人每次只能搬2块，\n小孩每次2人才能搬1块，要求一次性搬完，没有人空手，求男人，女人和小孩各多少人？\n");
	
	for(man=1;man<9;man++)
	{
		for(woman=1;woman<18;woman++)														//2层for循环语句嵌套
		{
			child=36-(man+woman);
			if(child%2==0 && 4*man+2*woman+0.5*child==36)									//求出满足要求的小孩数
				printf("\n求得：\n男：%d人\n女：%d人\n小孩：%d人\n",man,woman,child);
		
		}
	
	
	}



}

