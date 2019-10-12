//求两个数的最大公约数。
#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a%b == 0)
	{
		printf("%d",b);
	}
	else
	{
		int c;
		while(a%b != 0)
		{

			c = a%b;
			a = b;
			b = c;	
		}
		printf("%d",c);	
	}
	return 0;
}
