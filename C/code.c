#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>

char *fun(int *Digits, int count);
char *myitoa(int a, char *str);
int cmp(char **a, char **b);
//˫�����������
void swap(char **a, char **b);
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
	sprintf(str, "%d", a);
	return str;
}
int cmp(char **a, char **b)
{
	int aLength = strlen(a);
	int bLength = strlen(b);
	int maxLength = aLength < bLength ? bLength : aLength;
	char aTemp[6] = {0};
	char bTemp[6] = {0};
	strcpy(aTemp, a);
	strcpy(bTemp, b);
	char aFirst[1] = {a[0]};
	char bFirst[1] = {b[0]};
	if(strlen(a) < strlen(b)) {
		for(int i = strlen(a); i < maxLength; i++) {
			strcat(aTemp, aFirst);
		}
	} else {
		for(int i = strlen(b); i < maxLength; i++) {
			strcat(bTemp, bFirst);
		}
	}
	return strcmp(aTemp, bTemp);1
}

char *fun(int *Digits, int count)
{
	char *Max_Digit = (char *)malloc(sizeof(char) * count * 5 + 1);
	char Str_Digits[count][5];
	for(int i = 0; i < count * 5 + 1; i++) //��ʼ��������Ĵ����
	{
		Max_Digit[i] = 0;
	}
	for(int i = 0; i < count; i++)//����ת�ַ���
	{
		myitoa(Digits[i], Str_Digits[i]);
	}

	if(count == 1) {
		strcpy(Max_Digit, Str_Digits[0]);
		return Max_Digit;
	}
	//qsort(Str_Digits, count, sizeof(Str_Digits[0]), cmp);//�������ַ��������ȼ�
	DualPivotQuickSort(Str_Digits, 0, count - 1);

	for(int i = 0; i < count; i++)//��� 
	{
		strcat(Max_Digit, Str_Digits[i]);
	}
	if(Max_Digit[0] == '0') {
		strcpy(Max_Digit, "0");
	}
	return Max_Digit;
}

//˫�����������
void swap(char **a, char **b)
{
	char Temp[6];
	strcpy(Temp, a);
	strcpy(a, b);
	strcpy(b, Temp);
}
void DualPivotQuickSort(char *arr[], int low, int high)
{
	if(low < high) {
		// lp��ʾ�����ᣬrp��ʾ������
		int lp, rp;
		rp = partition(arr, low, high, &lp);
		DualPivotQuickSort(arr, low, lp - 1);
		DualPivotQuickSort(arr, lp + 1, rp - 1);
		DualPivotQuickSort(arr, rp + 1, high);
	}
}
int partition(char *arr[], int low, int high, int *lp)
{
	if(cmp(&arr[low], &arr[high]) > 0)
		swap(&arr[low], &arr[high]);
	// p�����࣬q������
	int j = low + 1;
	int g = high - 1, k = low + 1;
	char *p = arr[low], *q = arr[high];
	while(k <= g) {

		// ���Ԫ��С��������
		if(cmp(&arr[k], &p) < 0) {
			swap(&arr[k], &arr[j]);
			j++;
		}

		// ���Ԫ�ش��ڻ����������
		else if(cmp(&arr[k], &p) > 0) {
			while(cmp(&arr[k], &p) > 0 && k < g)
				g--;
			swap(&arr[k], &arr[g]);
			g--;
			if(cmp(&arr[k], &p) < 0) {
				swap(&arr[k], &arr[j]);
				j++;
			}
		}
		k++;
	}
	j--;
	g++;

	// ����������ʵ���λ��
	swap(&arr[low], &arr[j]);
	swap(&arr[high], &arr[g]);

	// �������������
	*lp = j;

	return g;
}