#include<string.h>
#include <stdio.h>
#include "二叉树的定义.h"


void inorder(node *T, char word[]);//中序遍历查找单词
void Search(node *root);//寻找的主函数

static int flag = 0;
void Search(node *root)
{
	if (!Judge(root))
	{
		return;
	};

	int number1 = 0;
	datatype words[50] = { 0 };
	
	//printf("你想查询的单词数量是:");
		//scanf("%d", &number1);

	while(strcmp(words, "#") != 0)
	{
		printf("请输入单词：(中间以空格或者回车分割，输入#以结束)\n");
		scanf("%s", words);
		if (strcmp(words, "#") == 0)
		{
			break;
		}

		//words[50] = getline();
		//datatype a[strlen(words) + 1];
		datatype a[maxsize];
		strcpy(a, words);
		flag = 0;
		
		inorder(root, a);
		if (flag == 0)
		{
			printf("单词%s未在文章中出现或者已经被删除了哦！ \n\n", a);
			flag = 0;
		}

	}
	cout << "**********本次查询已完成*********" << endl;
	system("pause");
}

void inorder(node *T, char word[])//中序遍历查找单词
{
	if (T != NULL)    //二叉树p非空
	{
		inorder(T->lchild, word);    //中序遍历左子树
		if (strcmp(word, T->data) == 0)
		{
			printf("单词%s在文章出现次数为 %d\n\n", T->data, T->number);   //访问根节点的数据域
			flag = 1;
		}
		inorder(T->rchild, word);//中序遍历右子树
	}
}