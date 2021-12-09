#include <iostream>

using namespace std;

int main(void)
{
	int m = 0;
	int n = 0;

	cout << "输入两个正整数：";
	cin >> m;
	cin >> n;
	while (m <= 0 || n <= 0)	{
		cout << "输入错误，请重新输入：";
		cin >> m;
		cin >> n;
	}

	int r = 1;
	int p = m * n;
	while (r)	{
		r = m % n;
		m = n;
		n = r;
	}
	int LCM = p / m;

	cout << "最小公倍数是：";
	cout << LCM;
	cout << endl;
	cout << "最大公约数是：";
	cout << m;
	cout << endl;

	return 0;
}