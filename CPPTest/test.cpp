#include <iostream>

using namespace std;

int main(void)
{
	float a = 1.1;
	cout << a << '\n';
	cout << int(a) << '\n';
	cout << a << '\n';

	int *x[5];
	int(*y)[5];

	char *c = "a";
	printf("%s\n", c);
	printf("%d", int(*c));
}