#include <iostream>

using namespace std;

enum letter {
	A, B, C, D
};

void show(letter c)
{
	cout << "ABCD"[c] << '\t';
}

int main(void)
{
	letter c1, c2, c3;
	int n = 0;
	for(c1 = A; c1 <= D; c1 = letter(int(c1) + 1))
		for(c2 = A; c2 <= D; c2 = letter(int(c2) + 1))
			for(c3 = A; c3 <= D; c3 = letter(int(c3) + 1)) {
				if(c1 != c2 && c1 != c3 && c2 != c3) {
					show(c1);
					show(c2);
					show(c3);
					cout << '\n';
					n++;
				}
			}
	cout << "共有 " << n << " 种取法!";

	return 0;
}