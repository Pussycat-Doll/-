#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	size_t _size;
	size_t _capacity;
}SeqList;


void SeqListInit(SeqList* ps)//��ʼ��
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}

void SeqListDestory(SeqList* ps)//����
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

SeqListCheckCapacity(SeqList* ps)//����Ƿ���Ҫ���ݣ���ִ��
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 4 : ps->_capacity * 2;
		ps->_array = (DataType*)realloc(ps->_array, sizeof(DataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* ps, DataType x)//β��
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;

	//SeqListInsert(ps, ps->_size, x);
}
void SeqListPushFront(SeqList* ps, DataType x)//ͷ��
{
	assert(ps);
	SeqListCheckCapacity(ps);
	size_t i = 0;
	for (i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = x;
	ps->_size++;

	//SeqListInsert(ps, 0, x);
}
void SeqListPopBack(SeqList* ps)//βɾ
{
	assert(ps && ps->_size > 0);
	ps->_size--;

	//SeqListErase(ps, ps->_size-1);
}
void SeqListPopFront(SeqList* ps)//ͷɾ
{
	assert(ps);
	size_t i = 0;
	for (i = 0; i < ps->_size - 1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_array[ps->_size - 1] = 0;
	ps->_size--;

	//SeqListErase(ps, 0);
}
void SeqListInsert(SeqList* ps, size_t pos, DataType x)//��ĳ��λ�ò���һ��Ԫ��
{
	assert(ps && pos <= ps->_size);
	SeqListCheckCapacity(ps);
	size_t i = 0;
	for (i = ps->_size; i > pos; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList* ps, size_t pos)//ɾ��ĳ��λ�õ�Ԫ��
{
	assert(ps && pos < ps->_size);
	size_t i = 0;
	for (i = pos; i < ps->_size - 1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}
int SeqListSize(SeqList* ps)//����˳���ʵ������Ԫ�صĸ���
{
	assert(ps);
	return ps->_size;
}

void swap(int* a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
SeqList Separat(SeqList* ps)
{
	int begin = 0;
	//int end = ps->_size - 1;
	int end = SeqListSize(ps) - 1;
	while (begin <= end)
	{
		while (begin <= end && ps->_array[begin] % 2 == 1)
		{
			++begin;
		}
		while (begin <= end && ps->_array[end] % 2 == 0)
		{
			--end;
		}
		if (begin < end)
		{
			swap(&ps->_array[begin], &ps->_array[end]);
		}
	}
	return *ps;
}

void Print(SeqList* ps)
{
	for (size_t i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 3 );
	Print(&s);
	Separat(&s);
	printf("����ż�������\n");
	Print(&s);

	SeqListDestory(&s);

	system("pause");
	return 0;
}
//���������΢ѧϰ��һ�����ݽṹ�����Զ���˳��ı�д�о����Ǻ��ѣ�������һЩС��ϸ����Ҫע��
//���磺����һ������Ҫ����Ƿ���Ҫ���ݣ����ж�һ���½�����˳���Ҫ���г�ʼ��������֮��Ҫ�ǵ����١�
//�����������Ŀ��˵�����Լ���������˼������ŵ�˼��Ƚ�����,Ϊ��ʹʱ�临�ӶȴﵽO(N),��Ҫǰ����
//����ָ��ͬʱ���������Ұѷ������������ݽ��н���������һ����Ҳ�����ٿ����µĿռ䡣