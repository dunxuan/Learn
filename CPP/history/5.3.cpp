#include <iostream>

//#define LENGTH 10

using namespace std;

int main(void)
{
	typedef struct	{
		int digit = 0;
		int * next = NULL;
	} list;
	int length = 0;
	cout << "输入e结束输入"；
	do	{
		cin >> 
	}
	int array[LENGTH] = {0};

	for (int i = 0; i < LENGTH; i++)	{
		cin >> array[i];
	}
	
	for (int j = 1, i = 0, key = 0; j < LENGTH; j++)	{
		key = array[j];
		for (i = j - 1; i >= 0 && array[i] > key; i--)	{
			array[i + 1] = array[i];
		}
		array[i + 1] = key;
	}

	for (int i = 0; i < LENGTH; i++)	{
		cout << array[i];
	}

	return 0;
}