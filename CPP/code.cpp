#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>

char *fun(int *Digits, int count);
char *myitoa(int a, char *str);
int cmp(char a[], char b[]);
//双枢轴快速排序
void swap(char *a, char *b);
void DualPivotQuickSort(char *arr[], int low, int high);
int partition(char *arr[], int low, int high, int *lp);

int main()
{
	int Num = 0;
	scanf("%d", &Num);
	int Digits[Num];
	//srand((unsigned)time(NULL));
	for(int i = 0; i < Num; i++) {
		//Digits[i] = rand() % 100000;
		scanf("%d", Digits + i);
	}
	char *s = fun(Digits, Num);

	printf("%s", s);

	return 0;
}

char *myitoa(int a, char *str)
{
	int length = 0;
	int i = 0;
	char c;
	int temp = a;
	while(temp) {
		length++;
		temp /= 10;
	}
	sprintf(str, "%d", a);
	return str;
}
int cmp(char a[], char b[])
{
	int maxLength = strlen(a) < strlen(b) ? strlen(b) : strlen(a);
	char *aTemp = malloc(sizeof(char) * maxLength + 1);
	char *bTemp = malloc(sizeof(char) * maxLength + 1);
	strcpy(aTemp, a);
	strcpy(bTemp, b);
	if(strlen(a) < strlen(b)) {
		for(int i = strlen(a); i < maxLength; i++) {
			strcat(aTemp, a[0]);
		}
	} else {
		for(int i = strlen(b); i < maxLength; i++) {
			strcat(bTemp, b[0]);
		}
	}
	return strcmp(aTemp, bTemp) < 0 ? 1 : -1;
}

char *fun(int *Digits, int count)
{
	char *Max_Digit = (char *)malloc(sizeof(char) * count * 5 + 1);
	char Str_Digits[count][5];
	for(int i = 0; i < count * 5 + 1; i++) //初始化最大数的存放区
	{
		Max_Digit[i] = 0;
	}
	for(int i = 0; i < count; i++)//数字转字符串
	{
		myitoa(Digits[i], Str_Digits[i]);
	}

	if(count == 1) {
		strcpy(Max_Digit, Str_Digits[0]);
		return Max_Digit;
	}
	//qsort(Str_Digits, count, sizeof(Str_Digits[0]), cmp);//排序获得字符串的优先级
	DualPivotQuickSort(Str_Digits, 0, count - 1);//排序获得字符串的优先级,双枢轴快速排序

	for(int i = 0; i < count; i++)//组合 
	{
		strcat(Max_Digit, Str_Digits[i]);
	}
	if(Max_Digit[0] == '0') {
		return "0";
	}
	return Max_Digit;
}

//双枢轴快速排序
void swap(char *a, char *b)//交换两个字符串 
{
	char *Temp = (char *)malloc(5);
	for(int i = 0; i < 5; i++) {
		Temp[i] = 0;
	}
	strcpy(Temp, a);
	strcpy(a, b);
	strcpy(b, Temp);
	free(Temp);
}
void DualPivotQuickSort(char *arr[], int low, int high)
{
	if(low < high) {
		// lp表示左枢轴，rp表示右枢轴
		int lp, rp;
		rp = partition(arr, low, high, &lp);
		DualPivotQuickSort(arr, low, lp - 1);
		DualPivotQuickSort(arr, lp + 1, rp - 1);
		DualPivotQuickSort(arr, rp + 1, high);
	}
}
int partition(char *arr[], int low, int high, int *lp)
{
	if(cmp(arr[low], arr[high]) > 0)
		swap(arr[low], arr[high]);
	// p是左枢，q是右枢
	int j = low + 1;
	int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
	while(k <= g) {

		// 如果元素小于左枢轴
		if(cmp(arr[k], p) < 0) {
			swap(arr[k], arr[j]);
			j++;
		}

		// 如果元素大于或等于右枢轴
		else if(cmp(arr[k], p) > 0) {
			while(cmp(arr[k], p) > 0 && k < g)
				g--;
			swap(arr[k], arr[g]);
			g--;
			if(cmp(arr[k], p) < 0) {
				swap(arr[k], arr[j]);
				j++;
			}
		}
		k++;
	}
	j--;
	g++;

	// 把枢轴带到适当的位置
	swap(arr[low], arr[j]);
	swap(arr[high], arr[g]);

	// 返回枢轴的索引
	*lp = j;

	return g;
}