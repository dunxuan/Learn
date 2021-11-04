#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long sum2_01(int num);
long long sum2_02(int num);

int main()
{
	long long sum_01 = 0;
	long long sum_02 = 0;

	for (int i = 0; i <= 2019; i++) {
		sum_01 += sum2_01(i);
		sum_02 += sum2_02(i);
	}

	cout << sum_01 << endl;
	cout << sum_02 << endl;
}

long long sum2_01(int num)
{
	string numTo(to_string(num));
	if (numTo.find_first_of("2019") != string::npos) {
		return (long long)powl(num, 2);
	}

	return 0;
}

long long sum2_02(int num)
{
	if (num >= 1000) {
		if (num / 1000 == 2 || num / 1000 == 1 || num / 1000 == 9) {
			return (long long)powl(num, 2);
		}
	}
	if (num >= 100) {
		if (num / 100 % 10 == 2 || num / 100 % 10 == 0 || num / 100 % 10 == 1 || num / 100 % 10 == 9) {
			return (long long)powl(num, 2);
		}
	}
	if (num >= 10) {
		if (num / 10 % 10 == 2 || num / 10 % 10 == 0 || num / 10 % 10 == 1 || num / 10 % 10 == 9) {
			return (long long)powl(num, 2);
		}
	}
	if (num % 10 == 2 || num % 10 == 0 || num % 10 == 1 || num % 10 == 9) {
		return (long long)powl(num, 2);
	}
	return 0;
}