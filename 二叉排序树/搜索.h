#include<string.h>
#include <stdio.h>
#include "�������Ķ���.h"


void inorder(node *T, char word[]);//����������ҵ���
void Search(node *root);//Ѱ�ҵ�������

static int flag = 0;
void Search(node *root)
{
	if (!Judge(root))
	{
		return;
	};

	int number1 = 0;
	datatype words[50] = { 0 };
	
	//printf("�����ѯ�ĵ���������:");
		//scanf("%d", &number1);

	while(strcmp(words, "#") != 0)
	{
		printf("�����뵥�ʣ�(�м��Կո���߻س��ָ����#�Խ���)\n");
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
			printf("����%sδ�������г��ֻ����Ѿ���ɾ����Ŷ�� \n\n", a);
			flag = 0;
		}

	}
	cout << "**********���β�ѯ�����*********" << endl;
	system("pause");
}

void inorder(node *T, char word[])//����������ҵ���
{
	if (T != NULL)    //������p�ǿ�
	{
		inorder(T->lchild, word);    //�������������
		if (strcmp(word, T->data) == 0)
		{
			printf("����%s�����³��ִ���Ϊ %d\n\n", T->data, T->number);   //���ʸ��ڵ��������
			flag = 1;
		}
		inorder(T->rchild, word);//�������������
	}
}