// �����������α�����ֵ��������ֵ�����ݽ��н�����
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
