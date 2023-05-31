#pragma once
#include <iostream>
using namespace std;
const int maxsize = 1024;


typedef char datatype;//节点定义
typedef struct node
{
	int  number = 0;
	datatype data[maxsize];
	struct node *lchild = NULL, *rchild = NULL;

}bstnode;

int Judge(bstnode *p);//判断是否为空结点的函数

int Judge(bstnode *p)
{
	if (p == NULL)
	{
		cout << "您尚未输入文本文件！" << endl;
		system("pause");
		return 0;
	}

}