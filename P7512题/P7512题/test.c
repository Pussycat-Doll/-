#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>
typedef int LSDataType;
typedef struct ListNode
{
	LSDataType _data;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

ListNode* BuyNode(LSDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}
//void ListInit(ListNode* plt, LSDataType x)//初始化
//{
//	assert(plt);
//	 plt = BuyNode(x);
//	plt->_next = plt;
//	plt->_prev = plt;
//}
//void ListPushBack(ListNode* plt, LSDataType x)//尾插
//{
//	assert(plt);
//	ListNode* newnode = BuyNode(x);//先创建一个新的结点
//	ListNode* head = plt;
//	ListNode* tail = plt->_prev;
//
//	tail->_next = newnode;
//	plt->_prev = newnode;
//	newnode->_next = plt;
//}
//
//void ListPrint(ListNode* plt)//打印链表
//{
//	assert(plt);
//	ListNode* head = plt;
//	ListNode* cur = head->_next;
//	while (cur != head)
//	{
//		printf("%d<===>", cur->_data);
//		cur = cur->_next;
//	}
//	printf("head\n");
//}
//int main()
//{
//	ListNode s1;
//	ListInit(&s1,1);
//	//ListPushBack(&s1, 8);
//	//ListPushBack(&s1, 7);
//	ListPrint(&s1);
//	system("pause");
//	return 0;
//}

void ListInit(List* plt)//初始化
{
	assert(plt);
	ListNode* head = BuyNode(0);
	head->_next = head;
	head->_prev = head;
	plt->_head = head;
}

void ListPushBack(List* plt, LSDataType x)//尾插
{
	assert(plt);
	ListNode* newnode = BuyNode(x);
	ListNode* head = plt->_head;
	ListNode* tail = head->_prev;

	newnode->_prev = tail;
	newnode->_next = head;

	tail->_next = newnode;
	head->_prev = newnode;
}
void ListPrint(List* plt)//打印链表
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	printf("head<===>");
	while (cur != head)
	{
		printf("%d<===>", cur->_data);
		cur = cur->_next;
	}
	printf("head\n");
}
ListNode* ListFind(List* plt, LSDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (x == cur->_data)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void ListErase(ListNode* pos)//删除Pos位置的结点
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
}
int main()
{
	List s1;
	ListInit(&s1);
	ListPushBack(&s1, 7);
	ListPushBack(&s1, 6);
	ListPushBack(&s1, 2);
	ListPushBack(&s1, 1);
	ListPushBack(&s1, 4);
	ListPushBack(&s1, 8);
	printf("原来的循环链表：\n");
	ListPrint(&s1);
	ListNode* pos = ListFind(&s1, 6);
	ListErase(pos);
	printf("删除结点6后的循环链表：\n");
	ListPrint(&s1);
	system("pause");
	return 0;
}
/*在本题目中，题目上说是对一个无头结点和头指针的双向循环链表进行操作，那么我们就让已知的那个结点指针成为头结点指针
好了，双向循环链表由于存在前后两个指针，这就使得找到那个要删除的结点简单很多*/