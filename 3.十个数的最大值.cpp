//求10 个整数中最大值。
#include<stdio.h>
int main()
{
	int a[10];
	int max;
	for(int i = 0;i < 10;i++)
	{
		scanf("%d",&a[i]);
	}
	max = a[0];
	for(int j = 0;j < 10;j++)
	{
		if(a[j] > max)
		{
			max = a[j];
		}
	}
	printf("%d",max);	
	return 0;	
} 
