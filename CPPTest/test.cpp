#include <iostream>

using namespace std;

enum test{
	a, b, c
};


int main(void)
{
	test m = a;
	cout << m << '\n';
	cout << test(int(m) + 1) << endl;

	float n = 1.1;
	cout << n << '\n';
	cout << int(n) << endl;
}