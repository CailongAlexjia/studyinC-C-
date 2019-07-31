#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node
{
	int id;
	struct Node *next; //指针域
}Node;

//创建头结点
//链表的头结点地址由函数返回
Node *SListCreat()
{
	Node *head = NULL;
	
	//头结点作为标志，不存储有效数据
	head = (Node *)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}

	//给head成员变量赋值
	head->id = -1;
	head->next = NULL;

	Node *pCur = head;
	Node *pNew = NULL;

	int data;
	
	while (1)
	{
		printf("请输入数据：");
		scanf("%d", &data);

		if (data == -1)
		{
			break;
		}

		// 新建节点动态分配空间
		pNew = (Node *)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			break;
		}

		//给成员变量赋值
		pNew->id = data;
		pNew->next = NULL;

		//链表建立关系
		//当前节点的next指向pNew
		pCur->next = pNew;
		pNew->next = NULL;

		//把pCur移动到pNew,pCurz指向pNew
		pCur = pNew;


	}


	
	return head;
}


//链表的遍历
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
		
		//当前节点往下移动一位，pCur指向下一个
		pCur = pCur->next;

	}
	printf("NULL\n");
	return 0;

}


//在值为x的节点前，插入值为y的节点；若值为x的节点不存在，则插在表尾
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

		//寻找下个节点，pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next; //pCur指向下一个节点
	}
		//2种情况
		//1. 找匹配的节点，pCur为匹配节点为匹配节点，pPre为pCur上一个节点
		//2. 没有找到匹配的节点，pCur为空节点，pPre为最后一个节点
		//给新节点动态分配空间
		Node *pNew = (Node *)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			return -2;
		}

		//给新节点赋值
		pNew->id = y;
		pNew->next = NULL;

		//插入指定位置
		pPre->next = pNew;  //pPre下一个指向pNew
		pNew->next = pCur;  //pNew下一个指向pCur


	
	return 0;

}
//删除第一个值为x的节点
int SListNodeDel(Node * head, int x)
{
	if (head == NULL)
	{
		return 0;
	}
	
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0; //0没有找到，1找到

	while (pCur != NULL)
	{
		if (pCur->id == x) //找到了匹配的节点
		{
			//pPre的下一个指向pCur的下一个
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			flag = 1;

			break;
		}

		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next; //pCur指向下一个节点
	}

	if (0 == flag)
	{
		printf("没有值为%d的节点\n", x);
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
		//保存head的下一个节点
		tmp = head->next;
		free(head);
		head = NULL;

		//head指向tmp
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
			//pPre的下一个指向pCur的下一个
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			flag = 1;

			pCur = pPre->next;
			
			//break;
			continue;
		}
		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next;
	}

	if (0 == flag)
	{
		printf("没有值为%d的节点\n", x);
		return -2;
	}

	return 0;
}


//链表节点排序
int SListNodeSort(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return -1;
	}

	//简单数组排序
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

	// pPre->next != NULl, 链表第二个节点
	for (pPre = head->next; pPre->next != NULL; pPre = pPre->next)
	{
		for(pCur = pPre->next; pCur != NULL; pCur = pCur->next)
			
			if (pPre->id > pCur->id)//升序
			{
				//注意排序中除了数据域需要交换，next指针还需要交换
				if (pPre->id > pCur->id)
				{
					//只交换数据域
					tmp.id = pCur->id;
					pCur->id = pPre->id;
					*pPre = tmp;

#if 0 
					//交换数据域
					tmp = *pCur;
					*pCur = *pPre;
					*pPre = tmp;

					//交换指针域
					tmp.next = pCur->next;
					pCur->next = pPre->next;
					pPre->next = tmp.next;
#endif
				}
			}
	}

	return 0;
}

//假如原来链表是升序的，升序插入节点
//不能插入节点后再排序，是升序插入新节点x
int SListNodeInsertPro(Node *head, int x)
{
	//保证插入前是有序的
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

	//1 2 3 4 5 6 插入4
	//3:pre, 5:cur
	while (pCur != NULL)
	{
		if (pCur->id > x)
		{
			break;
		}
		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next;
	}
	//2种情况
	//1.找匹配的节点，pCur为匹配节点，pPre为pCur上一个节点
	//2.没有找到匹配节点，pCur为空节点，pPre为最后一个节点

	//给新节点动态分配存
	Node *pNew = (Node *)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}
	//给插入节点赋值
	pNew->id = x;
	pNew->next = NULL;

	//插入指定位置
	pPre->next = pNew;
	pNew->next = pCur;

	return 0;

}




// 翻转链表的节点（不是排序，是翻转）
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
	//链表的遍历
	SListPrint(head);

	//链表中插入数据
	SlistNodeInsert(head, 5, 4);
	//链表的遍历
	SListPrint(head);

	//链表删除第一个为x的节点
	SListNodeDel(head, 6);
	//遍历链表
	SListPrint(head);


	//删除所有值为x的节点
	SListNodeDelPro(head, 5);
	//遍历列表
	SListPrint(head);

	SListNodeSort(head);
	printf("排序后\n");
	SListPrint(head);

	SListNodeInsertPro(head, 5);
	printf("升序插入6后\n");
	SListPrint(head);


	SListNodeReverse(head);
	printf("链表翻转后\n");
	SListPrint(head);



	//清空链表，释放所有节点
	SListNodeDestroy(head);
	head = NULL;
	//遍历列表
	//SListPrint(head);




	

	printf("\n");
	system("pause");
	return 0;
}
