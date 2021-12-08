#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char * fun(int * Digits, int count);
int main()
{
	int Num = 0;
	scanf("%d", &Num);
	int Digits[Num];
	srand((unsigned int)time(NULL));

	for(int i = 0; i < Num; i++) {
		Digits[i] = rand() % 100000;
		printf("%d  ", Digits[i]);
	}
	char * s = fun(Digits, Num);

	printf("%s", s);

	return 0;
}

char GetCharFromStr(char * str, int offset)
{
	char c;
	int length = strlen(str);
	if(offset >= length) {
		c = str[0];
	} else {
		c = str[offset];
	}

	return c;
}

void Swap(char * a, char * b)
{
	char * Temp = (char *)malloc(5);
	for(int i = 0; i < 5; i++) {
		Temp[i] = 0;
	}
	strcpy(Temp, a);
	strcpy(a, b);
	strcpy(b, Temp);
	free(Temp);
}

void SimpleSelectionSort(char * A[], int N)
{

	/*int i, j, k, max;

	for(i = 0; i < N - 1; i++) {
		max = i;
		for(j = i + 1; j < N; j++) {
			k = 0;
			while(GetCharFromStr(A[j], k) == GetCharFromStr(A[max], k)) {
				k++;
			}
			if(GetCharFromStr(A[j], k) > GetCharFromStr(A[max], k)) {
				max = j;
			}
		}
		Swap(A[i], A[max]);
	}*/
}
char * fun(int * Digits, int count)
{
	char * Max_Digit = (char *)malloc(count * 5 + 1);
	char * Str_Digits[200];
	for(int i = 0; i < count * 5 + 1; i++) //��ʼ��������Ĵ���� 
	{
		Max_Digit[i] = 0;
	}
	for(int i = 0; i < 200; i++)//��ʼ��ÿ����ת�����ַ�����Ĵ���� 
	{
		Str_Digits[i][5] = "";
	}
	for(int i = 0; i < count; i++)//����ת�ַ��� 
	{
		sprintf(Str_Digits[i], "%d", Digits[i]);
	}

	if(count == 1) {
		strcpy(Max_Digit, Str_Digits[0]);
		return Max_Digit;
	}
	SimpleSelectionSort(Str_Digits, count);//�������ַ��������ȼ� 


	for(int i = 0; i < count; i++)//��� 
	{
		strcat(Max_Digit, Str_Digits[i]);
	}

	return Max_Digit;
}