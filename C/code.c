在这里给出函数被调用进行测试的例子。例如：
#include <stdio.h>
/struct stu {
	int num;
	char name[20];
	int score;
};
void fun(struct stu * p, int n);
int main()
{
	struct stu a[20];
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%s%d", &a[i].num, a[i].name, &a[i].score);
	}
	fun(a, n);
	for (i = 0; i < n; i++)
		printf("%d %s %d\n", a[i].num, a[i].name, a[i].score);
	return 0;
}
/* 请在这里填写答案 */

