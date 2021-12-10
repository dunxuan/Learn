#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char * fun(int * Digits, int count);
char * myitoa(int a, char * str);
int cmp(char a[], char b[]);

int main()
{
	int Num = 0;
	scanf("%d", &Num);
	int Digits[Num];

	for(int i = 0; i < Num; i++) {
		scanf("%d", Digits + i);
	}
	char * s = fun(Digits, Num);

	printf("%s", s);

	return 0;
}

char * myitoa(int a, char * str)
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
	char * aTemp = malloc(sizeof(char) * maxLength + 1);
	char * bTemp = malloc(sizeof(char) * maxLength + 1);
	char aFirst[1] = { a[0] };
	char bFirst[1] = { b[0] };
	sprintf(aTemp, "%s", a);
	sprintf(bTemp, "%s", b);
	if(strlen(a) < strlen(b)) {
		for(int i = strlen(a); i < maxLength; i++) {
			strcat(aTemp, aFirst);
		}
	} else {
		for(int i = strlen(b); i < maxLength; i++) {
			strcat(bTemp, bFirst);
		}
	}
	return strcmp(aTemp, bTemp) < 0 ? 1 : -1;
}
char * fun(int * Digits, int count)
{
	char * Max_Digit = (char *)malloc(sizeof(char) * count * 5 + 1);
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
	qsort(Str_Digits, count, sizeof(Str_Digits[0]), cmp);//排序获得字符串的优先级 

	for(int i = 0; i < count; i++)//组合 
	{
		strcat(Max_Digit, Str_Digits[i]);
	}
	if(Max_Digit[0] == '0') {
		strcat(Max_Digit, "0");
	}
	return Max_Digit;
}
