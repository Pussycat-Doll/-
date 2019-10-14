#define _CRT_SECURE_NO_WARNINGS 1
//12.要求循环队列（注意不设头指针），设置一个标志量tag, 
//以tag为0或1来区分头尾指针相同时的队列状态，请编写与此
//结构相应的入队与出队算法。
//flag为0时表示循环队列没有满的状态
//flag = 1 表示队列已满
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