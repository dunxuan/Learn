// 实现双枢轴QuickSort的C程序
#include <stdio.h>

int partition(int *arr, int low, int high, int *lp);

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void DualPivotQuickSort(int *arr, int low, int high)
{
	if(low < high) {
		// lp表示左枢轴，rp表示右枢轴。
		int lp, rp;
		rp = partition(arr, low, high, &lp);
		DualPivotQuickSort(arr, low, lp - 1);
		DualPivotQuickSort(arr, lp + 1, rp - 1);
		DualPivotQuickSort(arr, rp + 1, high);
	}
}

int partition(int *arr, int low, int high, int *lp)
{
  	if(arr[low] > arr[high])
		swap(&arr[low], &arr[high]);
	// p是左枢，q是右枢。
	int j = low + 1;
	int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
	while(k <= g) {

		// 如果元素小于左枢轴
		if(arr[k] < p) {
			swap(&arr[k], &arr[j]);
			j++;
		}

		// 如果元素大于或等于右枢轴
		else if(arr[k] >= q) {
			while(arr[g] > q && k < g)
				g--;
			swap(&arr[k], &arr[g]);
			g--;
			if(arr[k] < p) {
				swap(&arr[k], &arr[j]);
				j++;
			}
		}
		k++;
	}
	j--;
	g++;

	// 把枢轴带到适当的位置。
	swap(&arr[low], &arr[j]);
	swap(&arr[high], &arr[g]);

	// 返回枢轴的索引。
	*lp = j;

	return g;
}

// Driver code
int main()
{
	int arr[] = { 24, 8, 42, 75, 29, 77, 38, 57 };
	DualPivotQuickSort(arr, 0, 7);
	printf("Sorted array: ");
	for(int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
