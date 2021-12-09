#include <iostream>

#define STUDENTS 1
#define ACHIEVEMENT 1

using namespace std;

int main(void)
{
	int stuAch[STUDENTS][ACHIEVEMENT] = {0};
	int stuAve[STUDENTS] = {0};
	int achAve[ACHIEVEMENT] = {0};
	int achMax[ACHIEVEMENT] = {0};
	//char stuNum[STUDENTS][13] = {0};

	for (int i = 0; i < STUDENTS; i++)	{
		//cout << "输入学生" << i + 1 << "的学号：";
		//cin >> *stuNum[i];
		for (int j = 0; j < ACHIEVEMENT; j++)	{
			cout << "输入学生" << i + 1 << "的课程" << j + 1 << "的成绩:"; 
			cin >> stuAch[i][j];
			stuAve[i] += stuAch[i][j];
			achAve[j] += stuAch[i][j];
			if (stuAch[i][j] > achMax[j])	{
				achMax[j] = stuAch[i][j];
			}
		}
		stuAve[i] /= ACHIEVEMENT;
	}
	
	cout << '\t';
	for (int j = 0; j < ACHIEVEMENT; j++)	{
		cout << "\t课程" << j + 1 ;
	}
	cout << "平均成绩" << endl;
	for (int i = 0; i < STUDENTS; i++)	{
		cout << "学生" << i + 1 << "\t\t";
		for (int j = 0; j < ACHIEVEMENT; j++)	{
			cout << stuAch[i][j] << '\t';
		}
		cout << stuAve[i];
		cout << endl;
	}
	cout << "平均成绩\t";
	for (int j = 0; j < ACHIEVEMENT; j++)	{
		cout << achAve[j] << '\t';
	}
	cout << endl;
	cout << "最高成绩\t";
	for (int j = 0; j < ACHIEVEMENT; j++)	{
		cout << achMax[j] << '\t';
	}

	return 0;
}