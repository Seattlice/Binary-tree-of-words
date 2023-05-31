#pragma once
#define maxsize 1024
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include "二叉树的定义.h"

void Printing(bstnode *p);//树输出的总函数
int inorder(bstnode *p);//中序输出树的函数
void PrintBiTree(bstnode *T, int n);//打印树模样的函数


void Printing(bstnode *p)
{
	if (!Judge(p))
	{
		return;
	};
	cout << "******************************************************" << endl;
	cout << "中序输出的树的数据为如下(一个数据为一行)：" << endl;
	inorder(p);//中序输出
	cout << endl;
	cout << "******************************************************" << endl;
	cout << "树的大概模样为如下(从左往右看，最左边为根节点 ,兄弟树对齐)：" << endl;
	PrintBiTree(p, 2);//模样输出
	system("pause");
}




//树的输出(中序遍历)
int inorder(bstnode *p)
{
	if (p != NULL)
	{

		inorder(p->lchild);
		cout <<"数据："<< p->data <<"\t\t出现的次数：\t"<<p->number<< endl;
		inorder(p->rchild);
	}
	return 0;
}



//树的模样输出
void PrintBiTree(bstnode *T, int n)
{
	int i;
	char ch = '	';
	if (T) {
		PrintBiTree(T->rchild, n + 1);
		for (i = 1; i <= n; ++i) { printf("%8c", ch); }
		printf("%s\n", T->data);
		PrintBiTree(T->lchild, n + 1);
	}
}
