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
//void ListInit(ListNode* plt, LSDataType x)//��ʼ��
//{
//	assert(plt);
//	 plt = BuyNode(x);
//	plt->_next = plt;
//	plt->_prev = plt;
//}
//void ListPushBack(ListNode* plt, LSDataType x)//β��
//{
//	assert(plt);
//	ListNode* newnode = BuyNode(x);//�ȴ���һ���µĽ��
//	ListNode* head = plt;
//	ListNode* tail = plt->_prev;
//
//	tail->_next = newnode;
//	plt->_prev = newnode;
//	newnode->_next = plt;
//}
//
//void ListPrint(ListNode* plt)//��ӡ����
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

void ListInit(List* plt)//��ʼ��
{
	assert(plt);
	ListNode* head = BuyNode(0);
	head->_next = head;
	head->_prev = head;
	plt->_head = head;
}

void ListPushBack(List* plt, LSDataType x)//β��
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
void ListPrint(List* plt)//��ӡ����
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
void ListErase(ListNode* pos)//ɾ��Posλ�õĽ��
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
	printf("ԭ����ѭ������\n");
	ListPrint(&s1);
	ListNode* pos = ListFind(&s1, 6);
	ListErase(pos);
	printf("ɾ�����6���ѭ������\n");
	ListPrint(&s1);
	system("pause");
	return 0;
}
/*�ڱ���Ŀ�У���Ŀ��˵�Ƕ�һ����ͷ����ͷָ���˫��ѭ��������в�������ô���Ǿ�����֪���Ǹ����ָ���Ϊͷ���ָ��
���ˣ�˫��ѭ���������ڴ���ǰ������ָ�룬���ʹ���ҵ��Ǹ�Ҫɾ���Ľ��򵥺ܶ�*/