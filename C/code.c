#include <stdio.h>
#include <stdlib.h>

struct stu {
	int num;
	char name[20];
	int score;
};

void fun(struct stu *p, int n);
int cmp(struct stu *a, struct stu *b);

int main()
{
	struct stu a[20];
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d%s%d", &a[i].num, a[i].name, &a[i].score);
	}
	fun(a, n);
	for(i = 0; i < n; i++)
		printf("%d %s %d\n", a[i].num, a[i].name, a[i].score);
	return 0;
}

int cmp(struct stu *a, struct stu *b)
{
	return a->score > b->score ? -1 : 1;
}

void fun(struct stu *p, int n)
{
	qsort(p, n, sizeof(struct stu), cmp);
}