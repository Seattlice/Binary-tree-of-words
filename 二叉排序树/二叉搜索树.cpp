#include <iostream>
#include <string>
#include<cstdlib>
#include "չʾ���˳�.h"
#include "����.h"
#include "ɾ��.h"
#include "�������Ķ���.h"
#include "�������Ĵ���.h"
#include "���������.h"
#include "�������.h"
using namespace std;

int main()
{
	node* HeadTree;
	HeadTree = new node;
	HeadTree = NULL;
	int choice;//ѡ���flag
	while (true)
	{
		Show_Menu();//չʾ�ĺ���

		cin >> choice;

		switch (choice)
		{
			case 1://�������������ı��ļ�
				if (HeadTree == NULL)
				{
					HeadTree = Construction(HeadTree);
				}
				else
				{
					cout << "***��⵽�����������ı��ļ�,��������ı��ļ��ٽ�������Ŷ��***" << endl;
					system("pause");
				}
				system("cls");
				break;
			case 2://ɾ��ͣ�õ����Լ����
				if (!Delete(HeadTree))
				{
					HeadTree = NULL;
				}
				system("cls");
				break;
			case 3://���������ı��ļ�
				HeadTree = Construction(HeadTree);

				system("cls");
				break;
			case 4://������ʼ��䵥�ʴ���
				Search(HeadTree);
				system("cls");
				break;
			case 5://����������Լ�����ģ��
				Printing(HeadTree);
				system("cls");
				break;
			case 6://��յ�ǰ��
				if (!Clear(HeadTree))
				{
					HeadTree = NULL;
				}
				system("cls");
				break;
			case 0://�˳�ѭ��
				exitSystem();

			default://����
				system("cls");
				cout << "*********��������ȷ��ѡ��**************" << endl;
				cout << endl;
				break;
		}
		cin.clear();
		cin.ignore();
	}

	system("pause");
	return 0;
}

