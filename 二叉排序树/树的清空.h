#pragma once
#define maxsize 1024
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include "�������Ķ���.h"
using namespace std;
int Clear(bstnode *p);//�����

int Clear(bstnode *p)
{	
	if (!Judge(p))
	{
		return 1;
	};
	int i = 0;//�жϵı�־
	cout << "���Ƿ�Ҫ��յ�ǰ���������" << endl;
	cout << "1����ȷ��" << endl;
	cout << "2��������һ��" << endl;

	while (true)
	{
		cin >> i;
		if (i == 1)
		{
			cout << "���Ѿ����" << endl;
			system("pause");
			return 0;
			break;
		}
		else if (i == 2)
		{
			cout << "�ѷ�����һ��" << endl;
			system("pause");
			return 1;
			break;
		}
		else
		{
			cout << "��������ȷ��ѡ��" << endl;
		}
		cin.clear();
		cin.ignore();
	}

}
