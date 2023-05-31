#pragma once
#define maxsize 1024
#include<stdio.h>
#include<string.h>
#include<iostream>

#include<cstdlib>
#include "二叉树的定义.h"
using namespace std;
static char A[maxsize];
static int i = 0;

void DeleteLeft(node *p, node *q);//删除该单词的函数，删除的是左子树
void DeleteRight(node *p, node *q);//删除该单词的函数，删除的是右子树
void  HeadDelete(node *T);//判断删除头结点的函数
int Delete(node *T);//删除节点的总概括函数
void Bsearch(node*T, node*child);//查找的函数
void DoubleDelete(node *T);//删除具有两个子树的结点



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
void DeleteLeft(node *p, node *q)//删除该单词的函数，删除的是左子树
{//p指向被删除的结点，p是q的左孩子
	node *par, *s;
	par = new node;
	s = new node;
	if ((p->lchild == NULL) && (p->rchild == NULL))//p为叶子
	{
		q->lchild = NULL;
	}
	else if (p->rchild == NULL)//p只有左子树
	{
		q->lchild = p->lchild;
	}
	else if (p->lchild == NULL)//p只有右子树
	{
		q->lchild = p->rchild;
	}
	else//p有左右子树，寻找右子树中左下结点
	{
		DoubleDelete(p);
	}
}

void DeleteRight(node *p, node *q)//删除该单词的函数，调用的是右子树
{//p指向被删除的结点，p是q的右孩子
	node *par, *s;
	par = new node;
	s = new node;
	if ((p->lchild == NULL) && (p->rchild == NULL))//p为叶子
	{
		q->rchild = NULL;
	}
	else if (p->rchild == NULL)//p只有左子树
	{
		q->rchild = p->lchild;
	}
	else if (p->lchild == NULL)//p只有右子树
	{
		q->rchild = p->rchild;
	}
	else//p有左右子树，寻找右子树中左下结点
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

int Delete(node *T)//删除节点的总概括函数
{
	if (!Judge(T))
	{
		return 1;
	};
	cout << "请输入你要删除的单词或者列表，若有多个，输入#以结束(中间用回车分割)" << endl;
	scanf("%s", A);
	
		while (strcmp(A, "#") != 0)
		{
			if (strcmp(T->data, A) == 0)//这一步判断是否删除头结点
			{
				if ((T->lchild == NULL )&&( T->rchild == NULL))
				{
					cout << "已经完全删除二叉排序树，请重新输入!" << endl;
					system("pause");
					return 0;
				}
				else
				{
					i = 1;
					HeadDelete(T);
				}
			}
			else//判断是否删除孩子
			{
				Down(T);
			}

			if (i == 0)//打印输出的函数
			{
				cout << "未找到该单词: "<<A<<" ,删除失败，请重新确认要删除的单词" << endl;
			}
			else
			{
				cout << "已经删除了 " << A << " 这个单词" << endl;
			}
			i = 0;

			scanf("%s", A);
			if (strcmp(A, "#") == 0)
			{
				break;
			}
		}

	cout << "*********已经完成删除操作*********" << endl;
	system("pause");
	return 1;
}
