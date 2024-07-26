#include <stdio.h>
#include<math.h>
#define MAX 10001

int h(int num)
{
	int temp=num;
	while (num != 0)
	{
		temp += num % 10;
		num /= 10;
	}
	return temp;
}

int main()
{
	int n = 0,a[MAX]={0,};
	for (int i = 0; i < MAX; i++)
	{
		n = h(i);
		if (n < MAX) a[n] = 1;
		if (a[i] == 0) printf("%d ", i);
	}
	
}