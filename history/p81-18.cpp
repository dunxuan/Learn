#include <iostream>

using namespace std;

int main(void)
{
	long long endResult = 1;
	long long singleResult = 1;

	for (int i = 2; i <= 20; i++)	{
		singleResult *= i;
		endResult += singleResult;
	}

	cout << "=";
	cout << endResult;
	cout << endl;

	return 0;
}