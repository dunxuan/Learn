long cmp(int * x, int * y);
char * fun(int * A, int N);
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
	int a[5] = { 0 };
	/*for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}*/
	char * s = fun(a, 0);
	printf(s);
}

#include <stdlib.h>

long cmp(int * x, int * y)
{
	long sx = 10, sy = 10;
	while (sx <= *x) {
		sx *= 10;
	}
	while (sy <= *y) {
		sy *= 10;
	}
	return sx * (*y) + (*x) - sy * (*x) - (*y);
}

char * fun(int * A, int N)
{
	if (!N) {
		return "\0";
	}
	qsort(A, N, sizeof(int), cmp);
	if (A[0] == 0) {
		char * ret = malloc(sizeof(char) * 2);
		ret[0] = '0', ret[1] = '\0';
		return "0";
	}
	char * ret = malloc(sizeof(char) * N * 5 + 1);
	char * p = ret;
	for (int i = 0; i < N; i++) {
		sprintf(p, "%d", A[i]);
		p += strlen(p);
	}
	return ret;
}