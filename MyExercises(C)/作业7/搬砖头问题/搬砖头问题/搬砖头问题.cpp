// ��שͷ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


void main()
{
	int man,woman,child;
	
	printf("��36��שͷ����36�������ᣬ��������ÿ��ֻ�ܰ�4�飬Ů��ÿ��ֻ�ܰ�2�飬\nС��ÿ��2�˲��ܰ�1�飬Ҫ��һ���԰��꣬û���˿��֣������ˣ�Ů�˺�С���������ˣ�\n");
	
	for(man=1;man<9;man++)
	{
		for(woman=1;woman<18;woman++)														//2��forѭ�����Ƕ��
		{
			child=36-(man+woman);
			if(child%2==0 && 4*man+2*woman+0.5*child==36)									//�������Ҫ���С����
				printf("\n��ã�\n�У�%d��\nŮ��%d��\nС����%d��\n",man,woman,child);
		
		}
	
	
	}



}

