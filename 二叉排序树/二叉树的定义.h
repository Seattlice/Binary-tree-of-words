#pragma once
#include <iostream>
using namespace std;
const int maxsize = 1024;


typedef char datatype;//�ڵ㶨��
typedef struct node
{
	int  number = 0;
	datatype data[maxsize];
	struct node *lchild = NULL, *rchild = NULL;

}bstnode;

int Judge(bstnode *p);//�ж��Ƿ�Ϊ�ս��ĺ���

int Judge(bstnode *p)
{
	if (p == NULL)
	{
		cout << "����δ�����ı��ļ���" << endl;
		system("pause");
		return 0;
	}

}