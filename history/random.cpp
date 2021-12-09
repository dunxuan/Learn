#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
	for (;;)	{
		srand((unsigned)time(NULL));

		cout << "(a, b) 之间的随机数";
		cout << endl;
		cout << "输入a:";
		int a = 0;
		cin >> a;
		cout << "输入b:";
		int b = 0;
		cin >> b;

		int random = rand() % (b - a + 1) + a;

		cout << random;
		cout << endl;
	}
	return 0;
}