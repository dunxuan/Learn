#include <iostream>

using namespace std;

int main(void)
{
	float result = 0;

	//输入
	cout << "输入成绩：";
	cin >> result;
	while (result > 100 || result < 0)	{
		cout << "输入错误，请重新输入：";
		cin >> result;
	}

	//计算
	char grade = 0;
	switch ((int)result / 10)	{
		case 10: case 9:
			grade = 'A';
			break;
		case 8:
			grade = 'B';
			break;
		case 7:
			grade = 'C';
			break;
		case 6:
			grade = 'D';
			break;
		default:
			grade = 'E';
			break;
	}

	//输出
	cout << "等级";
	cout << grade;
	cout << endl;

	return 0;
}