#include <iostream>

using namespace std;

int main(void)
{
	char present = 0;
	int alpha = 0;
	int space = 0;
	int number = 0;
	int other = 0;
	
	while ((present = getchar()) != '\n')	{
		if (present == ' ')	{
			space++;
		} else if (present >= '0' && present <= '9')	{
			number++;
		} else if (present >= 'a' && present <= 'z' ||		\
				   present >= 'A' && present <= 'Z')	{
			alpha++;
		} else	{
			other++;
		}
	}

	cout << "英文字母：";
	cout << alpha;
	cout << "个";
	cout << endl;
	cout << "空格：";
	cout << space;
	cout << "个";
	cout << endl;
	cout << "数字：";
	cout << number;
	cout << "个";
	cout << endl;
	cout << "其他字符：";
	cout << other;
	cout << "个";
	cout << endl;

	return 0;
}