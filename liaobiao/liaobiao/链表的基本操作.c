#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node
{
	int id;
	struct Node *next; //ָ����
}Node;

//����ͷ���
//�����ͷ����ַ�ɺ�������
Node *SListCreat()
{
	Node *head = NULL;
	
	//ͷ�����Ϊ��־�����洢��Ч����
	head = (Node *)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}

	//��head��Ա������ֵ
	head->id = -1;
	head->next = NULL;

	Node *pCur = head;
	Node *pNew = NULL;

	int data;
	
	while (1)
	{
		printf("���������ݣ�");
		scanf("%d", &data);

		if (data == -1)
		{
			break;
		}

		// �½��ڵ㶯̬����ռ�
		pNew = (Node *)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			break;
		}

		//����Ա������ֵ
		pNew->id = data;
		pNew->next = NULL;

		//��������ϵ
		//��ǰ�ڵ��nextָ��pNew
		pCur->next = pNew;
		pNew->next = NULL;

		//��pCur�ƶ���pNew,pCurzָ��pNew
		pCur = pNew;


	}


	
	return head;
}


//����ı���
int SListPrint(Node *head)
{
	if (head == NULL)
	{
		return -1;
	}

	Node *pCur = head->next;
	while (pCur != NULL)
	{
		printf("%d -> ", pCur->id);
		
		//��ǰ�ڵ������ƶ�һλ��pCurָ����һ��
		pCur = pCur->next;

	}
	printf("NULL\n");
	return 0;

}


//��ֵΪx�Ľڵ�ǰ������ֵΪy�Ľڵ㣻��ֵΪx�Ľڵ㲻���ڣ�����ڱ�β
int SlistNodeInsert(Node * head, int x, int y)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;
	
	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			break;
		}

		//Ѱ���¸��ڵ㣬pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next; //pCurָ����һ���ڵ�
	}
		//2�����
		//1. ��ƥ��Ľڵ㣬pCurΪƥ��ڵ�Ϊƥ��ڵ㣬pPreΪpCur��һ���ڵ�
		//2. û���ҵ�ƥ��Ľڵ㣬pCurΪ�սڵ㣬pPreΪ���һ���ڵ�
		//���½ڵ㶯̬����ռ�
		Node *pNew = (Node *)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			return -2;
		}

		//���½ڵ㸳ֵ
		pNew->id = y;
		pNew->next = NULL;

		//����ָ��λ��
		pPre->next = pNew;  //pPre��һ��ָ��pNew
		pNew->next = pCur;  //pNew��һ��ָ��pCur


	
	return 0;

}
//ɾ����һ��ֵΪx�Ľڵ�
int SListNodeDel(Node * head, int x)
{
	if (head == NULL)
	{
		return 0;
	}
	
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0; //0û���ҵ���1�ҵ�

	while (pCur != NULL)
	{
		if (pCur->id == x) //�ҵ���ƥ��Ľڵ�
		{
			//pPre����һ��ָ��pCur����һ��
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			flag = 1;

			break;
		}

		//pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next; //pCurָ����һ���ڵ�
	}

	if (0 == flag)
	{
		printf("û��ֵΪ%d�Ľڵ�\n", x);
		return -2;
	}
	
	

	return 0;
}


int SListNodeDestroy(Node * head)
{
	if (head == NULL)
	{
		return -1;
	}

	Node *tmp = NULL;
	int i = 0;

	while (head != NULL)
	{
		//����head����һ���ڵ�
		tmp = head->next;
		free(head);
		head = NULL;

		//headָ��tmp
		head = tmp;
		i++;


	}
	printf("i = %d\n", i);




	return 0;
}

int SListNodeDelPro(Node *head, int x)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0;

	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			//pPre����һ��ָ��pCur����һ��
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			flag = 1;

			pCur = pPre->next;
			
			//break;
			continue;
		}
		//pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next;
	}

	if (0 == flag)
	{
		printf("û��ֵΪ%d�Ľڵ�\n", x);
		return -2;
	}

	return 0;
}


