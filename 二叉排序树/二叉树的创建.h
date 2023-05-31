#pragma once
#define maxsize 1024
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include "�������Ķ���.h"
using namespace std;


bstnode * InsertBST(bstnode *t, bstnode *s);//�������ĺ���
bstnode *CreatBST(char sentence[maxsize], bstnode *t);//�����ı����ļ�
bstnode *Construction(bstnode *m);//���������ļ�

//������ 
bstnode * InsertBST(bstnode *t, bstnode *s)
{
	int i = 0;
	if (t == NULL)  t = s;  //�������ڵ� 
	else
	{
		//�ж��Ƿ�ڵ���ͬ  �ж�s��t��data�Ƿ�һ�� 
		if (strcmp(s->data,t->data)== 0)
		{
			t->number++;
		}
		else
		{
			//���ʲ�ͬ �ж�����ĸ�Ƿ���ͬ 
			if (s->data[i] != t->data[i])
			{
				if (s->data[i] < t->data[i])
					t->lchild = InsertBST(t->lchild, s);
				else if (s->data[0] > t->data[0])
					t->rchild = InsertBST(t->rchild, s);
			}
			//����ĸ��ͬʱ  ���β��Ҳ�ͬ����ĸ������ĸ˳������ 
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
	//��ʼ�� 
	s = (bstnode*)malloc(sizeof(bstnode));
	//t = (bstnode*)malloc(sizeof(bstnode));
	s->lchild = s->rchild = NULL;
	s->number = 0;
	//t = NULL;
	//������ӳ��� 
	length = strlen(sentence);
	//���������뿪�ٵ���ʱ�ڵ�s�� 
	for (i = 0; i <= length; i++)
	{
		if (sentence[i] != ' ')  //��ȡ���ʣ��ո��ʾ���ʶ������ 
		{
			s->data[j] = sentence[i];
			j++;
		}
		else if (sentence[i] == ' ')
		{
			s->number++;         //���ʸ�����1 
			s->data[j++] = '\0'; //�����ַ��������� 
			t = InsertBST(t, s);  //��������
			//���³�ʼ����ʱ���s 
			s = (bstnode*)malloc(sizeof(bstnode));
			s->lchild = s->rchild = NULL;
			s->number = 0;
			j = 0;
		}
		//�����һ������������û��һ���Ļ������һ������û������ 
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
	//bstnode *m;//���ص���
	//m = (bstnode*)malloc(sizeof(bstnode));
	printf("��������Ҫ�����Ӣ���ı���������#�Խ������룩\n");
	//���벢���������ı�
	//scanf_s("%s", sentence1, sizeof(sentence1));
	//cin >> sentence1;
	//gets_s(sentence1,maxsize);
	scanf("%[^#]", sentence1);
	//scanf("%s", sentence1);
	//cin.getline(sentence1,1024);
	cout << endl;
	cout << "************��������ı�Ϊ:***********" << endl;
	cout << sentence1 << endl;
	//cin >> sentence1;
	len = strlen(sentence1);
	if (!isalpha(sentence1[len - 1]))  sentence1[len - 1] = '\0';
	for (i = 0, j = 0; i < len; i++)
	{
		//��ȥ���֡���㣬������дתΪСд 
		if (isupper(sentence1[i])) sentence1[i] = sentence1[i] + 32;
		if (islower(sentence1[i])) sentence2[j++] = sentence1[i];
		else if (sentence1[i] == ' '&&sentence1[i + 1] == ' ') continue;    //�����ո� 
		else if (sentence1[i] == ' '&&ispunct(sentence1[i + 1])) continue; //�ո�ӷ��� 
		else if (sentence1[i + 1] == ' '&&ispunct(sentence1[i])) continue;  //���żӿո� 
		else if (ispunct(sentence1[i]) && sentence1[i] == '-') sentence2[j++] = '-';  //���ַ� 
		else if (ispunct(sentence1[i]) && sentence1[i] == '\'') sentence2[j++] = '\'';
		else if (ispunct(sentence1[i]) && ispunct(sentence1[i + 1])) i++;  //������� 
		else if (sentence1[i] == ' ') sentence2[j++] = sentence1[i];
		else if (ispunct(sentence1[i])) sentence2[j++] = ' ';

	}
	sentence2[j] = '\0';
	cout << endl;
	cout << "***************������ľ���Ϊ��*************" << endl;
	cout << sentence2 << endl;//���������ľ��� 
	m = CreatBST(sentence2,m);
	cout << endl;
	cout << "��ǰ�ı������ѽ������" << endl;
	system("pause");
	return m;
}
