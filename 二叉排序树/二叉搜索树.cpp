#include <iostream>
#include <string>
#include<cstdlib>
#include "展示与退出.h"
#include "搜索.h"
#include "删除.h"
#include "二叉树的定义.h"
#include "二叉树的创建.h"
#include "中序输出树.h"
#include "树的清空.h"
using namespace std;

int main()
{
	node* HeadTree;
	HeadTree = new node;
	HeadTree = NULL;
	int choice;//选择的flag
	while (true)
	{
		Show_Menu();//展示的函数

		cin >> choice;

		switch (choice)
		{
			case 1://创建树，读入文本文件
				if (HeadTree == NULL)
				{
					HeadTree = Construction(HeadTree);
				}
				else
				{
					cout << "***检测到您已输入了文本文件,请先清空文本文件再进行输入哦。***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 2://删除停用的树以及结点
				if (!Delete(HeadTree))
				{
					HeadTree = NULL;
				}
				system("cls");
				break;
			case 3://继续输入文本文件
				HeadTree = Construction(HeadTree);

				system("cls");
				break;
			case 4://输出单词及其单词次数
				Search(HeadTree);
				system("cls");
				break;
			case 5://中序输出树以及树的模样
				Printing(HeadTree);
				system("cls");
				break;
			case 6://清空当前树
				if (!Clear(HeadTree))
				{
					HeadTree = NULL;
				}
				system("cls");
				break;
			case 0://退出循环
				exitSystem();

			default://清屏
				system("cls");
				cout << "*********请输入正确的选择！**************" << endl;
				cout << endl;
				break;
		}
		cin.clear();
		cin.ignore();
	}

	system("pause");
	return 0;
}

