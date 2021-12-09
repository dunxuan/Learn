#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>

using namespace std;

int main(void)
{
	char s[100] = { 0 };
	for (int i = 0; (s[i] = getchar()) != '\n'; i++) {
	}
	int a[50] = { 0 };
	int j = 0;
	for (int i = 0; i <= strlen(s); i++) {
		if (isdigit(s[i])) {
			a[j] *= 10;
			a[j] += s[i] - 48;
		} else if (i > 0 && isdigit(s[i - 1])) {
			j++;
		}
	}
	for (int i = 0; i < j; i++) {
		cout << a[i] << endl;
	}
}