#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char * fun(int * Digits, int count);
int main()
{
	int i, n;
	scanf("%d", &n);
	srand(n);
	int d[n];
	if (n < 10)
		for (i = 0; i < n; i++)
			scanf("%d", d + i);
	char * s = fun(d, n);
	printf(s);
}

char GetCharFromStr(char * str, int offset)
{
	char c;
	int length = strlen(str);
	if (offset >= length) {
		c = str[0];
	} else {
		c = str[offset];
	}

	return c;
}
void myitoa(int a, char * str)
{
	int length;
	int i = 0;
	char c;
	while (a != 0) {
		switch (a % 10) {
		case 0:
			str[i] = '0';
			break;
		case 1:
			str[i] = '1';
			break;
		case 2:
			str[i] = '2';
			break;
		case 3:
			str[i] = '3';
			break;
		case 4:
			str[i] = '4';
			break;
		case 5:
			str[i] = '5';
			break;
		case 6:
			str[i] = '6';
			break;
		case 7:
			str[i] = '7';
			break;
		case 8:
			str[i] = '8';
			break;
		case 9:
			str[i] = '9';
			break;
		}
		i++;
		a = a / 10;
	}
	length = strlen(str);
	for (int i = 0; i < length / 2; i++) {
		c = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = c;
	}

	str[length] = '\0';
}
void Swap(char * a, char * b)
{
	char * Temp = (char *)malloc(5);
	for (int i = 0; i < 5; i++) {
		Temp[i] = 0;
	}
	strcpy(Temp, a);
	strcpy(a, b);
	strcpy(b, Temp);
	free(Temp);
}

void SimpleSelectionSort(char * A[], int N)
{
	int i, j, max;
	int k = 0;

	for (i = 0; i < N - 1; i++) {
		max = i;
		for (j = i + 1; j < N; j++) {
			k = 0;
			while (GetCharFromStr(A[j], k) == GetCharFromStr(A[max], k)) {
				k++;
			}
			if (GetCharFromStr(A[j], k) > GetCharFromStr(A[max], k)) {
				max = j;
			}
		}
		Swap(A[i], A[max]);
	}
}
char * fun(int * Digits, int count)
{
	char * Max_Digit = (char *)malloc(1000);
	char * Str_Digits[200];
	for (int i = 0; i < 1000; i++) //初始化最大数的存放区 
	{
		Max_Digit[i] = 0;
	}
	for (int i = 0; i < 200; i++)//初始化每个数转换成字符串后的存放区 
	{
		Str_Digits[i] = (char *)malloc(5);
		for (int j = 0; j < 5; j++) {
			Str_Digits[i][j] = 0;
		}
	}
	for (int i = 0; i < count; i++)//数字转字符串 
	{
		myitoa(Digits[i], Str_Digits[i]);
	}

	if (count == 1) {
		strcpy(Max_Digit, Str_Digits[0]);
		return Max_Digit;
	}
	SimpleSelectionSort(Str_Digits, count);//排序获得字符串的优先级 


	for (int i = 0; i < count; i++)//组合 
	{
		strcat(Max_Digit, Str_Digits[i]);
	}

	return Max_Digit;
}
