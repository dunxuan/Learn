#include <iostream>
#include <cmath>

#define BASE 10

using namespace std;

int main(void)
{
	cout << "计算Sn = a + aa + …… + aa……a(n个a)";
	int a = 0;
	cout << endl;
	cout << "输入数字a：";
	cin >> a;
	int n = 0;
	cout << "输入个数n：";
	cin >> n;

	long long Sn = 0;
	for (int i = 1; i <= n; i++)	{
		Sn += a * i * pow(BASE, n - i);
	}

	cout << "Sn=";
	cout << Sn;

	return 0;
}