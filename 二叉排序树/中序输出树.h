#pragma once
#define maxsize 1024
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include "�������Ķ���.h"

void Printing(bstnode *p);//��������ܺ���
int inorder(bstnode *p);//����������ĺ���
void PrintBiTree(bstnode *T, int n);//��ӡ��ģ���ĺ���


void Printing(bstnode *p)
{
	if (!Judge(p))
	{
		return;
	};
	cout << "******************************************************" << endl;
	cout << "�����������������Ϊ����(һ������Ϊһ��)��" << endl;
	inorder(p);//�������
	cout << endl;
	cout << "******************************************************" << endl;
	cout << "���Ĵ��ģ��Ϊ����(�������ҿ��������Ϊ���ڵ� ,�ֵ�������)��" << endl;
	PrintBiTree(p, 2);//ģ�����
	system("pause");
}




//�������(�������)
int inorder(bstnode *p)
{
	if (p != NULL)
	{

		inorder(p->lchild);
		cout <<"���ݣ�"<< p->data <<"\t\t���ֵĴ�����\t"<<p->number<< endl;
		inorder(p->rchild);
	}
	return 0;
}



//����ģ�����
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
