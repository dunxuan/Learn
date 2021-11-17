#include <iostream>

using namespace std;

void exchangeValue(int * i, int * j);

int main(void)
{
	int i = 0, j = 1;

	exchangeValue(&i, &j);

	cout << i << '\t' << j << endl;
}

void exchangeValue(int * i, int * j)
{
	int * temp = i;
	i = j;
	j = temp;
}