//����ڵ�����
int SListNodeSort(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return -1;
	}

	//����������
#if 0
	int a[] = { 1, 2, 4, 5, 7,8 };
	int n = sizeof(a) / sizeof(a[0]);
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{

			}
		}

	}
#endif

	Node *pPre = NULL;
	Node *pCur = NULL;
	Node tmp;

	// pPre->next != NULl, ����ڶ����ڵ�
	for (pPre = head->next; pPre->next != NULL; pPre = pPre->next)
	{
		for(pCur = pPre->next; pCur != NULL; pCur = pCur->next)
			
			if (pPre->id > pCur->id)//����
			{
				//ע�������г�����������Ҫ������nextָ�뻹��Ҫ����
				if (pPre->id > pCur->id)
				{
					//ֻ����������
					tmp.id = pCur->id;
					pCur->id = pPre->id;
					*pPre = tmp;

#if 0 
					//����������
					tmp = *pCur;
					*pCur = *pPre;
					*pPre = tmp;

					//����ָ����
					tmp.next = pCur->next;
					pCur->next = pPre->next;
					pPre->next = tmp.next;
#endif
				}
			}
	}

	return 0;
}

//����ԭ������������ģ��������ڵ�
//���ܲ���ڵ������������������½ڵ�x
int SListNodeInsertPro(Node *head, int x)
{
	//��֤����ǰ�������
	int ret = SListNodeSort(head);

	if (ret !=0 )
	{
		return ret;
	}

	if (head == NULL)
	{
		return -1;
	}

	Node *pPre = head;
	Node *pCur = head->next;

	//1 2 3 4 5 6 ����4
	//3:pre, 5:cur
	while (pCur != NULL)
	{
		if (pCur->id > x)
		{
			break;
		}
		//pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next;
	}
	//2�����
	//1.��ƥ��Ľڵ㣬pCurΪƥ��ڵ㣬pPreΪpCur��һ���ڵ�
	//2.û���ҵ�ƥ��ڵ㣬pCurΪ�սڵ㣬pPreΪ���һ���ڵ�

	//���½ڵ㶯̬�����
	Node *pNew = (Node *)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}
	//������ڵ㸳ֵ
	pNew->id = x;
	pNew->next = NULL;

	//����ָ��λ��
	pPre->next = pNew;
	pNew->next = pCur;

	return 0;

}




// ��ת����Ľڵ㣨���������Ƿ�ת��
int SListNodeReverse(Node *head)
{
	if (head == NULL || head->next == NULL || head->next->next ==NULL)
	{
		return -1;
	}

	Node *pPre = head->next;
	Node *pCur = pPre->next;
	pPre->next = NULL;
	Node *tmp = NULL;

	while (pCur != NULL)
	{
		tmp = pCur->next;
		pCur->next = pPre;

		pPre = pCur;
		pCur = tmp;
	}
	//head->next->next = NULL;
	head->next = pPre;

	return 0;


 
}



int main()
{
	Node *head = NULL;

	head = SListCreat();
	//����ı���
	SListPrint(head);

	//�����в�������
	SlistNodeInsert(head, 5, 4);
	//����ı���
	SListPrint(head);

	//����ɾ����һ��Ϊx�Ľڵ�
	SListNodeDel(head, 6);
	//��������
	SListPrint(head);


	//ɾ������ֵΪx�Ľڵ�
	SListNodeDelPro(head, 5);
	//�����б�
	SListPrint(head);

	SListNodeSort(head);
	printf("�����\n");
	SListPrint(head);

	SListNodeInsertPro(head, 5);
	printf("�������6��\n");
	SListPrint(head);


	SListNodeReverse(head);
	printf("����ת��\n");
	SListPrint(head);



	//��������ͷ����нڵ�
	SListNodeDestroy(head);
	head = NULL;
	//�����б�
	//SListPrint(head);




	

	printf("\n");
	system("pause");
	return 0;
}
