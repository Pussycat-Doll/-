// 给定两个整形变量的值，将两个值的内容进行交换。
#include<stdio.h>
int change(int a,int b)
{
	int t;
	t = a;
	a = b;
	b = t;
	printf("%d %d",a,b);
}
	 
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	change(a,b);
	return 0;
} 
