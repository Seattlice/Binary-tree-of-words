#pragma once
#define maxsize 1024
#include<stdio.h>
#include<string.h>
#include<iostream>

#include<cstdlib>
#include "�������Ķ���.h"
using namespace std;
static char A[maxsize];
static int i = 0;

void DeleteLeft(node *p, node *q);//ɾ���õ��ʵĺ�����ɾ������������
void DeleteRight(node *p, node *q);//ɾ���õ��ʵĺ�����ɾ������������
void  HeadDelete(node *T);//�ж�ɾ��ͷ���ĺ���
int Delete(node *T);//ɾ���ڵ���ܸ�������
void Bsearch(node*T, node*child);//���ҵĺ���
void DoubleDelete(node *T);//ɾ���������������Ľ��



void DoubleDelete(node *T)
{
	node *par, *s;
	par = new node;
	s = new node;
	par = T;
	s = T->rchild;
	if (s != NULL)
	{
		while (s->lchild != NULL)
		{
			par = s;
			s = s->lchild;
		}
	}
	strcpy(T->data, s->data);
	//p->data = &s->data;
	if (par == T)
	{
		par->rchild = s->rchild;
	}
	else
	{
		par->lchild = s->rchild;
	}

}

void  HeadDelete(node *T)
{
	node *s;
	s = new node;
	s = NULL;
	if (T->lchild == NULL)
	{
		s = T->rchild;
		strcpy(T->data, T->rchild->data);
		T->lchild = s->lchild;
		T->rchild = s->rchild;

	}
	else if (T->rchild == NULL)
	{
		s = T->lchild;
		strcpy(T->data, T->lchild->data);
		T->lchild = s->lchild;
		T->rchild = s->rchild;
	}
	else
	{
		DoubleDelete(T);
	}
	s = NULL;
	free(s);
}
void DeleteLeft(node *p, node *q)//ɾ���õ��ʵĺ�����ɾ������������
{//pָ��ɾ���Ľ�㣬p��q������
	node *par, *s;
	par = new node;
	s = new node;
	if ((p->lchild == NULL) && (p->rchild == NULL))//pΪҶ��
	{
		q->lchild = NULL;
	}
	else if (p->rchild == NULL)//pֻ��������
	{
		q->lchild = p->lchild;
	}
	else if (p->lchild == NULL)//pֻ��������
	{
		q->lchild = p->rchild;
	}
	else//p������������Ѱ�������������½��
	{
		DoubleDelete(p);
	}
}

void DeleteRight(node *p, node *q)//ɾ���õ��ʵĺ��������õ���������
{//pָ��ɾ���Ľ�㣬p��q���Һ���
	node *par, *s;
	par = new node;
	s = new node;
	if ((p->lchild == NULL) && (p->rchild == NULL))//pΪҶ��
	{
		q->rchild = NULL;
	}
	else if (p->rchild == NULL)//pֻ��������
	{
		q->rchild = p->lchild;
	}
	else if (p->lchild == NULL)//pֻ��������
	{
		q->rchild = p->rchild;
	}
	else//p������������Ѱ�������������½��
	{
		DoubleDelete(p);
	}
}

void Bsearch(node*T,node*child)
{
	if (child != NULL)
	{
		if (strcmp(child->data, A) > 0)
		{
			if (child->lchild != NULL)
			{
					Bsearch(child, child->lchild);
			}
		}
		else if (strcmp(child->data, A) < 0)
		{
			if(child->rchild != NULL)
			{
					Bsearch(child, child->rchild
					);
			}
		}
		else if (strcmp(child->data, A) == 0)
		{
			i = 1;
			if (T->lchild != NULL)
			{
				if (strcmp(T->lchild->data, A) == 0)
				{
					DeleteLeft(T->lchild, T);
				}
			}
			if(T->rchild != NULL)
			{ 
				if (strcmp(T->rchild->data, A) == 0)
				{
					DeleteRight(T->rchild, T);
				}
			}
		}
	}
}


void Down(node *T)
{
	node *B;
	B = new node;
	 Bsearch(T, T->lchild);
	 Bsearch(T, T->rchild);
}

int Delete(node *T)//ɾ���ڵ���ܸ�������
{
	if (!Judge(T))
	{
		return 1;
	};
	cout << "��������Ҫɾ���ĵ��ʻ����б����ж��������#�Խ���(�м��ûس��ָ�)" << endl;
	scanf("%s", A);
	
		while (strcmp(A, "#") != 0)
		{
			if (strcmp(T->data, A) == 0)//��һ���ж��Ƿ�ɾ��ͷ���
			{
				if ((T->lchild == NULL )&&( T->rchild == NULL))
				{
					cout << "�Ѿ���ȫɾ������������������������!" << endl;
					system("pause");
					return 0;
				}
				else
				{
					i = 1;
					HeadDelete(T);
				}
			}
			else//�ж��Ƿ�ɾ������
			{
				Down(T);
			}

			if (i == 0)//��ӡ����ĺ���
			{
				cout << "δ�ҵ��õ���: "<<A<<" ,ɾ��ʧ�ܣ�������ȷ��Ҫɾ���ĵ���" << endl;
			}
			else
			{
				cout << "�Ѿ�ɾ���� " << A << " �������" << endl;
			}
			i = 0;

			scanf("%s", A);
			if (strcmp(A, "#") == 0)
			{
				break;
			}
		}

	cout << "*********�Ѿ����ɾ������*********" << endl;
	system("pause");
	return 1;
}
