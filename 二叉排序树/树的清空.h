#pragma once
#define maxsize 1024
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include "二叉树的定义.h"
using namespace std;
int Clear(bstnode *p);//清空树

int Clear(bstnode *p)
{	
	if (!Judge(p))
	{
		return 1;
	};
	int i = 0;//判断的标志
	cout << "您是否要清空当前输入的树？" << endl;
	cout << "1、我确定" << endl;
	cout << "2、返回上一步" << endl;

	while (true)
	{
		cin >> i;
		if (i == 1)
		{
			cout << "树已经清空" << endl;
			system("pause");
			return 0;
			break;
		}
		else if (i == 2)
		{
			cout << "已返回上一步" << endl;
			system("pause");
			return 1;
			break;
		}
		else
		{
			cout << "请输入正确的选择！" << endl;
		}
		cin.clear();
		cin.ignore();
	}

}
