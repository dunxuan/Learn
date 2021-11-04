#include <stdio.h>

int f(int *i);

int main(void)
{
	int i = 1;
	printf("%d\t",i);
	f(&i);
	printf("%d", i);

	return 0;
}

int f(int * i)
{
	  *i *= 2;
}