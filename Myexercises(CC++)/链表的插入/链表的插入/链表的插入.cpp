// ����Ĳ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define LEN sizeof(struct person)
#define N 5

struct person *addAnode(struct person *head,struct person temp);
struct person *insert(struct person *head,struct person temp);
void print(struct person *head);
struct person
{
	char name[8];
	int num;
	struct person *next;
};
void main()
{
	struct person *head=0;
	struct person temp;
	int i;
	for(i=0;i<N;i++)
	{
		printf("��%d���ˣ�\n������",i+1);
		gets(temp.name);
		printf("�ɼ���");
		scanf("%d",&temp.num);
		getchar();
		head=addAnode(head,temp);
	}
	printf("Ҫ������˵�������");
	scanf("%s",temp.name);
	printf("�ɼ���");
	scanf("%d",&temp.num);
	head=insert(head,temp);

	print(head);
	
}
struct person *addAnode(struct person *head,struct person temp)
{
	struct person *ptemp=(struct person *)malloc(LEN);

	if(ptemp==0)
	{
		return head;
	}
	*ptemp=temp;
	ptemp->next=0;
	if(head==0)
	{
		head=ptemp;
	}
	else
	{
		struct person *p=head;
		while(p->next)
		{
			p=p->next;
		}
		p->next=ptemp;
		ptemp->next=0;
	}

	return head;

}
struct person *insert(struct person *head,struct person temp)
{
	struct person *ptemp=(struct person *)malloc(LEN);
	*ptemp=temp;
	struct person *p1,*p2;
	p1=p2=head;

	if(head==0)
	{
		return head;
	}
	if(ptemp->num<head->num)
	{
		head=ptemp;
		ptemp->next=p1;
	}
	while(p1)
	{
		if(ptemp->num<p1->num)
		{
			break;
		}
		p2=p1;
		p1=p1->next;
	}
	ptemp->next=p1;
	p2->next=ptemp;
	
	return head;
}

void print(struct person *head)
{
	struct person *p;
	p=head;
	if(head!=NULL)
	{
		do
		{
			printf("������%-8s�ɼ���%-3d\n",p->name,p->num);
			p=p->next;
		}while(p!=NULL);
	}



}

