
#include <stdio.h>
#define N 4
#define M 3
#include <stdio.h>     
int Row, Col;          // 最大数的行列标，全局变量
int fun(int array[N][M]);
int main()
{
	int a[N][M], i, j, max;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &a[i][j]);
	max = fun(a);
	printf("max=%d,row=%d,col=%d", max, Row, Col); //Row,Col代表最大值的下标
}

/* 请在这里填写答案 */

int fun(int array[N][M])
{
	int max = array[0][0];
	Row = 0;
	Col = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (array[i][j] > max) {
				max = array[i][j];
				Row = i;
				Col = j;
			}
		}
	}
	return max;
}