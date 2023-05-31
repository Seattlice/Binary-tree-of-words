#pragma once
#define maxsize 1024
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include "二叉树的定义.h"
using namespace std;


bstnode * InsertBST(bstnode *t, bstnode *s);//建立树的函数
bstnode *CreatBST(char sentence[maxsize], bstnode *t);//读入文本的文件
bstnode *Construction(bstnode *m);//建立树的文件

//建立树 
bstnode * InsertBST(bstnode *t, bstnode *s)
{
	int i = 0;
	if (t == NULL)  t = s;  //建立根节点 
	else
	{
		//判断是否节点相同  判断s与t的data是否一致 
		if (strcmp(s->data,t->data)== 0)
		{
			t->number++;
		}
		else
		{
			//单词不同 判断首字母是否相同 
			if (s->data[i] != t->data[i])
			{
				if (s->data[i] < t->data[i])
					t->lchild = InsertBST(t->lchild, s);
				else if (s->data[0] > t->data[0])
					t->rchild = InsertBST(t->rchild, s);
			}
			//首字母相同时  依次查找不同的字母，按字母顺序排列 
			while (s->data[i] == t->data[i])
			{
				if (s->data[i + 1] < t->data[i + 1])
				{
					t->lchild = InsertBST(t->lchild, s);
					break;
				}
				else if (s->data[i + 1] > t->data[i + 1])
				{
					t->rchild = InsertBST(t->rchild, s);
					break;
				}
				i++;
			}
		}
	}
	return t;
}

bstnode *CreatBST(char sentence[maxsize], bstnode *t)
{
	bstnode  *s;
	int i, j = 0, length;
	//初始化 
	s = (bstnode*)malloc(sizeof(bstnode));
	//t = (bstnode*)malloc(sizeof(bstnode));
	s->lchild = s->rchild = NULL;
	s->number = 0;
	//t = NULL;
	//求出句子长度 
	length = strlen(sentence);
	//将单词输入开辟的临时节点s中 
	for (i = 0; i <= length; i++)
	{
		if (sentence[i] != ' ')  //读取单词，空格表示单词读入完毕 
		{
			s->data[j] = sentence[i];
			j++;
		}
		else if (sentence[i] == ' ')
		{
			s->number++;         //单词个数加1 
			s->data[j++] = '\0'; //输入字符串结束符 
			t = InsertBST(t, s);  //插入树中
			//重新初始化临时结点s 
			s = (bstnode*)malloc(sizeof(bstnode));
			s->lchild = s->rchild = NULL;
			s->number = 0;
			j = 0;
		}
		//将最后一个单词入树，没这一步的话，最后一个单词没法入树 
		if (i == length)
		{
			s->number++;
			t = InsertBST(t, s);
		}
	}
	return t;
}

bstnode *Construction(bstnode *m)
{
	int i, j = 0, len = 0;
	char sentence1[maxsize], sentence2[maxsize], ch, *words[maxsize], a;
	//bstnode *m;//返回的树
	//m = (bstnode*)malloc(sizeof(bstnode));
	printf("请输入您要读入的英文文本：（输入#以结束输入）\n");
	//读入并处理输入文本
	//scanf_s("%s", sentence1, sizeof(sentence1));
	//cin >> sentence1;
	//gets_s(sentence1,maxsize);
	scanf("%[^#]", sentence1);
	//scanf("%s", sentence1);
	//cin.getline(sentence1,1024);
	cout << endl;
	cout << "************您输入的文本为:***********" << endl;
	cout << sentence1 << endl;
	//cin >> sentence1;
	len = strlen(sentence1);
	if (!isalpha(sentence1[len - 1]))  sentence1[len - 1] = '\0';
	for (i = 0, j = 0; i < len; i++)
	{
		//除去数字、标点，并将大写转为小写 
		if (isupper(sentence1[i])) sentence1[i] = sentence1[i] + 32;
		if (islower(sentence1[i])) sentence2[j++] = sentence1[i];
		else if (sentence1[i] == ' '&&sentence1[i + 1] == ' ') continue;    //两个空格 
		else if (sentence1[i] == ' '&&ispunct(sentence1[i + 1])) continue; //空格加符号 
		else if (sentence1[i + 1] == ' '&&ispunct(sentence1[i])) continue;  //符号加空格 
		else if (ispunct(sentence1[i]) && sentence1[i] == '-') sentence2[j++] = '-';  //连字符 
		else if (ispunct(sentence1[i]) && sentence1[i] == '\'') sentence2[j++] = '\'';
		else if (ispunct(sentence1[i]) && ispunct(sentence1[i + 1])) i++;  //多个符号 
		else if (sentence1[i] == ' ') sentence2[j++] = sentence1[i];
		else if (ispunct(sentence1[i])) sentence2[j++] = ' ';

	}
	sentence2[j] = '\0';
	cout << endl;
	cout << "***************处理过的句子为：*************" << endl;
	cout << sentence2 << endl;//输出处理过的句子 
	m = CreatBST(sentence2,m);
	cout << endl;
	cout << "当前文本的树已建立完成" << endl;
	system("pause");
	return m;
}
