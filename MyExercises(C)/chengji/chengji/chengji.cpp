// chengji.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int score[8][2],temp[8][2];
	int i,j;
	int temp;

	for(i=0;i<=7;i++)
	{
		printf("��%dλ�˶�Ա����Ϊ��",i+1);
		scanf("%d",score[i][0]);
		printf("��%dλ�˶�Ա�ɼ�Ϊ��",i+1);
		scanf("%d",score[i][1]);
		strcpy(temp,score);
	}

	for(i=0;i<=7;i++)
	{
		if(score[i][1]>score[i+1][1])
		{
			score[i+1][1]=score[i][1];
		}
	}
	
	return 0;
}

