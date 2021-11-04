#include <iostream>

#define STEPSNUMBER 600

using namespace std;

int getStepType(int steps);

int main(void)
{
	int numberOfType = 0;

	numberOfType = getStepType(STEPSNUMBER);

	cout << numberOfType;
}

int getStepType(int steps)
{
	if (steps <= 0)	return 0;
	if (steps == 1)	return 1;
	if (steps == 2)	return 2;
	if (steps == 3)	return 4;
	if (steps > 3)	
		return getStepType(steps - 1) + getStepType(steps - 2) + getStepType(steps - 3);
}