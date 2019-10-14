#define _CRT_SECURE_NO_WARNINGS 1
//12.Ҫ��ѭ�����У�ע�ⲻ��ͷָ�룩������һ����־��tag, 
//��tagΪ0��1������ͷβָ����ͬʱ�Ķ���״̬�����д���
//�ṹ��Ӧ�����������㷨��
//flagΪ0ʱ��ʾѭ������û������״̬
//flag = 1 ��ʾ��������
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QuDataType;
typedef struct Cyc_queue
{
	QuDataType* _arr;
	size_t _front;
	size_t _tail;
	size_t _capacity;
}Cyc_queue;

void Cyc_QueInit(Cyc_queue* ps)
{
	assert(ps);
	ps->_arr = NULL;
	ps->_front = ps->_tail = 0;
	ps->_capacity = 0;
}
void Cyc_QueDestory(Cyc_queue* ps)
{
	assert(ps);
	free(ps->_arr);
	ps->_arr = NULL;
	ps->_front = ps->_tail = 0;
	ps->_capacity = 0;
}

bool IsEmpty(Cyc_queue* ps)
{
	assert(ps);
	return  ps->_tail == ps->_front == 0;
}
void Cyc_QuePush(Cyc_queue* ps, QuDataType x)
{
	assert(ps);
	if (IsEmpty ||ps->_tail +1 == ps->_front)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 2 : ps->_capacity * 2;
		ps->_arr = (QuDataType*)realloc(ps->_arr, sizeof(QuDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->_arr[ps->_tail++] = x;

}
void Cyc_QuePop(Cyc_queue* ps)
{
	assert(ps && ps->_tail > 0);
	ps->_tail--;
}
int main()
{
	Cyc_queue q;
	Cyc_QueInit(&q);
	Cyc_QuePush(&q, 5);
	Cyc_QuePush(&q, 4);
	Cyc_QuePush(&q, 3);
	Cyc_QuePush(&q, 2);
	Cyc_QuePush(&q, 1);
	Cyc_QuePop(&q);
	system("pause");
	return 0;
}